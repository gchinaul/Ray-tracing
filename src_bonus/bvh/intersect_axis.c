/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_axis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:21:10 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "miniRT.h"

static void	update_bounds(float *tmin, float *tmax, float t1, float t2)
{
	*tmin = fmax(*tmin, fmin(t1, t2));
	*tmax = fmin(*tmax, fmax(t1, t2));
}

static void	calculate_intersection_times(t_aabb bbox, t_ray *ray,
		int axis, float *times)
{
	float	invd;
	float	origin;

	invd = 1.0f / get_ray_component(ray, axis);
	origin = get_origin_component(ray, axis);
	times[0] = (get_bbox_min(bbox, axis) - origin) * invd;
	times[1] = (get_bbox_max(bbox, axis) - origin) * invd;
}

bool	check_axis_intersection(t_aabb bbox, t_ray *ray,
		int axis, float *bounds)
{
	float	times[2];

	calculate_intersection_times(bbox, ray, axis, times);
	update_bounds(&bounds[0], &bounds[1], times[0], times[1]);
	if (bounds[1] <= bounds[0])
		return (false);
	return (true);
}
