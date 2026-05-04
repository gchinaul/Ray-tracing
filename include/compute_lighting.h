/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_lighting.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:18:10 by van               #+#    #+#             */
/*   Updated: 2025/09/07 13:46:38 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTE_LIGHTING_H
# define COMPUTE_LIGHTING_H

# include "miniRT.h"
# include <stdbool.h>

typedef struct s_vec3		t_vec3;
typedef struct s_scn_obj	t_scn_obj;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_cylinder	t_cylinder;
typedef struct s_rt			t_rt;

typedef struct s_compute_lighting
{
	t_vec3					*point;
	t_vec3					color;
	void					*obj_data;
	t_vec3					*obj_rgb;
	t_obj_type				type;
	int						face;
	float					ka;
	float					kd;
	float					ks;
	float					pe;
}							t_compute_l;

//	compute_lighting.c
t_vec3						compute_lighting(t_rt *rt, t_ray *ray);
void						tone_map(t_vec3 *color);
void						clamp_rgb(t_vec3 *color);

//	compute_l_set_v.c
void						compute_l_set_v(t_compute_l *v, t_ray *ray);
void						compute_l_set_v_sp(t_compute_l *v, t_sphere *sp);
void						compute_l_set_v_pl(t_compute_l *v, t_plane *pl);
void						compute_l_set_v_cy(t_compute_l *v, t_cylinder *cy);
void						compute_l_set_v_co(t_compute_l *v, t_cone *co);

//	light_contribution.c
void						light_contribution(t_rt *rt, t_compute_l *v,
								t_ray *ray, t_light *light);
bool						is_in_shadow(t_rt *rt, t_ray *ray,
								t_vec3 *vec_light, float dist_to_light);
t_vec3						spec_contribution(t_rt *rt, t_compute_l *v,
								t_light *light, t_ray *ray);
t_vec3						diffused_contribution(t_compute_l *v, t_ray *ray,
								t_vec3 *vec_light, t_light *light);

//	lighting_calc.c
void						apply_light_attenuation(t_vec3 *diffuse,
								t_vec3 *spec, float distance);
void						add_light_colors(t_vec3 *total, t_vec3 *diffuse,
								t_vec3 *spec);

//	set_normal.c
void						set_normal(t_ray *ray);
void						set_normal_sp(t_vec3 *normal, t_vec3 *point,
								t_sphere *sp);
void						set_normal_cy(t_vec3 *normal, t_vec3 *point,
								t_cylinder *cy, int face);

#endif
