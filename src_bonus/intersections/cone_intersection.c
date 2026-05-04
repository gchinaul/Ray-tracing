/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 10:06:47 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "cone_utils.h"
#include "miniRT.h"

bool		solve_quadratic(float a, float b, float c, float *t);
bool		check_cone_height(t_ray *ray, t_cone *cone, float t);
bool		ray_cone_side_intersect(t_ray *ray, t_cone *cone, float *t_out);

bool	ray_cone_intersect(t_ray *ray, t_cone *cone, float *t_out)
{
	float	t_side;

	if (ray_cone_side_intersect(ray, cone, &t_side))
	{
		*t_out = t_side;
		return (true);
	}
	return (false);
}

t_cone_hit	ray_cone_full_intersect(t_ray *ray, t_cone *cone, float *t_out)
{
	float	t_side;

	if (ray_cone_side_intersect(ray, cone, &t_side))
	{
		*t_out = t_side;
		return (CONE_SIDE);
	}
	return (CONE_NONE);
}

void	set_normal_cn(t_vec3 *normal, t_vec3 *point, t_cone *cone, int face)
{
	t_vec3	p;
	t_vec3	v;
	float	y;
	t_vec3	scaled_orient;

	(void)face;
	p = substract(point, &cone->coo);
	y = dot(&p, &cone->orientation);
	scaled_orient = scalar_mult(&cone->orientation, y);
	v = substract(&p, &scaled_orient);
	normalize(&v);
	*normal = v;
}
