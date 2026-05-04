/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartesian_conv2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:37:37 by van               #+#    #+#             */
/*   Updated: 2025/09/12 15:37:49 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cy_uv_side(t_ray *ray, float *u, float *v)
{
	t_vec3	xyz;
	float	theta;

	xyz.x = ray->point.x - ((t_cylinder *)ray->hit)->coo.x;
	xyz.y = ray->point.y - ((t_cylinder *)ray->hit)->coo.y;
	xyz.z = ray->point.z - ((t_cylinder *)ray->hit)->coo.z;
	*v = dot(&xyz, &((t_cylinder *)ray->hit)->orientation)
		/ ((t_cylinder *)ray->hit)->height;
	theta = atan2(dot(&xyz, &((t_cylinder *)ray->hit)->v_axis),
			dot(&xyz, &((t_cylinder *)ray->hit)->u_axis));
	*u = theta / (2 * M_PI);
	if (*u < 0)
		*u += 1;
	*u *= ray->scale;
	*v *= ray->scale;
}

void	cy_uv_base(t_ray *ray, float *u, float *v, t_bump_map *bump_map)
{
	t_vec3	op;
	float	scale;
	float	hw_ratio;

	op = substract(&ray->point, &((t_cylinder *)ray->hit)->coo);
	*u = dot(&op, &((t_cylinder *)ray->hit)->u_axis) / bump_map->columns;
	*v = dot(&op, &((t_cylinder *)ray->hit)->v_axis) / bump_map->rows;
	hw_ratio = ((t_cylinder *)ray->hit)->height
		/ ((t_cylinder *)ray->hit)->diameter;
	scale = ray->scale * hw_ratio * 400
		/ ((t_cylinder *)ray->hit)->diameter / hw_ratio;
	*u *= scale;
	*v *= scale;
}

void	cartesian_to_cylinder(t_ray *ray, float *u, float *v)
{
	t_vec3	u_axis;
	t_vec3	v_axis;

	generate_orthonormal_basis(((t_cylinder *)ray->hit)->orientation,
		&u_axis, &v_axis);
	((t_cylinder *)ray->hit)->u_axis = u_axis;
	((t_cylinder *)ray->hit)->v_axis = v_axis;
	if (ray->face != CYLINDER_SIDE)
		cy_uv_base(ray, u, v, ((t_cylinder *)ray->hit)->bmap);
	else
		cy_uv_side(ray, u, v);
	wrap_uv(u, v);
}
