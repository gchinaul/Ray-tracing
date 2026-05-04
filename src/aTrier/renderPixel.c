/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderPixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 19:09:41 by van               #+#    #+#             */
/*   Updated: 2025/09/10 17:02:55 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bump_map.h"
#include "checker_bonus.h"
#include "compute_lighting.h"
#include "cone_bonus.h"
#include "miniRT.h"

t_vec3	bg_color(t_vec3 *color)
{
	color->x = (BACKGROUND_COLOR >> 16) & 0xFF;
	color->y = (BACKGROUND_COLOR >> 8) & 0xFF;
	color->z = BACKGROUND_COLOR & 0xFF;
	return (*color);
}

t_vec3	render_pixel(t_rt *data, t_ray *ray, int depth, t_vec3 *color)
{
	float	t_min;
	t_vec3	tmp;
	float	kr;

	if (depth > MAX_DEPTH)
		return (bg_color(color));
	t_min = INFINITY;
	scn_intersect(data, ray, &t_min, NULL);
	if (t_min != INFINITY)
	{
		kr = 0;
		tmp = get_local_color_contribution(data, ray, &kr, t_min);
		*color = add(color, &tmp);
		return (*color);
	}
	ray->hit = NULL;
	return (bg_color(color));
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

t_vec3	get_local_color_contribution(t_rt *rt, t_ray *ray, float *kr,
		float t_min)
{
	t_vec3	tmp;

	tmp = scalar_mult(&ray->direction, t_min);
	ray->point = add(&ray->origin, &tmp);
	set_normal(ray);
	tmp = compute_lighting(rt, ray);
	tmp = scalar_mult(&tmp, 1 - *kr);
	return (tmp);
}
