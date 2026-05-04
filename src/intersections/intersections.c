/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:09:44 by van               #+#    #+#             */
/*   Updated: 2025/09/05 09:19:27 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	ray_sphere_intersect(t_ray *ray, t_sphere *sp, float *t)
{
	t_sp_intersect	v;

	v.oc = substract(&ray->origin, &sp->coo);
	v.b = dot(&ray->direction, &v.oc);
	v.radius = sp->diameter / 2;
	v.c = dot(&v.oc, &v.oc) - v.radius * v.radius;
	v.discriminant = v.b * v.b - v.c;
	if (v.discriminant < 0.0f)
		return (false);
	v.sqrt_disc = sqrtf(v.discriminant);
	v.t1 = -v.b - v.sqrt_disc;
	v.t2 = -v.b + v.sqrt_disc;
	if (v.t1 > 0.001f)
	{
		*t = v.t1;
		return (true);
	}
	else if (v.t2 > 0.001f)
	{
		*t = v.t2;
		return (true);
	}
	return (false);
}

bool	ray_plane_intersect(t_ray *ray, t_plane *plane, float *t)
{
	float	denom;
	t_vec3	p_to_o;
	float	num;
	float	t_hit;

	denom = dot(&ray->direction, &plane->orientation);
	if (fabs(denom) < 1e-6f)
		return (false);
	p_to_o = substract(&plane->coo, &ray->origin);
	num = dot(&p_to_o, &plane->orientation);
	t_hit = num / denom;
	if (t_hit < 0.001f)
		return (false);
	*t = t_hit;
	return (true);
}

bool	ray_cylinder_intersect(t_ray *ray, t_cylinder *cy, float *t_out)
{
	float	t1;
	float	t2;
	float	t_candidate;
	bool	found;

	if (!calc_t1_t2_cy(ray, cy, &t1, &t2))
		return (false);
	found = false;
	test_t_cy(ray, cy, &found, (float *[2]){&t1, &t_candidate});
	test_t_cy(ray, cy, &found, (float *[2]){&t2, &t_candidate});
	if (found)
	{
		*t_out = t_candidate;
		return (true);
	}
	return (false);
}

bool	calc_t1_t2_cy(t_ray *ray, t_cylinder *cy, float *t1, float *t2)
{
	float	radius;
	t_vec3	axes[3];
	float	dot_ab[3];
	float	discriminant;
	float	sqrt_discriminant;

	radius = cy->diameter / 2.0f;
	axes[0] = substract(&ray->origin, &cy->coo);
	axes[1] = vec_project_orthogonal(ray->direction, cy->orientation);
	axes[2] = vec_project_orthogonal(axes[0], cy->orientation);
	dot_ab[0] = dot(&axes[1], &axes[1]);
	dot_ab[1] = dot(&axes[1], &axes[2]);
	dot_ab[2] = dot(&axes[2], &axes[2]);
	discriminant = dot_ab[1] * dot_ab[1]
		- dot_ab[0] * (dot_ab[2] - radius * radius);
	if (discriminant < 0.0f)
		return (false);
	sqrt_discriminant = sqrtf(discriminant);
	*t1 = (-dot_ab[1] - sqrt_discriminant) / dot_ab[0];
	*t2 = (-dot_ab[1] + sqrt_discriminant) / dot_ab[0];
	return (true);
}

void	test_t_cy(t_ray *ray, t_cylinder *cy, bool *found, float **t_tcandidate)
{
	t_vec3	p;
	float	height;

	if (*t_tcandidate[0] >= 0.001f)
	{
		p.x = ray->origin.x + *t_tcandidate[0] * ray->direction.x;
		p.y = ray->origin.y + *t_tcandidate[0] * ray->direction.y;
		p.z = ray->origin.z + *t_tcandidate[0] * ray->direction.z;
		height = dot(&(t_vec3){p.x - cy->coo.x, p.y - cy->coo.y,
				p.z - cy->coo.z}, &cy->orientation);
		if (height >= 0.0f && height <= cy->height)
		{
			if (!*found || *t_tcandidate[0] < *t_tcandidate[1])
			{
				*t_tcandidate[1] = *t_tcandidate[0];
				*found = true;
			}
		}
	}
}
