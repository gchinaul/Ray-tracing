/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:29:52 by van               #+#    #+#             */
/*   Updated: 2025/09/05 07:55:18 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_PARSER_H
# define SCENE_PARSER_H

# include "get_next_line.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>

# define CY_MAX_LEN 99

typedef struct s_scn_el_lst	t_scn_el_lst;
struct						s_scn_el_lst
{
	char					*id;
	char					**data;
	t_scn_el_lst			*next;
};

//	scn_el_lst.c
void					set_attr_null(t_scn_el_lst *node);
t_scn_el_lst			*new_node(void);
void					delete_node(t_scn_el_lst **node);
int						append_node(t_scn_el_lst **lst, t_scn_el_lst *node);
void					delete_lst(t_scn_el_lst **lst);

//	parser1.c
int						parse_scene(char *file, t_scn_el_lst **lst);
int						set_nodes(int fd, t_scn_el_lst **lst);
int						set_node(t_scn_el_lst **lst, char *line);
void					print_datas(t_scn_el_lst **lst);
//	parser2.c
int						check_data(t_scn_el_lst **lst);
int						is_valid_data(t_scn_el_lst *node);
int						check_id(t_scn_el_lst *node);
int						is_valid_id(char *s);
int						check_fields(t_scn_el_lst *node);

//	fields_checkers1.c
int						check_a_fields(t_scn_el_lst *node);
int						check_c_fields(t_scn_el_lst *node);
int						check_l_fields(t_scn_el_lst *node);
int						check_sp_fields(t_scn_el_lst *node);
int						check_pl_fields(t_scn_el_lst *node);
//	fields_checkers2.c
int						check_cy_fields(t_scn_el_lst *node);
bool					check_fields_lighting(t_scn_el_lst *node, int start);
bool					check_fields_texture(t_scn_el_lst *node, int start);
int						check_co_fields(t_scn_el_lst *node);

// format_checkers1.c
int						is_dot_format_in_range_1(char *s);
int						is_rgb_format(char *s);
int						is_one_digit_after_dot(char *s, int *count);
int						is_coo_format(char *s);
int						is_fov_format(char *s);
// format_checkers2.c
int						is_orientation_format(char *s);
int						is_length_format(char *s);
int						is_orientation_vec_null(char *s);
bool					is_positive_int_format(char *s);
bool					is_float_format(char *s);

// number_checker.c
int						check_number(t_scn_el_lst **lst);
int						err_acl_count(int *acl_count);

#endif
