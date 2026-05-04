/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_side_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:26:53 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "miniRT.h"
#include "cone_utils.h"

bool	solve_quadratic(float a, float b, float c, float *t);
bool	check_cone_height(t_ray *ray, t_cone *cone, float t);

static void	calc_cone_quad_coeffs(t_ray *ray, t_cone *cone, t_cone_coeffs *cf)
{
	t_vec3	co;
	t_vec3	dir;
	float	cos2;
	float	dot_dir_axis;
	float	dot_co_axis;

	co = substract(&ray->origin, &cone->coo);
	dir = ray->direction;
	cos2 = cosf(cone->angle) * cosf(cone->angle);
	dot_dir_axis = dot(&dir, &cone->orientation);
	dot_co_axis = dot(&co, &cone->orientation);
	*(cf->a) = dot_dir_axis * dot_dir_axis - cos2;
	*(cf->b) = 2 * (dot_dir_axis * dot_co_axis - dot(&dir, &co) * cos2);
	*(cf->c) = dot_co_axis * dot_co_axis - dot(&co, &co) * cos2;
}

bool	ray_cone_side_intersect(t_ray *ray, t_cone *cone, float *t_out)
{
	float			a;
	float			b;
	float			c;
	float			t;
	t_cone_coeffs	coeffs;

	coeffs = (t_cone_coeffs){&a, &b, &c};
	calc_cone_quad_coeffs(ray, cone, &coeffs);
	if (!solve_quadratic(a, b, c, &t))
		return (false);
	if (!check_cone_height(ray, cone, t))
		return (false);
	*t_out = t;
	return (true);
}
