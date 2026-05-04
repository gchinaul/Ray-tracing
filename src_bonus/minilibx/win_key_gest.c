/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_key_gest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:42:14 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/10 14:23:02 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	win_key_handler_exit(int keycode, t_hook *hook)
{
	if (keycode == KEY_ESC)
	{
		mlx_loop_end(hook->mlx->mlx);
		return (1);
	}
	if (!hook->extra_data)
		return (1);
	return (0);
}

int	win_key_handler(int keycode, t_hook *hook)
{
	t_rt	*data;
	bool	re_print;

	re_print = 0;
	if (win_key_handler_exit(keycode, hook))
		return (0);
	data = (t_rt *)hook->extra_data;
	if (keycode == KEY_U || keycode == KEY_I
		|| keycode == KEY_O || keycode == KEY_P)
		change_selected_type(data, keycode);
	else if (keycode == KEY_W || keycode == KEY_S || keycode == KEY_A
		|| keycode == KEY_D || keycode == KEY_F || keycode == KEY_G)
		handle_translations(data, keycode, &re_print);
	else if (keycode == KEY_LEFT || keycode == KEY_RIGHT || keycode == KEY_UP
		|| keycode == KEY_DOWN)
		handle_rotation(data, keycode, &re_print);
	else if (keycode == KEY_PLUS || keycode == KEY_MINUS)
		handle_zoom(data, keycode, &re_print);
	else if (keycode == KEY_R || keycode == KEY_T)
		change_selected(data, keycode);
	else
		printf("Key pressed: %d\n", keycode);
	if (re_print)
		render_img(data);
	return (0);
}

void	redo_bvh(t_rt *rt)
{
	delete_bvh(rt->bvh);
	free(rt->scn.arr);
	rt->bvh = init_bvh(&rt->scn, rt->scn.objs_count);
}

void	handle_rotation(t_rt *rt, int keycode, bool *re_print)
{
	if (rt->selected.type == CAM)
	{
		handle_camera_rotation(rt, keycode);
		*re_print = true;
	}
	else if (rt->selected.type == OBJS)
	{
		if (rt->selected.objs->type == CY)
		{
			*re_print = handle_cy_rotation
				((t_cylinder *)rt->selected.objs->data, keycode);
			if (*re_print)
			{
				rt->selected.objs->bbox = compute_cylinder_aabb_safe
					((t_cylinder *)rt->selected.objs->data);
				redo_bvh(rt);
			}
		}
	}
	else if (rt->selected.type == PLANES)
	{
		*re_print = handle_pl_rotation((t_plane *)rt->selected.planes, keycode);
		if (*re_print)
			set_pl_uv_axes(rt->selected.planes);
	}
}

void	print_obj_type(t_rt *rt)
{
	if (rt->selected.type == CAM)
		ft_printf("C\n");
	else if (rt->selected.type == LIGHTS)
		ft_printf("L\n");
	else if (rt->selected.type == OBJS)
	{
		if (rt->selected.objs->type == SP)
			ft_printf("sp\n");
		else if (rt->selected.objs->type == CY)
			ft_printf("cy\n");
	}
	else if (rt->selected.type == PLANES)
		ft_printf("pl\n");
}
