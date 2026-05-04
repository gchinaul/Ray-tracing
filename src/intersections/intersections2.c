/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:16:29 by van               #+#    #+#             */
/*   Updated: 2025/09/05 09:31:09 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	vec_project_orthogonal(t_vec3 v, t_vec3 axis)
{
	float	dot_va;
	t_vec3	res;

	dot_va = dot(&v, &axis);
	res.x = v.x - dot_va * axis.x;
	res.y = v.y - dot_va * axis.y;
	res.z = v.z - dot_va * axis.z;
	return (res);
}

bool	ray_disk_intersect(t_ray *ray, t_vec3 *center_normal, float radius,
			float *t_out)
{
	float	denom;
	float	num;
	float	t;
	float	dist2;
	t_vec3	p_to_o__p__v[3];

	denom = dot(&ray->direction, &center_normal[1]);
	if (fabs(denom) < 1e-6f)
		return (false);
	p_to_o__p__v[0] = substract(&center_normal[0], &ray->origin);
	num = dot(&p_to_o__p__v[0], &center_normal[1]);
	t = num / denom;
	if (t < 0.001f)
		return (false);
	p_to_o__p__v[1].x = ray->origin.x + t * ray->direction.x;
	p_to_o__p__v[1].y = ray->origin.y + t * ray->direction.y;
	p_to_o__p__v[1].z = ray->origin.z + t * ray->direction.z;
	p_to_o__p__v[2] = substract(&p_to_o__p__v[1], &center_normal[0]);
	dist2 = dot(&p_to_o__p__v[2], &p_to_o__p__v[2]);
	if (dist2 > radius * radius)
		return (false);
	*t_out = t;
	return (true);
}

t_cyl_hit	ray_cylinder_full_intersect(t_ray *ray, t_cylinder *cyl,
				float *t_out)
{
	float		t_side;
	float		t_best;
	t_cyl_hit	hit_type;

	t_best = -1.0f;
	hit_type = CYLINDER_NONE;
	if (ray_cylinder_intersect(ray, cyl, &t_side))
	{
		t_best = t_side;
		hit_type = CYLINDER_SIDE;
	}
	bases_cy_full(ray, cyl, &t_best, &hit_type);
	if (hit_type != CYLINDER_NONE)
	{
		*t_out = t_best;
		return (hit_type);
	}
	return (CYLINDER_NONE);
}

void	bases_cy_full(t_ray *ray, t_cylinder *cy, float *t_best,
			t_cyl_hit *hit_type)
{
	float	t_base;
	t_vec3	top_center;

	if (ray_disk_intersect(ray, (t_vec3 [2]){cy->coo, cy->orientation},
		cy->diameter / 2.0f, &t_base))
	{
		if (*t_best < 0.0f || t_base < *t_best)
		{
			*t_best = t_base;
			*hit_type = CYLINDER_BASE_BOTTOM;
		}
	}
	top_center.x = cy->coo.x + cy->orientation.x * cy->height;
	top_center.y = cy->coo.y + cy->orientation.y * cy->height;
	top_center.z = cy->coo.z + cy->orientation.z * cy->height;
	if (ray_disk_intersect(ray, (t_vec3 [2]){top_center, cy->orientation},
		cy->diameter / 2.0f, &t_base))
	{
		if (*t_best < 0.0f || t_base < *t_best)
		{
			*t_best = t_base;
			*hit_type = CYLINDER_BASE_TOP;
		}
	}
}
