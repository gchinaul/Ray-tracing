/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 14:26:27 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:15:55 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_normal(t_ray *ray)
{
	float		u;
	float		v;
	t_bump_map	*map;

	ray->map = NULL;
	set_normal(ray);
	if (set_texture_data(ray, &u, &v, &map))
		return ;
	ray->u = u;
	ray->v = v;
	ray->map = map;
	ray->normal = perturb_normal(map, u, v, ray);
}

bool	set_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map)
{
	bool	ret;

	ret = false;
	if (ray->type == SP)
		ret = set_sp_texture_data(ray, u, v, map);
	else if (ray->type == PL)
		ret = set_pl_texture_data(ray, u, v, map);
	else if (ray->type == CY)
		ret = set_cy_texture_data(ray, u, v, map);
	else if (ray->type == CN)
		ret = set_co_texture_data(ray, u, v, map);
	return (ret);
}

bool	set_sp_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map)
{
	if (!((t_sphere *)ray->hit)->bmap_name)
		return (true);
	*map = ((t_sphere *)ray->hit)->bmap;
	ray->scale = ((t_sphere *)ray->hit)->scale;
	ray->intensity = ((t_sphere *)ray->hit)->intensity;
	cartesian_to_spherical(ray, u, v);
	return (false);
}

bool	set_pl_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map)
{
	if (!((t_plane *)ray->hit)->bmap_name)
		return (true);
	*map = ((t_plane *)ray->hit)->bmap;
	ray->scale = ((t_plane *)ray->hit)->scale;
	ray->intensity = ((t_plane *)ray->hit)->intensity;
	cartesian_to_plane(ray, u, v, *map);
	return (false);
}

bool	set_cy_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map)
{
	if (!((t_cylinder *)ray->hit)->bmap_name)
		return (true);
	*map = ((t_cylinder *)ray->hit)->bmap;
	ray->scale = ((t_cylinder *)ray->hit)->scale;
	ray->intensity = ((t_cylinder *)ray->hit)->intensity;
	cartesian_to_cylinder(ray, u, v);
	return (false);
}
