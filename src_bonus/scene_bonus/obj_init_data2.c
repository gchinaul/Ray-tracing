/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init_data2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:39:41 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:34:53 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cylinder	*init_cy_data(t_scn_el_lst *el)
{
	t_cylinder	*data;

	data = malloc(sizeof(t_cylinder));
	if (data == NULL)
		return (err_malloc_null());
	data->coo = _3f_str_to_vec3(el->data[1]);
	data->orientation = _3f_str_to_vec3(el->data[2]);
	normalize(&data->orientation);
	data->diameter = float_str_to_float(el->data[3]);
	data->height = float_str_to_float(el->data[4]);
	data->color = rgb_str_to_int(el->data[5], &data->rgb);
	set_cy_lighting_attr(el, data, 6);
	data->bmap_name = NULL;
	data->bmap = NULL;
	if (arr_len((void *)el->data) == 6 + 5 + 3)
	{
		data->bmap_name = ft_strdup(el->data[11]);
		if (data->bmap_name == NULL)
			return (err_null("Error: strdup init_sp_data\n"));
		data->scale = float_str_to_float(el->data[12]);
		data->intensity = float_str_to_float(el->data[13]);
	}
	return (data);
}

void	set_sp_lighting_attr(t_scn_el_lst *el, t_sphere *data, int start)
{
	data->ka = float_str_to_float(el->data[start++]);
	data->kd = float_str_to_float(el->data[start++]);
	data->ks = float_str_to_float(el->data[start++]);
	data->pe = ft_atoi(el->data[start++]);
	data->kr = float_str_to_float(el->data[start++]);
}

void	set_cy_lighting_attr(t_scn_el_lst *el, t_cylinder *data, int start)
{
	data->ka = float_str_to_float(el->data[start++]);
	data->kd = float_str_to_float(el->data[start++]);
	data->ks = float_str_to_float(el->data[start++]);
	data->pe = ft_atoi(el->data[start++]);
	data->kr = float_str_to_float(el->data[start++]);
}

void	set_pl_lighting_attr(t_scn_el_lst *el, t_plane *data, int start)
{
	data->ka = float_str_to_float(el->data[start++]);
	data->kd = float_str_to_float(el->data[start++]);
	data->ks = float_str_to_float(el->data[start++]);
	data->pe = ft_atoi(el->data[start++]);
	data->kr = float_str_to_float(el->data[start++]);
}
