/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init_data_co.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:32:34 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "miniRT.h"
#include "scene.h"

static void	init_cone_defaults(t_cone *co)
{
	co->ka = 0.1f;
	co->kd = 0.7f;
	co->ks = 0.3f;
	co->pe = 24;
	co->kr = 0.0f;
	co->bmap_name = NULL;
	co->bmap = NULL;
	co->scale = 1.0f;
	co->intensity = 1.0f;
}

static void	init_cone_basic_data(t_cone *co, t_scn_el_lst *el, t_vec3 *rgb)
{
	write(1, "Converting coo\n", 14);
	co->coo = _3f_str_to_vec3(el->data[1]);
	write(1, "Converting orientation\n", 22);
	co->orientation = _3f_str_to_vec3(el->data[2]);
	write(1, "Converting radius\n", 17);
	co->radius = ft_atof(el->data[3]) / 2.0f;
	write(1, "Converting height\n", 17);
	co->height = ft_atof(el->data[4]);
	write(1, "Converting color: ", 17);
	write(1, el->data[5], ft_strlen(el->data[5]));
	write(1, "\n", 1);
	co->color = rgb_str_to_int(el->data[5], rgb);
}

static int	init_cone_optional_params(t_cone *co, t_scn_el_lst *el, int len)
{
	if (len == 6 + 5 || len == 6 + 5 + 3)
	{
		co->ka = float_str_to_float(el->data[6]);
		co->kd = float_str_to_float(el->data[7]);
		co->ks = float_str_to_float(el->data[8]);
		co->pe = ft_atoi(el->data[9]);
		co->kr = float_str_to_float(el->data[10]);
		if (len == 6 + 5 + 3)
		{
			co->bmap_name = ft_strdup(el->data[11]);
			if (!co->bmap_name)
				return (1);
			co->scale = float_str_to_float(el->data[12]);
			co->intensity = float_str_to_float(el->data[13]);
		}
	}
	return (0);
}

static t_cone	*finalize_cone_init(t_cone *co, t_scn_el_lst *el)
{
	int	len;

	len = arr_len((void *)el->data);
	if (init_cone_optional_params(co, el, len))
	{
		free(co);
		return (err_null("Error: strdup init_co_data\n"));
	}
	co->angle = atan2f(co->radius, co->height);
	co->bbox = compute_cone_aabb_bonus(co);
	return (co);
}

t_cone	*init_co_data(t_scn_el_lst *el)
{
	t_cone	*co;
	t_vec3	rgb;

	write(1, "Allocating cone\n", 16);
	co = malloc(sizeof(t_cone));
	if (!co)
	{
		write(1, "Malloc failed\n", 13);
		return (NULL);
	}
	co->next = NULL;
	co->prev = NULL;
	init_cone_basic_data(co, el, &rgb);
	if (co->color == 1)
	{
		write(1, "RGB conversion failed\n", 20);
		free(co);
		return (NULL);
	}
	co->rgb = rgb;
	normalize(&co->orientation);
	init_cone_defaults(co);
	return (finalize_cone_init(co, el));
}
