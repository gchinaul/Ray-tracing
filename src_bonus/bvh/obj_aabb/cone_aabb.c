/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_aabb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:12:15 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:18:41 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "miniRT.h"

static t_vec3	compute_apex(t_cone *co)
{
	t_vec3	apex;

	apex.x = co->coo.x + co->orientation.x * co->height;
	apex.y = co->coo.y + co->orientation.y * co->height;
	apex.z = co->coo.z + co->orientation.z * co->height;
	return (apex);
}

t_aabb	compute_cone_aabb(t_cone *co)
{
	t_aabb	bbox;
	t_vec3	base;
	t_vec3	apex;
	float	r;

	base = co->coo;
	r = co->radius;
	apex = compute_apex(co);
	bbox.min.x = fmin(base.x - r, apex.x);
	bbox.max.x = fmax(base.x + r, apex.x);
	bbox.min.y = fmin(base.y - r, apex.y);
	bbox.max.y = fmax(base.y + r, apex.y);
	bbox.min.z = fmin(base.z - r, apex.z);
	bbox.max.z = fmax(base.z + r, apex.z);
	return (bbox);
}
