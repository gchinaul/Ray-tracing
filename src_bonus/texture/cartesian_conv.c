/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:03:24 by van               #+#    #+#             */
/*   Updated: 2025/09/12 15:37:21 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cartesian_to_spherical(t_ray *ray, float *u, float *v)
{
	float	xyz[3];
	float	phi;
	float	theta;
	float	r;

	r = ((t_sphere *)ray->hit)->diameter / 2.0f;
	xyz[0] = ray->point.x - ((t_sphere *)ray->hit)->coo.x;
	xyz[1] = ray->point.y - ((t_sphere *)ray->hit)->coo.y;
	xyz[2] = ray->point.z - ((t_sphere *)ray->hit)->coo.z;
	phi = atan2f(xyz[1], xyz[0]);
	if (phi < 0)
		phi += 2 * M_PI;
	theta = acosf(xyz[2] / r);
	*u = phi / (2 * M_PI);
	*v = theta / M_PI;
	*u *= ray->scale;
	*v *= ray->scale;
	wrap_uv(u, v);
}

void	cartesian_to_plane(t_ray *ray, float *u, float *v, t_bump_map *bump_map)
{
	t_vec3	op;

	op = substract(&ray->point, &((t_plane *)ray->hit)->coo);
	*u = dot(&op, &((t_plane *)ray->hit)->u_axis) / bump_map->columns;
	*v = dot(&op, &((t_plane *)ray->hit)->v_axis) / bump_map->rows;
	*u *= ray->scale;
	*v *= ray->scale;
	wrap_uv(u, v);
}

void	generate_orthonormal_basis(t_vec3 A, t_vec3 *U, t_vec3 *V)
{
	if (fabs(A.x) > fabs(A.y))
		*U = (t_vec3){0, 1, 0};
	else
		*U = (t_vec3){1, 0, 0};
	*U = cross(&A, U);
	normalize(U);
	*V = cross(&A, U);
	normalize(V);
}

void	wrap_uv(float *u, float *v)
{
	*u = fmodf(*u, 1.0f);
	*v = fmodf(*v, 1.0f);
	if (*u < 0)
		*u += 1.0f;
	if (*v < 0)
		*v += 1.0f;
}
