/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_to_cone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:57 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "miniRT.h"

static void	calculate_relative_coords(t_ray *ray, t_vec3 *relative)
{
	t_cone	*cone;

	cone = (t_cone *)ray->hit;
	relative->x = ray->point.x - cone->coo.x;
	relative->y = ray->point.y - cone->coo.y;
	relative->z = ray->point.z - cone->coo.z;
}

static void	apply_scale_and_wrap(t_ray *ray, float *u, float *v)
{
	*u *= ray->scale;
	*v *= ray->scale;
	*u = fmodf(*u, 1.0f);
	*v = fmodf(*v, 1.0f);
	if (*u < 0)
		*u += 1.0f;
	if (*v < 0)
		*v += 1.0f;
}

void	cartesian_to_cone(t_ray *ray, float *u, float *v)
{
	t_vec3	u_vec;
	t_vec3	v_vec;
	t_vec3	relative;
	float	theta;

	calculate_relative_coords(ray, &relative);
	generate_orthonormal_basis(((t_cone *)ray->hit)->orientation,
		&u_vec, &v_vec);
	*v = dot(&relative, &((t_cone *)ray->hit)->orientation)
		/ ((t_cone *)ray->hit)->height;
	theta = atan2f(dot(&relative, &v_vec), dot(&relative, &u_vec));
	*u = theta / (2 * M_PI);
	if (*u < 0)
		*u += 1;
	apply_scale_and_wrap(ray, u, v);
}
