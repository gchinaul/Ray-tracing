/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_rt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:04:31 by van               #+#    #+#             */
/*   Updated: 2025/09/05 17:01:52 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RT_H
# define STRUCT_RT_H

# include "bump_map.h"
# include "bvh.h"
# include "math_for_phys_1.h"
# include "minilibx.h"
# include <stdbool.h>

typedef enum s_select_type
{
	CAM,
	LIGHTS,
	OBJS,
	PLANES
}					t_select_type;

typedef struct s_selected
{
	t_select_type	type;
	t_camera		*cam;
	t_light			*lights;
	t_scn_obj		*objs;
	t_plane			*planes;
}					t_selected;

typedef struct s_rt
{
	t_scn			scn;
	t_mlx			mlx;
	t_selected		selected;
	t_bvhnode		*bvh;
	t_bump_map		*b_maps;
}					t_rt;

#endif
