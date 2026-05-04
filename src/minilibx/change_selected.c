/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_selected.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 12:50:48 by van               #+#    #+#             */
/*   Updated: 2025/09/10 14:27:42 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	change_selected(t_rt *rt, int keycode)
{
	if (rt->selected.type == LIGHTS)
		change_selected_light(rt, keycode);
	else if (rt->selected.type == OBJS)
		change_selected_objs(rt, keycode);
	else if (rt->selected.type == PLANES)
		change_selected_plane(rt, keycode);
	ft_printf("Selected object: ");
	print_obj_type(rt);
}

void	change_selected_light(t_rt *rt, int keycode)
{
	if (keycode == KEY_R)
	{
		if (rt->selected.lights->prev)
			rt->selected.lights = rt->selected.lights->prev;
		else
		{
			while (rt->selected.lights->next)
				rt->selected.lights = rt->selected.lights->next;
		}
	}
	else if (keycode == KEY_T)
	{
		if (rt->selected.lights->next)
			rt->selected.lights = rt->selected.lights->next;
		else
		{
			while (rt->selected.lights->prev)
				rt->selected.lights = rt->selected.lights->prev;
		}
	}
}

void	change_selected_plane(t_rt *rt, int keycode)
{
	if (keycode == KEY_R)
	{
		if (rt->selected.planes->prev)
			rt->selected.planes = rt->selected.planes->prev;
		else
		{
			while (rt->selected.planes->next)
				rt->selected.planes = rt->selected.planes->next;
		}
	}
	else if (keycode == KEY_T)
	{
		if (rt->selected.planes->next)
			rt->selected.planes = rt->selected.planes->next;
		else
		{
			while (rt->selected.planes->prev)
				rt->selected.planes = rt->selected.planes->prev;
		}
	}
}

void	change_selected_objs(t_rt *rt, int keycode)
{
	if (keycode == KEY_R)
	{
		if (rt->selected.objs->prev)
			rt->selected.objs = rt->selected.objs->prev;
		else
		{
			while (rt->selected.objs->next)
				rt->selected.objs = rt->selected.objs->next;
		}
	}
	else if (keycode == KEY_T)
	{
		if (rt->selected.objs->next)
			rt->selected.objs = rt->selected.objs->next;
		else
		{
			while (rt->selected.objs->prev)
				rt->selected.objs = rt->selected.objs->prev;
		}
	}
}

void	change_selected_type(t_rt *rt, int keycode)
{
	if (keycode == KEY_U)
		rt->selected.type = CAM;
	else if (keycode == KEY_I)
	{
		if (rt->selected.lights)
			rt->selected.type = LIGHTS;
		else
			printf("no light available\n");
	}
	else if (keycode == KEY_O)
	{
		if (rt->selected.objs)
			rt->selected.type = OBJS;
		else
			printf("no object available\n");
	}
	else if (keycode == KEY_P)
	{
		if (rt->selected.planes)
			rt->selected.type = PLANES;
		else
			printf("no plane available\n");
	}
	ft_printf("Selected object: ");
	print_obj_type(rt);
}
