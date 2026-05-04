/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_for_phys_3.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:21:44 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:57 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FOR_PHYS_3_H
# define MATH_FOR_PHYS_3_H

# include "math_for_phys_1.h"

static inline t_vec3	scalar_mult(t_vec3 *u, float f)
{
	t_vec3	res;

	res.x = u->x * f;
	res.y = u->y * f;
	res.z = u->z * f;
	return (res);
}

static inline t_vec3	scalar_div(t_vec3 *u, float f)
{
	t_vec3	res;

	if (f == 0)
		return ((t_vec3){0, 0, 0});
	res.x = u->x / f;
	res.y = u->y / f;
	res.z = u->z / f;
	return (res);
}

static inline t_vec3	vec3_min(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	if (a.x < b.x)
		res.x = a.x;
	else
		res.x = b.x;
	if (a.y < b.y)
		res.y = a.y;
	else
		res.y = b.y;
	if (a.z < b.z)
		res.z = a.z;
	else
		res.z = b.z;
	return (res);
}

static inline t_vec3	vec3_max(t_vec3 a, t_vec3 b)
{
	t_vec3	res;

	if (a.x > b.x)
		res.x = a.x;
	else
		res.x = b.x;
	if (a.y > b.y)
		res.y = a.y;
	else
		res.y = b.y;
	if (a.z > b.z)
		res.z = a.z;
	else
		res.z = b.z;
	return (res);
}

#endif
