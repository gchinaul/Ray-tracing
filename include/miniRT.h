/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:18:34 by van               #+#    #+#             */
/*   Updated: 2025/09/11 21:18:30 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "bump_map.h"
# include "bvh.h"
# include "colors.h"
# include "compute_lighting.h"
# include "errors.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "intersections.h"
# include "math_for_phys_1.h"
# include "math_for_phys_2.h"
# include "minilibx.h"
# include "render_img.h"
# include "scene_parser.h"
# include "struct_rt.h"
# include "struct_scn_obj.h"
# include "variables.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "bvh.h"
# include "errors.h"
# include "get_obj.h"
# include "render_img.h"
# include "scene.h"
# include "free_utils.h"
# include "obj_transformations.h"

# include "checker_bonus.h"
# include "cone.h"
# include "cone_bonus.h"

# define BACKGROUND_COLOR 0x0000FF

/* Debug and utility functions */
void	print_bvh(t_bvhnode *head);
void	print_bvh_tree(t_bvhnode *node, int depth);
int		lst_size(t_scn_obj *lst);

#endif