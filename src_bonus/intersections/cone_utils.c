/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 08:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:27:17 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "miniRT.h"
#include "cone_utils.h"

static void	solve_quadratic_discriminant(t_quad_params *p)
{
	float	discriminant;
	float	q;
	float	tmp;

	discriminant = p->b * p->b - 4 * p->a * p->c;
	if (p->b > 0)
		q = -0.5 * (p->b + sqrtf(discriminant));
	else
		q = -0.5 * (p->b - sqrtf(discriminant));
	*(p->t0) = q / p->a;
	*(p->t1) = p->c / q;
	if (*(p->t0) > *(p->t1))
	{
		tmp = *(p->t0);
		*(p->t0) = *(p->t1);
		*(p->t1) = tmp;
	}
}

static bool	handle_negative_roots(float *t0, float t1, float *t)
{
	if (*t0 < 0)
	{
		*t0 = t1;
		if (*t0 < 0)
			return (false);
	}
	*t = *t0;
	return (true);
}

bool	solve_quadratic(float a, float b, float c, float *t)
{
	float			discriminant;
	float			t0;
	float			t1;
	t_quad_params	params;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (false);
	if (discriminant == 0)
	{
		t0 = -0.5 * b / a;
		t1 = t0;
	}
	else
	{
		params = (t_quad_params){a, b, c, &t0, &t1};
		solve_quadratic_discriminant(&params);
	}
	return (handle_negative_roots(&t0, t1, t));
}

bool	check_cone_height(t_ray *ray, t_cone *cone, float t)
{
	t_vec3	scaled_dir;
	t_vec3	p;
	t_vec3	v;
	float	h;

	scaled_dir = scalar_mult(&ray->direction, t);
	p = add(&ray->origin, &scaled_dir);
	v = substract(&p, &cone->coo);
	h = dot(&v, &cone->orientation);
	if (h < 0 || h > cone->height)
		return (false);
	return (true);
}
