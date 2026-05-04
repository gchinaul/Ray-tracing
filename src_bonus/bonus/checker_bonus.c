/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:15:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/11 21:25:57 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#include "checker_bonus.h"

static void	plane_basis(t_vec3 *n, t_vec3 *u, t_vec3 *v)
{
	t_vec3	a;

	if (fabs(n->y) < 0.99f)
		a = (t_vec3){0, 1, 0};
	else
		a = (t_vec3){1, 0, 0};
	*u = cross(&a, n);
	normalize(u);
	*v = cross(n, u);
	normalize(v);
}

static t_vec3	plane_local_coords(t_plane *pl, t_vec3 *p)
{
	t_vec3	u;
	t_vec3	v;
	t_vec3	rel;

	plane_basis(&pl->orientation, &u, &v);
	rel = substract(p, &pl->coo);
	return ((t_vec3){dot(&rel, &u), dot(&rel, &v), 0});
}

static t_vec3	darken(const t_vec3 *rgb, float factor)
{
	t_vec3	c;

	c.x = rgb->x * factor;
	c.y = rgb->y * factor;
	c.z = rgb->z * factor;
	return (c);
}

static t_vec3	get_base_color(t_plane *pl)
{
	t_vec3	base;

	base.x = pl->rgb.x / 255.0f;
	base.y = pl->rgb.y / 255.0f;
	base.z = pl->rgb.z / 255.0f;
	return (base);
}

t_vec3	checkerboard_color_for_plane(t_plane *pl, t_vec3 *point)
{
	const float	square_size = 5.0f;
	t_vec3		st;
	int			sx;
	int			sy;
	t_vec3		base;

	st = plane_local_coords(pl, point);
	sx = (int)floorf(st.x / square_size);
	sy = (int)floorf(st.y / square_size);
	base = get_base_color(pl);
	if ((sx + sy) & 1)
		return (darken(&base, 0.2f));
	return (base);
}
