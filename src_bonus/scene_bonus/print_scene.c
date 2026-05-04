/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:07:17 by van               #+#    #+#             */
/*   Updated: 2025/09/03 15:00:44 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_scn(t_scn *scn)
{
	printf("A:\n");
	print_a_data(scn->amb);
	printf("C:\n");
	print_c_data(scn->cam);
	print_lights(scn->lights);
	print_objects(&scn->objs);
	print_planes(scn->planes);
	printf("\n\n");
}

void	print_lights(t_light *lights)
{
	if (lights == NULL)
		return ;
	while (lights)
	{
		printf("L:\n");
		print_l_data(lights);
		lights = lights->next;
	}
}

void	print_planes(t_plane *planes)
{
	if (planes == NULL)
		return ;
	while (planes)
	{
		printf("pl:\n");
		print_pl_data(planes);
		planes = planes->next;
	}
}

void	print_cn_data(t_cone *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\torientation: %.2f,%.2f,%.2f\n",
		data->orientation.x, data->orientation.y, data->orientation.z);
	printf("\tradius: %.2f\n", data->radius);
	printf("\theight: %.2f\n", data->height);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
}
