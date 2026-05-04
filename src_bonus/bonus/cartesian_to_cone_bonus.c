/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_to_cone_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/08 21:28:40 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_utils.h"
#include "bump_map.h"
#include "cone_bonus.h"
#include "miniRT.h"

static void	calc_cone_coords(t_vec3 *rel_point, t_cone *cone, float *v_coord)
{
	*v_coord = dot(rel_point, &cone->orientation) / cone->height;
}

static void	calc_cone_angle(t_vec3 *rel_point, t_vec3 *u_vec, t_vec3 *v_vec,
		float *u_coord)
{
	float	x_prim;
	float	y_prim;
	float	theta;

	x_prim = dot(rel_point, u_vec);
	y_prim = dot(rel_point, v_vec);
	theta = atan2f(y_prim, x_prim);
	*u_coord = theta / (2 * M_PI);
	if (*u_coord < 0)
		*u_coord += 1;
}

static void	apply_scale_wrap(float *u, float *v, float scale)
{
	*u *= scale;
	*v *= scale;
	*u = fmodf(*u, 1.0f);
	*v = fmodf(*v, 1.0f);
	if (*u < 0)
		*u += 1;
	if (*v < 0)
		*v += 1;
}

void	cartesian_to_cone_bonus(t_ray *ray, float *u, float *v, t_vec3 *point)
{
	t_vec3			u_vec;
	t_vec3			v_vec;
	t_vec3			rel_point;
	t_cone			*cone;
	t_cone_params	params;

	params.u = u;
	params.v = v;
	params.point = point;
	cone = (t_cone *)ray->hit;
	rel_point.x = point->x - cone->coo.x;
	rel_point.y = point->y - cone->coo.y;
	rel_point.z = point->z - cone->coo.z;
	generate_orthonormal_basis(cone->orientation, &u_vec, &v_vec);
	calc_cone_coords(&rel_point, cone, params.v);
	calc_cone_angle(&rel_point, &u_vec, &v_vec, params.u);
	apply_scale_wrap(params.u, params.v, ray->scale);
}
