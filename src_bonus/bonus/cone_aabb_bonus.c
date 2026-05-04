/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_aabb_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/07 13:42:08 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "math_for_phys_1.h"
#include "math_for_phys_2.h"
#include <float.h>

static void	update_aabb_with_point(t_aabb *aabb, t_vec3 *point)
{
	aabb->min.x = fmin(aabb->min.x, point->x);
	aabb->min.y = fmin(aabb->min.y, point->y);
	aabb->min.z = fmin(aabb->min.z, point->z);
	aabb->max.x = fmax(aabb->max.x, point->x);
	aabb->max.y = fmax(aabb->max.y, point->y);
	aabb->max.z = fmax(aabb->max.z, point->z);
}

static void	get_cone_basis(t_cone *cone, t_vec3 *right, t_vec3 *up)
{
	t_vec3	temp;

	if (fabs(cone->orientation.y) < 0.99)
	{
		set_vec3(&temp, 0, 1, 0);
		*right = cross(&temp, &cone->orientation);
	}
	else
	{
		set_vec3(&temp, 1, 0, 0);
		*right = cross(&temp, &cone->orientation);
	}
	normalize(right);
	*up = cross(&cone->orientation, right);
	normalize(up);
}

static t_vec3	compute_circle_point(t_cone *cone, t_vec3 right,
	t_vec3 up, int i)
{
	float	angle;
	float	cos_angle;
	float	sin_angle;
	t_vec3	point;

	angle = i * M_PI / 4;
	cos_angle = cos(angle);
	sin_angle = sin(angle);
	point = cone->coo;
	point.x += cone->radius * (cos_angle * right.x + sin_angle * up.x);
	point.y += cone->radius * (cos_angle * right.y + sin_angle * up.y);
	point.z += cone->radius * (cos_angle * right.z + sin_angle * up.z);
	return (point);
}

static void	add_circle_points(t_aabb *aabb, t_cone *cone)
{
	t_vec3	right;
	t_vec3	up;
	t_vec3	point;
	int		i;

	get_cone_basis(cone, &right, &up);
	i = 0;
	while (i < 8)
	{
		point = compute_circle_point(cone, right, up, i);
		update_aabb_with_point(aabb, &point);
		i++;
	}
}

t_aabb	compute_cone_aabb_bonus(t_cone *cone)
{
	t_aabb	aabb;
	t_vec3	apex;

	apex.x = cone->coo.x + cone->orientation.x * cone->height;
	apex.y = cone->coo.y + cone->orientation.y * cone->height;
	apex.z = cone->coo.z + cone->orientation.z * cone->height;
	aabb.min = apex;
	aabb.max = apex;
	update_aabb_with_point(&aabb, &cone->coo);
	add_circle_points(&aabb, cone);
	return (aabb);
}
