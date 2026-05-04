/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_intersection_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/04 13:42:08 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "cone_utils.h"
#include "intersections.h"
#include "math_for_phys_1.h"
#include <math.h>

static void	compute_cone_coeffs(t_ray *ray, t_cone *cone, float *coeffs)
{
	t_vec3	apex;
	t_vec3	co;
	float	k;
	float	cos2;

	apex = get_cone_apex(cone);
	co = substract(&ray->origin, &apex);
	k = cone->radius / cone->height;
	cos2 = 1.0f / (1.0f + k * k);
	coeffs[0] = dot(&ray->direction, &cone->orientation);
	coeffs[1] = dot(&co, &cone->orientation);
	coeffs[2] = coeffs[0] * coeffs[0] - cos2 * dot(&ray->direction,
			&ray->direction);
	coeffs[3] = 2.0f * (coeffs[0] * coeffs[1] - cos2 * dot(&ray->direction,
				&co));
	coeffs[4] = coeffs[1] * coeffs[1] - cos2 * dot(&co, &co);
}

bool	ray_cone_side_intersect_bonus(t_ray *ray, t_cone *cone, float *t_out)
{
	float	coeffs[5];
	float	t;

	compute_cone_coeffs(ray, cone, coeffs);
	if (!solve_quadratic(coeffs[2], coeffs[3], coeffs[4], &t))
		return (false);
	if (!is_point_on_cone_side(ray, cone, t))
		return (false);
	*t_out = t;
	return (true);
}
