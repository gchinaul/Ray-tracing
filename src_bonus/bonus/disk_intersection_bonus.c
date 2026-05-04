/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disk_intersection_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/01 13:42:08 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	point_inside_disk(t_vec3 point, t_vec3 center, float radius)
{
	t_vec3	v;
	float	dist2;

	v = substract(&point, &center);
	dist2 = dot(&v, &v);
	return (dist2 <= radius * radius);
}

bool	ray_disk_intersect_bonus(t_ray *ray, t_vec3 center,
	t_vec3 normal, float radius)
{
	float	denom;
	t_vec3	p_to_o;
	float	t;
	t_vec3	point;

	denom = dot(&ray->direction, &normal);
	if (fabs(denom) < 1e-6f)
		return (false);
	p_to_o = substract(&ray->origin, &center);
	t = dot(&p_to_o, &normal) / denom;
	if (t < 0.001f)
		return (false);
	point.x = ray->origin.x + t * ray->direction.x;
	point.y = ray->origin.y + t * ray->direction.y;
	point.z = ray->origin.z + t * ray->direction.z;
	return (point_inside_disk(point, center, radius));
}
