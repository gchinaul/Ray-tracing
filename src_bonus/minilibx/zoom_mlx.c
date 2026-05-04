/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 13:00:59 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/10 13:26:39 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	handle_zoom(t_rt *data, int keycode, bool *re_print)
{
	t_camera	*cam;

	cam = data->scn.cam;
	if (!cam)
		return ;
	if (keycode == KEY_PLUS)
	{
		if (cam->fov_h > 10)
		{
			cam->fov_h -= 5;
			printf("Zoom in - FOV: %d\n", cam->fov_h);
			*re_print = true;
		}
	}
	else if (keycode == KEY_MINUS)
	{
		if (cam->fov_h < 170)
		{
			cam->fov_h += 5;
			printf("Zoom out - FOV: %d\n", cam->fov_h);
			*re_print = true;
		}
	}
}
