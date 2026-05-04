/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 17:06:54 by van               #+#    #+#             */
/*   Updated: 2025/08/11 20:36:32 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

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
}				t_mlx;

typedef enum e_values
{
	MAX_ALTITUDE = 499,
	MAX_ALTITUDE_LEN = 3
}				t_values;

typedef struct s_coo
{
	int	***coo;
	int	**points;
	int	lines;
	int	points_per_line;
}				t_coo;

typedef struct s_print
{
	int	x_margin;
	int	y_margin;
	int	y_base;
	int	x_offset;
	int	x_gap;
	int	y_gap;
	int	alt_coef;
}				t_print;

typedef enum e_keys
{
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_UP = 65362,
	KEY_RIGHT = 65363,
	KEY_DOWN = 65364,
	KEY_PLUS = 65451,
	KEY_MINUS = 65453,
	KEY_W = 119,
	KEY_S = 115,
	KEY_A = 97,
	KEY_D = 100
}				t_keys;

typedef struct s_hook
{
	t_mlx	*mlx;
	t_coo	*coo;
	t_print	*print;
}				t_hook;

typedef struct s_check_lines_vars
{
	char	c;
	char	int_str[8];
	int		i;
	int		bytes;
	int		hexa;
	char	prev;
	int		res;
}			t_cl_vars;

// errors.c
int		err_altitude(void);
int		err_map_unvalid_char(void);

// connect
void	*cnct(void);

// new_win
void	*new_win(void *connection_id, int size_x, int size_y, char *title);

// init_img
int		init_img(void *connection_id, t_img *img, int width, int height);

// mlx.c
int		mlx_ini(t_mlx *mlx, int width, int height, char *title);
int		mlx_free(t_mlx *mlx);
int		mlx_free_image(t_mlx *mlx);

// put_pixel
void	put_pixel(t_img *img, int x, int y, int color);

// draw_gradient_lines.c
void	draw_gradient_line(t_mlx *mlx, int *p1, int *p2, int *colors);

// draw_basic_shapes
int		draw_rectangle(t_img *img, int *top_left, int *bot_right, int color);

// check_map.c
int		check_map(char *file);

// count_lines_and_ppl.c
int		count_lines_and_ppl(char *file, int *lines, int *ppl);

// print_map.c
int		print_map2(t_mlx *mlx, t_coo *coo, t_print *print);
int		print_map(t_mlx *mlx, char *file);

// s_coo.c
int		coo_init(t_coo **coo, int lines, int points_per_line);
void	coo_destroy(t_coo *coo);
int		fill_points(char *file, t_coo *coo);

// s_print.c
int		print_init(t_print **print);
void	calculate_img_size(t_mlx *mlx, t_coo *coo, t_print *print);

// win_key_handler.c
int		win_key_handler(int keycode, t_hook *hook);

// zoom.c
void	zoom_in(t_hook *hook);
void	zoom_out(t_hook *hook);
int		change_offset(int keycode, t_hook *hook);

// change_map.c
void	re_print(t_hook *hook);
void	change_alt_coef(int keycode, t_hook *hook);

// utils.c
int		is_fdf_char(char c);
int		is_fdf_value(char c);
int		atoi_fd(int fd, char *c);
int		hexa_atoi_fd(int fd, char *c);

#endif
