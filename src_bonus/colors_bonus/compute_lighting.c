/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 12:02:27 by van               #+#    #+#             */
/*   Updated: 2025/09/05 10:07:23 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	compute_lighting(t_rt *rt, t_ray *ray)
{
	t_compute_l	v;
	t_light		*lights;

	compute_l_set_v(&v, ray);
	v.face = ray->face;
	v.color = scalar_mult(v.obj_rgb, v.ka * rt->scn.amb->light_ratio);
	if (ray->map)
		v.color = scalar_mult(&v.color, sample_bump(ray->map, ray->u, ray->v));
	lights = rt->scn.lights;
	while (lights)
	{
		light_contribution(rt, &v, ray, lights);
		lights = lights->next;
	}
	return (v.color);
}

void	tone_map(t_vec3 *color)
{
	float		r;
	float		g;
	float		b;
	const float	exposure = 1.0f;
	const float	gamma = 2.2f;

	r = (color->x * exposure) / 255.0f;
	g = (color->y * exposure) / 255.0f;
	b = (color->z * exposure) / 255.0f;
	r = r / (1.0f + r);
	g = g / (1.0f + g);
	b = b / (1.0f + b);
	r = powf(r, 1.0f / gamma);
	g = powf(g, 1.0f / gamma);
	b = powf(b, 1.0f / gamma);
	color->x = r * 255.0f;
	color->y = g * 255.0f;
	color->z = b * 255.0f;
}

void	clamp_rgb(t_vec3 *color)
{
	if (color->x > 255)
		color->x = 255;
	if (color->y > 255)
		color->y = 255;
	if (color->z > 255)
		color->z = 255;
}
