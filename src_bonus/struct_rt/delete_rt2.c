/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:07:12 by van               #+#    #+#             */
/*   Updated: 2025/09/09 09:40:23 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_planes(t_plane *planes)
{
	t_plane	*tmp;

	while (planes)
	{
		tmp = planes->next;
		free_plane(planes);
		planes = tmp;
	}
}

void	free_plane(t_plane *plane)
{
	if (plane == NULL)
		return ;
	free(plane->bmap_name);
	free(plane);
}

void	free_cones(t_cone *cones)
{
	if (cones == NULL)
		return ;
	while (cones->next)
	{
		cones = cones->next;
		free_cone(cones->prev);
	}
	free_cone(cones);
}

void	free_cone(t_cone *cone)
{
	if (cone == NULL)
		return ;
	free(cone->bmap_name);
	free(cone);
}
