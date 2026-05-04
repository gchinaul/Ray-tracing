/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:21:38 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "miniRT.h"

float	get_ray_component(t_ray *ray, int axis)
{
	if (axis == 0)
		return (ray->direction.x);
	else if (axis == 1)
		return (ray->direction.y);
	else
		return (ray->direction.z);
}

float	get_origin_component(t_ray *ray, int axis)
{
	if (axis == 0)
		return (ray->origin.x);
	else if (axis == 1)
		return (ray->origin.y);
	else
		return (ray->origin.z);
}

float	get_bbox_min(t_aabb bbox, int axis)
{
	if (axis == 0)
		return (bbox.min.x);
	else if (axis == 1)
		return (bbox.min.y);
	else
		return (bbox.min.z);
}

float	get_bbox_max(t_aabb bbox, int axis)
{
	if (axis == 0)
		return (bbox.max.x);
	else if (axis == 1)
		return (bbox.max.y);
	else
		return (bbox.max.z);
}
