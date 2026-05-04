/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 16:58:58 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/10 13:28:54 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	cam_xz_translation(t_camera *cam, int keycode)
{
	t_vec3		move_vec;
	float		move_speed;
	t_vec3		right_vec;

	move_speed = 1.0f;
	if (keycode == KEY_S || keycode == KEY_A)
		move_speed = -move_speed;
	if (keycode == KEY_W || keycode == KEY_S)
		move_vec = scalar_mult(&cam->orientation, move_speed);
	else
	{
		right_vec = calculate_right_vector(cam);
		move_vec = scalar_mult(&right_vec, move_speed);
	}
	cam->coo = add(&cam->coo, &move_vec);
}

void	handle_camera_movement(t_rt *data, int keycode)
{
	t_camera	*cam;

	cam = data->scn.cam;
	if (!cam)
		return ;
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D)
		cam_xz_translation(cam, keycode);
	else if (keycode == KEY_F || keycode == KEY_G)
		vec3_y_translation(&cam->coo, keycode);
}
