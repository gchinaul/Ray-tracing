/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/08 15:22:17 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_BONUS_H
# define CONE_BONUS_H

# include "bump_map.h"
# include "bvh.h"
# include "cone.h" // base cone types
# include "miniRT.h"
# include "struct_rt.h"

void		cartesian_to_cone_bonus(t_ray *ray, float *u, float *v,
				t_vec3 *point);

bool		ray_cone_intersect_bonus(t_ray *ray, t_cone *cone,
				float *t_out);
bool		ray_disk_intersect_bonus(t_ray *ray, t_vec3 center,
				t_vec3 normal, float radius);
bool		intersect_bvh(t_aabb bbox, t_ray *ray);

/* Intersection functions (bonus variants) */
bool		ray_cone_intersect_bonus(t_ray *ray, t_cone *cone, float *t_out);
t_cone_hit	ray_cone_full_intersect_bonus(t_ray *ray, t_cone *cone,
				float *t_out);
void		set_normal_cn_bonus(t_vec3 *normal, t_vec3 *point, t_cone *cone,
				int face);

/* AABB computation */
t_aabb		compute_cone_aabb_bonus(t_cone *cone);

#endif
