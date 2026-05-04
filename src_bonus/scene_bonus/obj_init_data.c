/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:26:29 by van               #+#    #+#             */
/*   Updated: 2025/09/09 09:14:52 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_amb_light	*init_a_data(t_scn_el_lst *el)
{
	t_amb_light	*data;

	data = malloc(sizeof(t_amb_light));
	if (data == NULL)
		return (err_malloc_null());
	data->light_ratio = float_str_to_float(el->data[1]);
	data->color = rgb_str_to_int(el->data[2], &data->rgb);
	return (data);
}

t_camera	*init_c_data(t_scn_el_lst *el)
{
	t_camera	*data;

	data = malloc(sizeof(t_camera));
	if (data == NULL)
		return (err_malloc_null());
	data->coo = _3f_str_to_vec3(el->data[1]);
	data->orientation = _3f_str_to_vec3(el->data[2]);
	normalize(&data->orientation);
	data->fov_h = ft_atoi(el->data[3]);
	data->focal_length = 1;
	return (data);
}

t_light	*init_l_data(t_scn_el_lst *el)
{
	t_light	*data;

	data = malloc(sizeof(t_light));
	if (data == NULL)
		return (err_malloc_null());
	data->coo = _3f_str_to_vec3(el->data[1]);
	data->brightness_ratio = float_str_to_float(el->data[2]);
	data->color = rgb_str_to_int(el->data[3], &data->rgb);
	data->prev = NULL;
	data->next = NULL;
	return (data);
}

t_sphere	*init_sp_data(t_scn_el_lst *el)
{
	t_sphere	*data;

	data = malloc(sizeof(t_sphere));
	if (data == NULL)
		return (err_malloc_null());
	data->coo = _3f_str_to_vec3(el->data[1]);
	data->diameter = float_str_to_float(el->data[2]);
	data->color = rgb_str_to_int(el->data[3], &data->rgb);
	set_sp_lighting_attr(el, data, 4);
	data->bmap_name = NULL;
	data->bmap = NULL;
	if (arr_len((void *)el->data) == 4 + 5 + 3)
	{
		data->bmap_name = ft_strdup(el->data[9]);
		if (data->bmap_name == NULL)
		{
			return (err_null("Error: strdup init_sp_data\n"));
		}
		data->scale = float_str_to_float(el->data[10]);
		data->intensity = float_str_to_float(el->data[11]);
	}
	return (data);
}

t_plane	*init_pl_data(t_scn_el_lst *el)
{
	t_plane	*data;

	data = malloc(sizeof(t_plane));
	if (data == NULL)
		return (err_malloc_null());
	data->coo = _3f_str_to_vec3(el->data[1]);
	data->orientation = _3f_str_to_vec3(el->data[2]);
	normalize(&data->orientation);
	data->color = rgb_str_to_int(el->data[3], &data->rgb);
	set_pl_lighting_attr(el, data, 4);
	data->next = NULL;
	data->prev = NULL;
	data->bmap_name = NULL;
	data->bmap = NULL;
	if (arr_len((void *)el->data) == 4 + 5 + 3)
	{
		data->bmap_name = ft_strdup(el->data[9]);
		if (data->bmap_name == NULL)
		{
			return (err_null("Error: strdup init_sp_data\n"));
		}
		data->scale = float_str_to_float(el->data[10]);
		data->intensity = float_str_to_float(el->data[11]);
	}
	return (data);
}
