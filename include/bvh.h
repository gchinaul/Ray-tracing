/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:49:39 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include "math_for_phys_1.h"
# include "struct_scn_obj.h"

//	aabb.c
int			longest_axis(t_aabb *bbox);
float		aabb_intersect(t_aabb *bbox, t_ray *ray);
void		calc_t0_t1_aabb_intersect(t_ray *ray, t_aabb *bbox, t_vec3 *t0,
				t_vec3 *t1);
void		calc_t_min_t_max_aabb_intersect(t_vec3 *t0, t_vec3 *t1,
				float *t_min, float *t_max);
int			aabb_overlap(t_aabb *a, t_aabb *b);

//	init_bvh_1.c
t_bvhnode	*init_bvh(t_scn *scn, int count);
t_bvhnode	*build_bvh(t_scn_obj **objs, int count);
t_bvhnode	*create_leaf(t_scn_obj **objs, int count);
t_aabb		compute_combined_aabb(t_scn_obj **objs, int count);
t_aabb		combine_aabb(const t_aabb *a, const t_aabb *b);
//	init_bvh_2.c
int			centroid_comparator(t_scn_obj *a, t_scn_obj *b, int axis);

//	obj_aabb
//		sphere_aabb.c
t_aabb		compute_sphere_aabb(t_sphere *sp);
//		cylinder_aabb.c
t_aabb		compute_cylinder_aabb_safe(t_cylinder *cyl);

//		intersect_axis.c
bool		check_axis_intersection(t_aabb bbox, t_ray *ray,
				int axis, float *bounds);

//		intersect_bvh_utils.c
float		get_ray_component(t_ray *ray, int axis);
float		get_origin_component(t_ray *ray, int axis);
float		get_bbox_min(t_aabb bbox, int axis);
float		get_bbox_max(t_aabb bbox, int axis);

//	bvh.c
int			bvh_intersect(t_ray *ray, t_bvhnode *node, float *t, void **s_s);
int			bvh_intersect_early_exit(t_ray *ray, t_bvhnode *node, float *t,
				void *self);
bool		bvh_search(t_bvhnode *node, t_ray *ray, float **t_t_left_t_right,
				void *self);
bool		bvh_search_overlap(t_bvhnode *node, t_ray *ray,
				float **t_t_left_t_right, void *self);
//	bvh_2.c
int			objects_intersect(t_ray *ray, t_bvhnode *node, float *t,
				void *self);
int			redirect_intersect_type_ft(t_bvhnode *node, t_ray *ray,
				float *t_obj, int i);

//	sort
//		bubble.c
void		sort_objects_by_axis(t_scn_obj **arr, int count, int axis);
void		swap_nodes(t_scn_obj *a, t_scn_obj *b);
//		merge.c
t_scn_obj	*merge_sort(t_scn_obj *head, int axis);
t_scn_obj	*merge(t_scn_obj *a, t_scn_obj *b, int axis);
void		sort_list(t_scn_obj **head, int axis);

#endif
