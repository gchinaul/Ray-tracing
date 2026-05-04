/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:09:15 by van               #+#    #+#             */
/*   Updated: 2025/09/12 15:39:36 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "math_for_phys_1.h"

typedef struct s_rt		t_rt;
typedef struct s_ray	t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_img	*img;
	int		width;
	int		height;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
}			t_mlx;

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_Q = 113,
	KEY_E = 101,
	KEY_COMMA = 44,
	KEY_DOT = 46,
	KEY_DOWN = 65364,
	KEY_PLUS = 65451,
	KEY_MINUS = 65453,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100,
	KEY_R = 114,
	KEY_T = 116,
	KEY_F = 102,
	KEY_G = 103,
	KEY_U = 117,
	KEY_I = 105,
	KEY_O = 111,
	KEY_P = 112
}			t_keys;

typedef struct s_viewplane_1
{
	t_vec3	centre;
	t_vec3	top_left;
	t_vec3	vec_right;
	t_vec3	vec_up;
	float	x_indent;
	float	y_indent;
}			t_viewplane_1;

typedef struct s_hook
{
	t_mlx	*mlx;
	void	*extra_data;
}			t_hook;

void		*cnct(void);
void		*new_win(void *connection_id, int size_x, int size_y, char *title);
int			init_img(void *connection_id, t_img *img, int width, int height);
int			mlx_ini(t_mlx *mlx, int width, int height, char *title);
int			mlx_free(t_mlx *mlx);
int			mlx_free_image(t_mlx *mlx);
void		put_pixel(t_img *img, int x, int y, int color);
int			win_key_handler(int keycode, t_hook *hook);
int			close_window(void *param);

//
void		set_vp_hw(float *w, float *h, t_camera *cam, t_mlx *mlx);
// déjà dans render_img.h
// int			render_pixel(t_rt *data, t_ray *ray, int depth, t_vec3 *color);
t_vec3		calculate_right_vector(t_camera *cam);
void		handle_camera_movement(t_rt *data, int keycode);
t_vec3		rotate_vector(t_vec3 *vec, t_vec3 *axis, float angle);
void		handle_camera_rotation(t_rt *data, int keycode);
void		handle_zoom(t_rt *data, int keycode, bool *re_print);
int			win_key_handler(int keycode, t_hook *hook);
int			close_window(void *param);
void		change_selected_type(t_rt *rt, int keycode);
void		objs_translations(t_rt *rt, int keycode, bool *re_print);
void		change_selected_light(t_rt *rt, int keycode);
void		change_selected_plane(t_rt *rt, int keycode);
void		change_selected_objs(t_rt *rt, int keycode);

#endif
