/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 18:05:30 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUMP_MAP_H
# define BUMP_MAP_H

# include "math_for_phys_1.h"
# include <stdbool.h>

typedef struct s_rt			t_rt;
typedef struct s_scn_obj	t_scn_obj;
typedef struct s_bump_map	t_bump_map;
typedef struct s_ray		t_ray;
typedef struct s_plane		t_plane;

//	bump_map.c
int			init_bump_maps(t_rt *rt);
void		link_planes(t_rt *rt);
void		link_objs(t_rt *rt);
char		*get_obj_bmap_name(t_scn_obj *obj);
void		set_obj_bmap(t_scn_obj *obj, t_bump_map *map);
//	bump_map_2.c
int			alloc_bump_maps(t_rt *rt);
bool		have_bmaps_valid_ext(t_bump_map *map);
bool		are_bmaps_openable(t_bump_map *maps);
int			register_objs_texture(t_rt *rt);
int			register_planes_texture(t_rt *rt);
//	bump_map_3.c
void		append_bump_map(t_rt *rt, t_bump_map *map);
bool		is_new_map(t_bump_map *maps, char *name);
void		set_map_attr_null(t_bump_map *map);
int			init_bump_map(t_bump_map *map);
//	bump_map_4.c
int			init_map(t_bump_map *map, int fd);
bool		copy_file_content(t_bump_map *map, char **line, int fd);
int			free_map(t_bump_map *map);

//	p3_header_check.c
int			check_header(int fd, t_bump_map *map);
int			check_header_1(int fd);
int			check_header_2(int fd, t_bump_map *map);
int			check_header_3(int fd, t_bump_map *map);

//	parsing_utils.c
char		*get_nth_word(char *s, int n);
bool		is_number(char *s);
int			count_words(char *s);
bool		ft_isspace(char c);
char		*get_next_word(char *s);

//	cartesian_convert.c
void		cartesian_to_spherical(t_ray *ray, float *u, float *v);
void		cartesian_to_plane(t_ray *ray, float *u, float *v,
				t_bump_map *bump_map);
void		cartesian_to_cylinder(t_ray *ray, float *u, float *v);
void		generate_orthonormal_basis(t_vec3 A, t_vec3 *U, t_vec3 *V);
void		wrap_uv(float *u, float *v);

//	sample_bump.c
float		sample_bump(t_bump_map *map, float u, float v);
void		get_indexes(float **uv, t_bump_map *map, int *xy2, int *xy);

//	perturb_normal.c
t_vec3		perturb_normal(t_bump_map *map, float u, float v, t_ray *ray);
void		set_uv_axes(t_ray *ray, t_vec3 *u_axis, t_vec3 *v_axis);
void		set_pl_uv_axes(t_plane *pl);
void		set_sp_uv_axes(t_ray *ray, t_vec3 *u_axis, t_vec3 *v_axis);
void		calc_dhdu_dhdv(t_bump_map *map, t_ray *ray, float **uv,
				float *dhdu_dhdv);

#endif
