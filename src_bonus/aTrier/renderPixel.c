/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderPixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:09:41 by van               #+#    #+#             */
/*   Updated: 2025/09/07 13:45:44 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bump_map.h"
#include "checker_bonus.h"
#include "compute_lighting.h"
#include "cone_bonus.h"
#include "miniRT.h"

t_vec3	render_pixel(t_rt *data, t_ray *ray, int depth, t_vec3 *color)
{
	float	t_min;
	t_vec3	tmp;
	float	kr;
	void	*self;

	if (depth > MAX_DEPTH)
		return (compute_final_depth(ray, color));
	self = ray->hit;
	t_min = INFINITY;
	bvh_intersect(ray, data->bvh, &t_min, (void *[2]){self, &(float){0}});
	planes_intersect(ray, data->scn.planes, &t_min, self);
	if (t_min != INFINITY)
	{
		tmp = get_local_color_contribution(data, ray, &kr, t_min);
		*color = add(color, &tmp);
		if (kr >= 0.1f)
		{
			compute_reflected_ray(ray);
			tmp = render_pixel(data, ray, depth + 1, color);
			return (scalar_mult(&tmp, kr));
		}
		return (*color);
	}
	ray->hit = NULL;
	return (render_pixel(data, ray, MAX_DEPTH + 1, color));
}

t_vec3	compute_final_depth(t_ray *ray, t_vec3 *color)
{
	t_vec3	tmp;

	if (ray->hit)
	{
		if (ray->type == SP)
			tmp = ((t_sphere *)ray->hit)->rgb;
		else if (ray->type == PL)
			tmp = ((t_plane *)ray->hit)->rgb;
		else if (ray->type == CY)
			tmp = ((t_cylinder *)ray->hit)->rgb;
		else if (ray->type == CN)
			tmp = ((t_cone *)ray->hit)->rgb;
	}
	else
	{
		tmp.x = (BACKGROUND_COLOR >> 16) & 0xFF;
		tmp.y = (BACKGROUND_COLOR >> 8) & 0xFF;
		tmp.z = BACKGROUND_COLOR & 0xFF;
	}
	*color = add(color, &tmp);
	return (*color);
}

void	get_hit_obj_kr(t_ray *ray, float *kr)
{
	if (ray->type == SP)
		*kr = ((t_sphere *)ray->hit)->kr;
	else if (ray->type == PL)
		*kr = ((t_plane *)ray->hit)->kr;
	else if (ray->type == CY)
		*kr = ((t_cylinder *)ray->hit)->kr;
	else if (ray->type == CN)
		*kr = ((t_cone *)ray->hit)->kr;
	else
		*kr = 0.0f;
}

void	compute_reflected_ray(t_ray *ray)
{
	t_vec3	tmp;

	set_normal(ray);
	tmp = scalar_mult(&ray->normal, 2 * dot(&ray->direction, &ray->normal));
	ray->direction = substract(&ray->direction, &tmp);
	normalize(&ray->direction);
	ray->origin = ray->point;
}

t_vec3	get_local_color_contribution(t_rt *rt, t_ray *ray, float *kr,
		float t_min)
{
	t_vec3	tmp;

	get_hit_obj_kr(ray, kr);
	tmp = scalar_mult(&ray->direction, t_min);
	ray->point = add(&ray->origin, &tmp);
	ray->map = NULL;
	compute_normal(ray);
	tmp = compute_lighting(rt, ray);
	tmp = scalar_mult(&tmp, 1 - *kr);
	return (tmp);
}
