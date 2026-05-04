/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:55:29 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "ft_printf.h"
# include "libft.h"
# include "struct_rt.h"
# include <math.h>
# include <unistd.h>

typedef struct s_scn_obj	t_scn_obj;
typedef struct s_scn_el_lst	t_scn_el_lst;
typedef struct s_vec3		t_vec3;
typedef struct s_amb_light	t_amb_light;
typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cone		t_cone;

//	print_objects.c
void		print_objects(t_scn_obj **objs);
void		print_id(int type);
void		print_data(t_scn_obj *node);
void		print_a_data(t_amb_light *data);
void		print_c_data(t_camera *data);
//	print_objects2.c
void		print_l_data(t_light *data);
void		print_sp_data(t_sphere *data);
void		print_pl_data(t_plane *data);
void		print_cy_data(t_cylinder *data);
void		print_co_data(t_cone *data);

//	data_convert.c
float		float_str_to_float(char *str);
int			rgb_str_to_int(char *str, t_vec3 *rgb);
t_vec3		_3f_str_to_vec3(char *str);

//	object.c
void		append_obj(t_scn_obj **lst, t_scn_obj *node);
t_scn_obj	*new_obj(void);
void		set_obj_attr_null(t_scn_obj *node);
void		delete_objs(t_scn_obj **objs);

//	init_objects.c
int			init_objects(t_scn_el_lst **lst, t_scn_obj **objs);
int			add_obj(t_scn_el_lst *el, t_scn_obj **objs);
int			add_a_obj(t_scn_el_lst *el, t_scn_obj **objs);
int			add_c_obj(t_scn_el_lst *el, t_scn_obj **objs);
int			add_l_obj(t_scn_el_lst *el, t_scn_obj **objs);
//	init_objects2.c
int			add_sp_obj(t_scn_el_lst *el, t_scn_obj **objs);
int			add_cy_obj(t_scn_el_lst *el, t_scn_obj **objs);

int			add_co_obj(t_scn_el_lst *el, t_scn_obj **objs);

//	obj_init_data.c
t_amb_light	*init_a_data(t_scn_el_lst *el);
t_camera	*init_c_data(t_scn_el_lst *el);
t_light		*init_l_data(t_scn_el_lst *el);
t_sphere	*init_sp_data(t_scn_el_lst *el);
t_plane		*init_pl_data(t_scn_el_lst *el);
//	obj_init_data2.c
t_cylinder	*init_cy_data(t_scn_el_lst *el);
void		set_sp_lighting_attr(t_scn_el_lst *el, t_sphere *data, int start);
void		set_cy_lighting_attr(t_scn_el_lst *el, t_cylinder *data, int start);
void		set_pl_lighting_attr(t_scn_el_lst *el, t_plane *data, int start);
//	obj_init_data_co.c
t_cone		*init_co_data(t_scn_el_lst *el);
t_cone		*parse_cone(char **tokens, int *err);
void		init_cone_material(t_cone *cone);
int			validate_cone_params(t_cone *cone, char **tokens);

//	init_scene.c
int			init_scene(t_scn_el_lst **lst, t_scn *scn);
void		set_scn_attr_null(t_scn *scn);
bool		process_current_el(t_scn_el_lst *current, t_scn *scn);
int			process_shape(t_scn_el_lst *current, t_scn *scn);
bool		has_bounded_volume(t_scn_el_lst *el);
//	init_scene2.c
int			add_light(t_scn_el_lst *el, t_light **lights);
int			add_plane(t_scn_el_lst *el, t_plane **planes);
int			add_cone(t_scn_el_lst *el, t_cone **cones);

//	print_scene.c
void		print_scn(t_scn *scn);
void		print_lights(t_light *lights);
void		print_planes(t_plane *planes);

#endif
