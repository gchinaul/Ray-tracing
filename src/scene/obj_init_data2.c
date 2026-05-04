/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_init_data2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 08:39:41 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:06:12 by van              ###   ########.fr       */
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
	return (data);
}
