/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_for_phys_1.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:21:44 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:57 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_FOR_PHYS_1_H
# define MATH_FOR_PHYS_1_H

# include <stdbool.h>
# include <math.h>

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}				t_vec3;

int	set_vec3(t_vec3 *v, float x, float y, float z);

static inline t_vec3	add(t_vec3 *u, t_vec3 *v)
{
	t_vec3	w;

	w.x = u->x + v->x;
	w.y = u->y + v->y;
	w.z = u->z + v->z;
	return (w);
}

static inline t_vec3	substract(t_vec3 *u, t_vec3 *v)
{
	t_vec3	w;

	w.x = u->x - v->x;
	w.y = u->y - v->y;
	w.z = u->z - v->z;
	return (w);
}

#endif
