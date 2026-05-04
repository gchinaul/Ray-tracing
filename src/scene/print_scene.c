/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 14:07:17 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:07:06 by van              ###   ########.fr       */
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
