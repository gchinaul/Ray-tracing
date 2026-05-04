/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_scn_obj.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:47:57 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:16:37 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SCN_OBJ_H
# define STRUCT_SCN_OBJ_H

typedef struct s_aabb		t_aabb;
typedef struct s_scn_obj	t_scn_obj;
typedef struct s_bvhnode	t_bvhnode;
typedef struct s_bump_map	t_bump_map;
typedef struct s_cone		t_cone;

typedef enum e_cyl_hit
{
	CYLINDER_NONE,
	CYLINDER_SIDE,
	CYLINDER_BASE_BOTTOM,
	CYLINDER_BASE_TOP
}							t_cyl_hit;

typedef enum e_cone_hit
{
	CONE_NONE,
	CONE_SIDE,
	CONE_BASE
}							t_cone_hit;

struct						s_aabb
{
	t_vec3					min;
	t_vec3					max;
};

typedef struct s_amb_light
{
	float					light_ratio;
	int						color;
	t_vec3					rgb;
}							t_amb_light;

typedef struct s_camera
{
	t_vec3					coo;
	t_vec3					orientation;
	int						fov_h;
	int						focal_length;
}							t_camera;

typedef struct s_light		t_light;
struct						s_light
{
	t_vec3					coo;
	float					brightness_ratio;
	int						color;
	t_vec3					rgb;
	t_light					*prev;
	t_light					*next;
};

typedef struct s_sphere
{
	t_vec3					coo;
	float					diameter;
	int						color;
	t_vec3					rgb;
	t_aabb					bbox;
	float					ka;
	float					kd;
	float					ks;
	int						pe;
	float					kr;
	char					*bmap_name;
	float					scale;
	float					intensity;
	t_bump_map				*bmap;
}							t_sphere;

typedef struct s_plane		t_plane;
struct						s_plane
{
	t_vec3					coo;
	t_vec3					orientation;
	int						color;
	t_vec3					rgb;
	t_plane					*next;
	t_plane					*prev;
	float					ka;
	float					kd;
	float					ks;
	int						pe;
	float					kr;
	t_vec3					u_axis;
	t_vec3					v_axis;
	char					*bmap_name;
	float					scale;
	float					intensity;
	t_bump_map				*bmap;
};

typedef struct s_cylinder
{
	t_vec3					coo;
	t_vec3					orientation;
	float					diameter;
	float					height;
	int						color;
	t_vec3					rgb;
	t_aabb					bbox;
	float					ka;
	float					kd;
	float					ks;
	int						pe;
	float					kr;
	t_vec3					u_axis;
	t_vec3					v_axis;
	char					*bmap_name;
	float					scale;
	float					intensity;
	t_bump_map				*bmap;
}							t_cylinder;

typedef enum e_obj_type
{
	A,
	C,
	L,
	SP,
	PL,
	CY,
	CN,
	COUNT
}							t_obj_type;

typedef struct s_scn		t_scn;
struct						s_scn
{
	t_camera				*cam;
	t_amb_light				*amb;
	t_light					*lights;
	t_scn_obj				*objs;
	int						objs_count;
	t_plane					*planes;
	t_cone					*cones;
	t_bvhnode				*bvh;
	t_scn_obj				**arr;
};

struct						s_scn_obj
{
	t_obj_type				type;
	void					*data;
	t_scn_obj				*next;
	t_scn_obj				*prev;
	t_aabb					bbox;
};

typedef struct s_ray
{
	t_vec3					origin;
	t_vec3					direction;
	t_vec3					point;
	void					*hit;
	t_obj_type				type;
	int						face;
	t_vec3					normal;
	float					u;
	float					v;
	t_bump_map				*map;
	float					scale;
	float					intensity;
	float					t;
}							t_ray;

struct						s_bvhnode
{
	t_aabb					bbox;
	t_bvhnode				*left;
	t_bvhnode				*right;
	t_scn_obj				**objs;
	int						object_count;
	bool					is_leaf;
};

struct						s_bump_map
{
	char					*name;
	int						rows;
	int						columns;
	int						scale;
	float					*map;
	t_bump_map				*next;
};

#endif
