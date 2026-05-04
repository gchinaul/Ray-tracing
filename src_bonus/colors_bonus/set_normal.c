/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:39:39 by van               #+#    #+#             */
/*   Updated: 2025/09/05 11:04:12 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_normal(t_ray *ray)
{
	if (ray->type == SP)
		set_normal_sp(&ray->normal, &ray->point, (t_sphere *)ray->hit);
	else if (ray->type == PL)
		ray->normal = ((t_plane *)ray->hit)->orientation;
	else if (ray->type == CY)
		set_normal_cy(&ray->normal, &ray->point,
			(t_cylinder *)ray->hit, ray->face);
	else if (ray->type == CN)
		set_normal_cn_bonus(&ray->normal, &ray->point,
			(t_cone *)ray->hit, ray->face);
}

void	set_normal_sp(t_vec3 *normal, t_vec3 *point, t_sphere *sp)
{
	*normal = substract(point, &sp->coo);
	normalize(normal);
}

void	set_normal_cy(t_vec3 *normal, t_vec3 *point, t_cylinder *cy, int face)
{
	t_vec3	v;
	float	proj;
	t_vec3	c;

	if (face == 3)
		*normal = cy->orientation;
	else if (face == 2)
		*normal = scalar_mult(&cy->orientation, -1.0f);
	else if (face == 1)
	{
		v = substract(point, &cy->coo);
		proj = dot(&v, &cy->orientation);
		c = scalar_mult(&cy->orientation, proj);
		c = add(&cy->coo, &c);
		*normal = substract(point, &c);
		normalize(normal);
	}
}
