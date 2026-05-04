/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/01 10:00:00 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "bump_map.h"
# include "miniRT.h"
# include "struct_scn_obj.h"

# ifdef BONUS
#  include "cone_bonus.h"
# endif

typedef struct s_cone
{
	t_vec3			coo;
	t_vec3			orientation;
	float			radius;
	float			height;
	int				color;
	t_vec3			rgb;
	t_aabb			bbox;
	struct s_cone	*next;
	struct s_cone	*prev;
	float			ka;
	float			kd;
	float			ks;
	int				pe;
	float			kr;
	char			*bmap_name;
	float			scale;
	float			intensity;
	t_bump_map		*bmap;
	float			angle;
}					t_cone;

/* Intersection functions */
bool				ray_cone_intersect(t_ray *ray, t_cone *cone, float *t_out);
t_cone_hit			ray_cone_full_intersect(t_ray *ray, t_cone *cone,
						float *t_out);
void				set_normal_cn(t_vec3 *normal, t_vec3 *point, t_cone *cone,
						int face);
int					check_co_fields(t_scn_el_lst *node);

/* Texture mapping */
void				cartesian_to_cone(t_ray *ray, float *u, float *v);

/* AABB computation */
t_aabb				compute_cone_aabb(t_cone *cone);

#endif
