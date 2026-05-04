/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_contribution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:02:57 by van               #+#    #+#             */
/*   Updated: 2025/09/05 12:06:03 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "struct_scn_obj.h"
#include "compute_lighting.h"
#include "miniRT.h"

void	light_contribution(t_rt *rt, t_compute_l *v, t_ray *ray, t_light *light)
{
	t_vec3		vec_light;
	t_vec3		diffuse_color;
	float		dist_to_light;
	t_vec3		spec_color;
	float		attenuation;

	vec_light = substract(&light->coo, v->point);
	dist_to_light = norm(&vec_light);
	normalize(&vec_light);
	if (is_in_shadow(rt, ray, &vec_light, dist_to_light))
		return ;
	diffuse_color = diffused_contribution(v, ray, &vec_light, light);
	spec_color = spec_contribution(rt, v, light, ray);
	attenuation = 1.0f / (1.0f + 0.002 * dist_to_light
			+ 0.0001f * dist_to_light * dist_to_light);
	diffuse_color = scalar_mult(&diffuse_color, attenuation);
	diffuse_color = scalar_mult(&diffuse_color, attenuation);
	spec_color = scalar_mult(&spec_color, attenuation);
	v->color = add(&v->color, &diffuse_color);
	v->color = add(&v->color, &spec_color);
}

bool	is_in_shadow(t_rt *rt, t_ray *ray, t_vec3 *vec_light,
			float dist_to_light)
{
	float	t_min;
	t_ray	to_light;

	to_light.origin = ray->point;
	to_light.direction = *vec_light;
	to_light.hit = NULL;
	t_min = INFINITY;
	bvh_intersect_early_exit(&to_light, rt->bvh, &t_min, ray->hit);
	if (t_min < dist_to_light)
		return (true);
	planes_intersect(&to_light, rt->scn.planes, &t_min, ray->hit);
	if (t_min < dist_to_light)
		return (true);
	return (false);
}

t_vec3	diffused_contribution(t_compute_l *v, t_ray *ray, t_vec3 *vec_light,
			t_light *light)
{
	float	diff;
	t_vec3	diffuse;
	t_vec3	scaled_color;

	if (v->type == PL)
		scaled_color = checkerboard_color_for_plane
			((t_plane *)ray->hit, v->point);
	else
	{
		scaled_color.x = v->obj_rgb->x / 255.0f;
		scaled_color.y = v->obj_rgb->y / 255.0f;
		scaled_color.z = v->obj_rgb->z / 255.0f;
	}
	diff = fmaxf(dot(&ray->normal, vec_light), 0.0f);
	diffuse = hadamard_product(&scaled_color, &light->rgb);
	diffuse = scalar_mult(&diffuse, diff * light->brightness_ratio * v->kd);
	return (diffuse);
}

t_vec3	spec_contribution(t_rt *rt, t_compute_l *v, t_light *light, t_ray *ray)
{
	float		dot_nl;
	t_vec3		light_dir;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	float		spec_intensity;

	light_dir = substract(&light->coo, &ray->origin);
	normalize(&light_dir);
	view_dir = substract(&rt->scn.cam->coo, &ray->origin);
	normalize(&view_dir);
	dot_nl = dot(&ray->normal, &light_dir);
	if (dot_nl <= 0)
		return ((t_vec3){0});
	reflect_dir = scalar_mult(&ray->normal, 2 * dot_nl);
	reflect_dir = substract(&reflect_dir, &light_dir);
	normalize(&reflect_dir);
	spec_intensity = powf(fmaxf(dot(&reflect_dir, &view_dir), 0), v->pe);
	return (scalar_mult(&light->rgb, v->ks * spec_intensity));
}
