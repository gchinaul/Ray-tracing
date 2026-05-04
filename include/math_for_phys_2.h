/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_for_phys_2.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 17:15:13 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 10:12:46 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FOR_PHYS_2_H
# define MATH_FOR_PHYS_2_H

# include "math_for_phys_3.h"
# include <math.h>
# include <stdio.h>

static inline float	dot(t_vec3 *u, t_vec3 *v)
{
	return ((u->x * v->x) + (u->y * v->y) + (u->z * v->z));
}

static inline t_vec3	cross(t_vec3 *u, t_vec3 *v)
{
	t_vec3	w;

	w.x = (u->y * v->z) - (u->z * v->y);
	w.y = (u->z * v->x) - (u->x * v->z);
	w.z = (u->x * v->y) - (u->y * v->x);
	return (w);
}

static inline void	normalize(t_vec3 *v)
{
	float	length;

	length = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
	if (length < 0.01)
		printf("!!!\n");
	*v = scalar_div(v, length);
}

static inline t_vec3	hadamard_product(t_vec3 *u, t_vec3 *v)
{
	t_vec3	w;

	w.x = u->x * v->x;
	w.y = u->y * v->y;
	w.z = u->z * v->z;
	return (w);
}

static inline float	norm(t_vec3 *u)
{
	return (sqrtf(u->x * u->x + u->y * u->y + u->z * u->z));
}

#endif