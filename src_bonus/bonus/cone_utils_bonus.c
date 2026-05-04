/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 10:07:12 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/08 21:28:39 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "intersections.h"
#include "math_for_phys_1.h"
#include <math.h>
#include <stdbool.h>

t_vec3	get_cone_apex(t_cone *cone)
{
	t_vec3	apex;

	apex.x = cone->coo.x + cone->orientation.x * cone->height;
	apex.y = cone->coo.y + cone->orientation.y * cone->height;
	apex.z = cone->coo.z + cone->orientation.z * cone->height;
	return (apex);
}

bool	is_point_on_cone_side(t_ray *ray, t_cone *cone, float t)
{
	t_vec3	point;
	t_vec3	v;
	float	height;

	point.x = ray->origin.x + t * ray->direction.x;
	point.y = ray->origin.y + t * ray->direction.y;
	point.z = ray->origin.z + t * ray->direction.z;
	v = substract(&point, &cone->coo);
	height = dot(&v, &cone->orientation);
	return (height >= 0 && height <= cone->height);
}

void	set_normal_cn_bonus(t_vec3 *normal, t_vec3 *point, t_cone *cone,
		int face)
{
	t_vec3	p;
	t_vec3	v;
	float	y;
	t_vec3	scaled_orient;

	if (face == CONE_BASE)
	{
		*normal = cone->orientation;
		return ;
	}
	p = substract(point, &cone->coo);
	y = dot(&p, &cone->orientation);
	scaled_orient = scalar_mult(&cone->orientation, y);
	v = substract(&p, &scaled_orient);
	normalize(&v);
	*normal = v;
}
