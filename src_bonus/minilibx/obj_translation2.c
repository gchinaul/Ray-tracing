/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_translation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:53:45 by van               #+#    #+#             */
/*   Updated: 2025/09/10 12:54:51 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	handle_pl_translations(t_plane *pl, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S)
		return (vec3_z_translation(&pl->coo, keycode));
	if (keycode == KEY_A || keycode == KEY_D)
		return (vec3_x_translation(&pl->coo, keycode));
	if (keycode == KEY_G || keycode == KEY_F)
		return (vec3_y_translation(&pl->coo, keycode));
	return (0);
}

int	handle_cy_translations(t_cylinder *cy, int keycode)
{
	if (keycode == KEY_W || keycode == KEY_S)
		return (vec3_z_translation(&cy->coo, keycode));
	if (keycode == KEY_A || keycode == KEY_D)
		return (vec3_x_translation(&cy->coo, keycode));
	if (keycode == KEY_G || keycode == KEY_F)
		return (vec3_y_translation(&cy->coo, keycode));
	return (0);
}

void	handle_translations(t_rt *rt, int keycode, bool *re_print)
{
	if (rt->selected.type == CAM)
	{
		handle_camera_movement(rt, keycode);
		*re_print = true;
	}
	else if (rt->selected.type == LIGHTS)
		*re_print = handle_light_translations(rt->selected.lights, keycode);
	else if (rt->selected.type == OBJS)
		objs_translations(rt, keycode, re_print);
	else if (rt->selected.type == PLANES)
		*re_print = handle_pl_translations((t_plane *)rt->selected.planes,
				keycode);
}

void	objs_translations(t_rt *rt, int keycode, bool *re_print)
{
	if (rt->selected.objs->type == SP)
	{
		*re_print = handle_sp_translations((t_sphere *)rt->selected.objs->data,
				keycode);
		if (*re_print)
		{
			rt->selected.objs->bbox
				= compute_sphere_aabb((t_sphere *)rt->selected.objs->data);
			redo_bvh(rt);
		}
	}
	else if (rt->selected.objs->type == CY)
	{
		*re_print = handle_cy_translations
			((t_cylinder *)rt->selected.objs->data, keycode);
		if (*re_print)
		{
			rt->selected.objs->bbox = compute_cylinder_aabb_safe
				((t_cylinder *)rt->selected.objs->data);
			redo_bvh(rt);
		}
	}
}
