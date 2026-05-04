/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_translations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 19:05:09 by van               #+#    #+#             */
/*   Updated: 2025/09/10 14:12:33 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// 100 => lim imposé au parsing
bool	vec3_z_translation(t_vec3 *coo, int keycode)
{
	float	move_speed;

	move_speed = 1.0f;
	if (keycode == KEY_W && coo->z + move_speed < 100)
	{
		coo->z += move_speed;
		return (1);
	}
	if (keycode == KEY_S && coo->z - move_speed > -100)
	{
		coo->z -= move_speed;
		return (1);
	}
	return (0);
}

bool	vec3_x_translation(t_vec3 *coo, int keycode)
{
	float	move_speed;

	move_speed = 1.0f;
	if (keycode == KEY_D && coo->x + move_speed < 100)
	{
		coo->x += move_speed;
		return (1);
	}
	if (keycode == KEY_A && coo->x - move_speed > -100)
	{
		coo->x -= move_speed;
		return (1);
	}
	return (0);
}

bool	vec3_y_translation(t_vec3 *coo, int keycode)
{
	float	move_speed;

	move_speed = 1.0f;
	if (keycode == KEY_G && coo->y + move_speed < 100)
	{
		coo->y += move_speed;
		return (1);
	}
	else if (keycode == KEY_F && coo->y - move_speed > -100)
	{
		coo->y -= move_speed;
		return (1);
	}
	return (0);
}

int	handle_light_translations(t_light *light, int keycode)
{
	if (light == NULL)
		return (0);
	if (keycode == KEY_W || keycode == KEY_S)
		return (vec3_z_translation(&light->coo, keycode));
	if (keycode == KEY_A || keycode == KEY_D)
		return (vec3_x_translation(&light->coo, keycode));
	if (keycode == KEY_G || keycode == KEY_F)
		return (vec3_y_translation(&light->coo, keycode));
	return (0);
}

int	handle_sp_translations(t_sphere *sp, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S)
		return (vec3_z_translation(&sp->coo, keycode));
	if (keycode == KEY_A || keycode == KEY_D)
		return (vec3_x_translation(&sp->coo, keycode));
	if (keycode == KEY_G || keycode == KEY_F)
		return (vec3_y_translation(&sp->coo, keycode));
	return (0);
}
