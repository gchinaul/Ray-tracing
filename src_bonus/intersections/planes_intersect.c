/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planes_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:01:55 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "cone_bonus.h"

int	planes_intersect(t_ray *ray, t_plane *planes, float *t, void *self)
{
	t_vec3	sub;
	float	denom;
	float	tolerance;
	float	t_tmp;

	while (planes)
	{
		if ((void *)planes == self)
		{
			planes = planes->next;
			continue ;
		}
		sub = substract(&planes->coo, &ray->origin);
		denom = dot(&planes->orientation, &ray->direction);
		tolerance = fmaxf(1e-6f, fabs(denom) * 1e-4f);
		if (fabs(denom) > tolerance)
		{
			t_tmp = dot(&sub, &planes->orientation) / denom;
			if (t_tmp > 0 && t_tmp < *t)
				set_ray_hit_plane(ray, t, t_tmp, planes);
		}
		planes = planes->next;
	}
	return (0);
}

void	set_ray_hit_plane(t_ray *ray, float *t, float t_tmp, t_plane *plane)
{
	*t = t_tmp;
	ray->hit = plane;
	ray->type = PL;
	ray->face = 1;
}

int	cones_intersect(t_ray *ray, t_cone *cones, float *t, void *self)
{
	float	t_tmp;

	while (cones)
	{
		if ((void *)cones == self)
		{
			cones = cones->next;
			continue ;
		}
		if (ray_cone_intersect_bonus(ray, cones, &t_tmp))
		{
			if (t_tmp > 1e-6f && t_tmp < *t)
			{
				*t = t_tmp;
				ray->hit = cones;
				ray->type = CN;
				ray->face = 1;
			}
		}
		cones = cones->next;
	}
	return (0);
}
