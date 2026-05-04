/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aabb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:49:25 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:12:59 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// return the axis as an int (x = 0, y = 1, z = 2) 
int	longest_axis(t_aabb *bbox)
{
	float	dx;
	float	dy;
	float	dz;
	int		axis;

	dx = bbox->max.x - bbox->min.x;
	dy = bbox->max.y - bbox->min.y;
	dz = bbox->max.z - bbox->min.z;
	if (dx > dy && dx > dz)
		axis = 0;
	else if (dy > dz)
		axis = 1;
	else
		axis = 2;
	return (axis);
}

// returns the distance to an AABB, -1.0f if not intersected
float	aabb_intersect(t_aabb *bbox, t_ray *ray)
{
	t_vec3	t0;
	t_vec3	t1;
	float	t_min;
	float	t_max;

	if (bbox == NULL || ray == NULL)
		return (-1.0f);
	calc_t0_t1_aabb_intersect(ray, bbox, &t0, &t1);
	calc_t_min_t_max_aabb_intersect(&t0, &t1, &t_min, &t_max);
	if (t_min > t_max)
		return (-1.0f);
	if (t_max < 0.0f)
		return (-1.0f);
	if (t_min < 0.0f)
		return (t_max);
	return (t_min);
}

// calc the distances to each surface of the AABB
void	calc_t0_t1_aabb_intersect(t_ray *ray, t_aabb *bbox, t_vec3 *t0,
			t_vec3 *t1)
{
	t_vec3	inv_dir;

	inv_dir.x = 1.0f / ray->direction.x;
	inv_dir.y = 1.0f / ray->direction.y;
	inv_dir.z = 1.0f / ray->direction.z;
	t0->x = (bbox->min.x - ray->origin.x) * inv_dir.x;
	t1->x = (bbox->max.x - ray->origin.x) * inv_dir.x;
	t0->y = (bbox->min.y - ray->origin.y) * inv_dir.y;
	t1->y = (bbox->max.y - ray->origin.y) * inv_dir.y;
	t0->z = (bbox->min.z - ray->origin.z) * inv_dir.z;
	t1->z = (bbox->max.z - ray->origin.z) * inv_dir.z;
}

// calc the distances to the points where the ray get in and out the AABB
void	calc_t_min_t_max_aabb_intersect(t_vec3 *t0, t_vec3 *t1, float *t_min,
			float *t_max)
{
	t_vec3	tmin;
	t_vec3	tmax;

	tmin.x = fminf(t0->x, t1->x);
	tmax.x = fmaxf(t0->x, t1->x);
	tmin.y = fminf(t0->y, t1->y);
	tmax.y = fmaxf(t0->y, t1->y);
	tmin.z = fminf(t0->z, t1->z);
	tmax.z = fmaxf(t0->z, t1->z);
	*t_min = fmaxf(fmaxf(tmin.x, tmin.y), tmin.z);
	*t_max = fminf(fminf(tmax.x, tmax.y), tmax.z);
}

int	aabb_overlap(t_aabb *a, t_aabb *b)
{
	if (a->max.x < b->min.x || a->min.x > b->max.x)
		return (0);
	if (a->max.y < b->min.y || a->min.y > b->max.y)
		return (0);
	if (a->max.z < b->min.z || a->min.z > b->max.z)
		return (0);
	return (1);
}
