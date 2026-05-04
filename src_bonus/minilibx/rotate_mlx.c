/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mlx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:03:24 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/10 13:27:56 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	rotate_vector(t_vec3 *vec, t_vec3 *axis, float angle)
{
	t_vec3	result;
	float	cos_sin[2];
	float	dot_product;
	t_vec3	cross_product;
	t_vec3	tmp[3];

	cos_sin[0] = cos(angle);
	cos_sin[1] = sin(angle);
	dot_product = dot(vec, axis);
	cross_product = cross(axis, vec);
	tmp[0] = scalar_mult(vec, cos_sin[0]);
	tmp[1] = scalar_mult(&cross_product, cos_sin[1]);
	tmp[2] = scalar_mult(axis, dot_product * (1 - cos_sin[0]));
	result = add(&tmp[0], &tmp[1]);
	result = add(&result, &tmp[2]);
	return (result);
}

void	cam_y_rot(int keycode, t_camera *cam)
{
	float	rotation_speed;
	t_vec3	up_vec;

	rotation_speed = 0.1f;
	up_vec = (t_vec3){0, 1, 0};
	if (keycode == KEY_LEFT)
	{
		rotation_speed = -rotation_speed;
		printf("Camera rotated left\n");
	}
	else
		printf("Camera rotated right\n");
	cam->orientation = rotate_vector(&cam->orientation, &up_vec,
			rotation_speed);
	normalize(&cam->orientation);
}

void	cam_vert_rot(int keycode, t_camera *cam)
{
	float	rotation_speed;
	t_vec3	right_vec;

	rotation_speed = 0.1f;
	right_vec = calculate_right_vector(cam);
	if (keycode == KEY_UP)
	{
		rotation_speed = -rotation_speed;
		printf("Camera rotated up\n");
	}
	else
		printf("Camera rotated down\n");
	cam->orientation = rotate_vector(&cam->orientation, &right_vec,
			rotation_speed);
	normalize(&cam->orientation);
}

void	handle_camera_rotation(t_rt *data, int keycode)
{
	t_camera	*cam;

	cam = data->scn.cam;
	if (!cam)
		return ;
	if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		cam_y_rot(keycode, cam);
	else if (keycode == KEY_DOWN || keycode == KEY_UP)
		cam_vert_rot(keycode, cam);
}

t_vec3	calculate_right_vector(t_camera *cam)
{
	t_vec3	vec_global_up;
	t_vec3	right;

	if (fabs(cam->orientation.y) > 0.99)
		vec_global_up = (t_vec3){1, 0, 0};
	else
		vec_global_up = (t_vec3){0, 1, 0};
	right = cross(&vec_global_up, &cam->orientation);
	normalize(&right);
	return (right);
}
