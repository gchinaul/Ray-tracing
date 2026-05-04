/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:23:26 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:00:11 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_IMG_H
# define RENDER_IMG_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_vec3		t_vec3;
typedef struct s_camera		t_camera;
typedef struct s_mlx		t_mlx;
typedef struct s_rt			t_rt;
typedef struct s_ray		t_ray;
typedef struct s_scn_obj	t_scn_obj;

typedef struct s_viewplane
{
	t_vec3	centre;
	t_vec3	top_left;
	float	x_indent;
	float	y_indent;
	t_vec3	vec_up;
	t_vec3	vec_right;
}				t_viewplane;

//	renderImg.c
void	render_img(t_rt *data);
void	init_t_viewplane(t_viewplane *vp, t_camera *cam, t_mlx *mlx);
void	set_vp_hw(float *w, float *h, t_camera *cam, t_mlx *mlx);
void	compute_new_ray(t_rt *rt, t_viewplane *vp, t_ray *ray, int *ij);

//	renderPixel.c
t_vec3	render_pixel(t_rt *data, t_ray *ray, int depth, t_vec3 *color);
t_vec3	compute_final_depth(t_ray *ray, t_vec3 *color);
void	get_hit_obj_kr(t_ray *ray, float *kr);
void	compute_reflected_ray(t_ray *ray);
t_vec3	get_local_color_contribution(t_rt *rt, t_ray *ray, float *kr,
			float t_min);

//	compute_normal.c
void	compute_normal(t_ray *ray);
bool	set_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map);
bool	set_sp_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map);
bool	set_pl_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map);
bool	set_cy_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map);
bool	set_co_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map);

#endif
