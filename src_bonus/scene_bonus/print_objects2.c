/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 07:49:30 by van               #+#    #+#             */
/*   Updated: 2025/09/05 08:44:41 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_l_data(t_light *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\tbrightness ratio: %.2f\n", data->brightness_ratio);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
}

void	print_sp_data(t_sphere *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\tdiameter: %.2f\n", data->diameter);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
	printf("\tka: %.1f, kd: %.1f, ks: %.1f, pe: %d, kr: %.1f\n",
		data->ka, data->kd, data->ks, data->pe, data->kr);
	if (data->bmap_name)
		printf("\ttexture: %s, scale: %.2f, intensity: %.2f\n",
			data->bmap_name, data->scale, data->intensity);
}

void	print_pl_data(t_plane *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\torientation: %.2f,%.2f,%.2f\n",
		data->orientation.x, data->orientation.y, data->orientation.z);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
	printf("\tka: %.1f, kd: %.1f, ks: %.1f, pe: %d, kr: %.1f\n",
		data->ka, data->kd, data->ks, data->pe, data->kr);
	if (data->bmap_name)
		printf("\ttexture: %s, scale: %.2f, intensity: %.2f\n",
			data->bmap_name, data->scale, data->intensity);
}

void	print_cy_data(t_cylinder *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\torientation: %.2f,%.2f,%.2f\n",
		data->orientation.x, data->orientation.y, data->orientation.z);
	printf("\tdiameter: %.2f\n", data->diameter);
	printf("\theight: %.2f\n", data->height);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
	printf("\tka: %.1f, kd: %.1f, ks: %.1f, pe: %d, kr: %.1f\n",
		data->ka, data->kd, data->ks, data->pe, data->kr);
	if (data->bmap_name)
		printf("\ttexture: %s, scale: %.2f, intensity: %.2f\n",
			data->bmap_name, data->scale, data->intensity);
}

void	print_co_data(t_cone *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\torientation: %.2f,%.2f,%.2f\n",
		data->orientation.x, data->orientation.y, data->orientation.z);
	printf("\tradius: %.2f\n", data->radius);
	printf("\theight: %.2f\n", data->height);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
	printf("\tka: %.1f, kd: %.1f, ks: %.1f, pe: %d, kr: %.1f\n",
		data->ka, data->kd, data->ks, data->pe, data->kr);
	if (data->bmap_name)
		printf("\ttexture: %s, scale: %.2f, intensity: %.2f\n",
			data->bmap_name, data->scale, data->intensity);
}
