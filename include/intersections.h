/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:53:52 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:45:47 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include <stdbool.h>
# include "miniRT.h"

typedef struct s_vec3		t_vec3;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_sp_intersect
{
	t_vec3					oc;
	float					b;
	float					c;
	float					discriminant;
	float					sqrt_disc;
	float					t1;
	float					t2;
	float					radius;
}							t_sp_intersect;

//	intersections_1.c
bool		ray_sphere_intersect(t_ray *ray, t_sphere *sp, float *t);
bool		ray_plane_intersect(t_ray *ray, t_plane *plane, float *t);
bool		ray_cylinder_intersect(t_ray *ray, t_cylinder *cy, float *t_out);
bool		calc_t1_t2_cy(t_ray *ray, t_cylinder *cy, float *t1, float *t2);
void		test_t_cy(t_ray *ray, t_cylinder *cy, bool *found,
				float **t_tcandidate);

//	intersections_2.c
t_vec3		vec_project_orthogonal(t_vec3 v, t_vec3 axis);
bool		ray_disk_intersect(t_ray *ray, t_vec3 *center_normal,
				float radius, float *t_out);
t_cyl_hit	ray_cylinder_full_intersect(t_ray *ray, t_cylinder *cyl,
				float *t_out);
void		bases_cy_full(t_ray *ray, t_cylinder *cy, float *t_best,
				t_cyl_hit *hit_type);

//	planes_intersect.c
int			planes_intersect(t_ray *ray, t_plane *planes, float *t, void *self);
void		set_ray_hit_plane(t_ray *ray, float *t, float t_tmp,
				t_plane *plane);

//	scn_intersect.c
void		scn_intersect(t_rt *rt, t_ray *ray, float *t_min, void *self);
void		objs_intersect(t_rt *rt, t_ray *ray, float *t_min, void *self);

//	cone_intersection.c
int			cones_intersect(t_ray *ray, t_cone *cones, float *t, void *self);

#endif
