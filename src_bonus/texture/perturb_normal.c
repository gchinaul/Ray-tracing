/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perturb_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:21:56 by van               #+#    #+#             */
/*   Updated: 2025/09/12 14:31:45 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// bump_map  : tableau 2D de float dans [0,1] chargé préalablement
// w, h      : dimensions de la bump map
// u, v      : coordonnées UV dans [0,1]

// N' = N - o(h/x) . U - o(h/v) . V

t_vec3	perturb_normal(t_bump_map *map, float u, float v, t_ray *ray)
{
	float	dhdu_dhdv[2];
	t_vec3	*normal;
	t_vec3	uv[2];
	t_vec3	tmp;
	t_vec3	perturbed_normal;

	calc_dhdu_dhdv(map, ray, (float *[2]){&u, &v}, dhdu_dhdv);
	normal = &ray->normal;
	set_uv_axes(ray, &uv[0], &uv[1]);
	tmp = scalar_mult(&uv[0], dhdu_dhdv[0]);
	perturbed_normal = substract(normal, &tmp);
	tmp = scalar_mult(&uv[1], dhdu_dhdv[1]);
	perturbed_normal = substract(&perturbed_normal, &tmp);
	if (norm(&perturbed_normal) < 0.01f)
	{
		tmp = scalar_mult(&uv[0], dhdu_dhdv[0]);
		tmp = scalar_mult(&tmp, 1.1);
		perturbed_normal = substract(normal, &tmp);
		tmp = scalar_mult(&uv[1], dhdu_dhdv[1]);
		tmp = scalar_mult(&tmp, 1.1);
		perturbed_normal = substract(&perturbed_normal, &tmp);
	}
	normalize(&perturbed_normal);
	return (perturbed_normal);
}

void	calc_dhdu_dhdv(t_bump_map *map, t_ray *ray, float **uv,
			float *dhdu_dhdv)
{
	float	hu[2];
	float	hv[2];
	float	delta_uv[2];

	delta_uv[0] = 1.0f / map->columns;
	delta_uv[1] = 1.0f / map->rows;
	hu[1] = sample_bump(map, *uv[0] + delta_uv[0], *uv[1]);
	hu[0] = sample_bump(map, *uv[0] - delta_uv[0], *uv[1]);
	hv[1] = sample_bump(map, *uv[0], *uv[1] + delta_uv[1]);
	hv[0] = sample_bump(map, *uv[0], *uv[1] - delta_uv[1]);
	dhdu_dhdv[0] = (hu[1] - hu[0]) / (2.0f * delta_uv[0]);
	dhdu_dhdv[1] = (hv[1] - hv[0]) / (2.0f * delta_uv[1]);
	dhdu_dhdv[0] *= ray->intensity;
	dhdu_dhdv[1] *= ray->intensity;
}

void	set_uv_axes(t_ray *ray, t_vec3 *u_axis, t_vec3 *v_axis)
{
	if (ray->type == SP)
		set_sp_uv_axes(ray, u_axis, v_axis);
	if (ray->type == PL)
	{
		*u_axis = ((t_plane *)ray->hit)->u_axis;
		*v_axis = ((t_plane *)ray->hit)->v_axis;
	}
	if (ray->type == CY)
	{
		*u_axis = ((t_cylinder *)ray->hit)->u_axis;
		*v_axis = ((t_cylinder *)ray->hit)->v_axis;
	}
}

void	set_pl_uv_axes(t_plane *pl)
{
	t_vec3	a;
	t_vec3	u;
	t_vec3	v;
	t_vec3	n;

	n = pl->orientation;
	if ((fabs(n.x) > 0.9))
		a = (t_vec3){0, 0, 1};
	else
		a = (t_vec3){1, 0, 0};
	u = cross(&n, &a);
	normalize(&u);
	v = cross(&n, &u);
	normalize(&v);
	pl->u_axis = u;
	pl->v_axis = v;
}

void	set_sp_uv_axes(t_ray *ray, t_vec3 *u_axis, t_vec3 *v_axis)
{
	t_vec3	xyz;
	float	r;
	float	phi;
	float	theta;

	r = ((t_sphere *)ray->hit)->diameter / 2.0f;
	xyz.x = ray->point.x - ((t_sphere *)ray->hit)->coo.x;
	xyz.y = ray->point.y - ((t_sphere *)ray->hit)->coo.y;
	xyz.z = ray->point.z - ((t_sphere *)ray->hit)->coo.z;
	phi = atan2f(xyz.y, xyz.x);
	if (phi < 0)
		phi += 2 * M_PI;
	theta = acosf(xyz.z / r);
	*u_axis = (t_vec3){-sinf(phi), cosf(phi), 0};
	*v_axis = (t_vec3){cosf(theta) * cosf(phi), cosf(theta) * sinf(phi),
		-sinf(theta)};
}
