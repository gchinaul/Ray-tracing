/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transformations.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 11:08:00 by van               #+#    #+#             */
/*   Updated: 2025/09/10 12:56:34 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_TRANSFORMATIONS_H
# define OBJ_TRANSFORMATIONS_H

# include "miniRT.h"

//	win_key_gest.c
void	change_selected(t_rt *rt, int keycode);
void	handle_rotation(t_rt *rt, int keycode, bool *re_print);
void	redo_bvh(t_rt *rt);
void	print_obj_type(t_rt *rt);

//	obj_translations.c
int		handle_light_translations(t_light *light, int keycode);
int		handle_sp_translations(t_sphere *sp, int keycode);
bool	vec3_z_translation(t_vec3 *coo, int keycode);
bool	vec3_x_translation(t_vec3 *coo, int keycode);
bool	vec3_y_translation(t_vec3 *coo, int keycode);
//	obj_translations2.c
int		handle_pl_translations(t_plane *pl, int keycode);
int		handle_cy_translations(t_cylinder *cy, int keycode);
void	handle_translations(t_rt *rt, int keycode, bool *re_print);

//	obj_rotations.c
int		handle_pl_rotation(t_plane *pl, int keycode);
int		handle_cy_rotation(t_cylinder *cy, int keycode);

# ifdef BONUS
//	obj_transformations_cone.c
int		handle_cn_translations_bonus(t_cone *cn, int keycode);
int		handle_cn_rotation_bonus(t_cone *cn, int keycode);
# endif

#endif
