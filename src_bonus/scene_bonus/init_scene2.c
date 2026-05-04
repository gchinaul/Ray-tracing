/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:14:15 by van               #+#    #+#             */
/*   Updated: 2025/09/05 12:00:27 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_light(t_scn_el_lst *el, t_light **lights)
{
	t_light	*current;
	t_light	*new;

	new = init_l_data(el);
	if (new == NULL)
		return (1);
	if (*lights == NULL)
		*lights = new;
	else
	{
		current = *lights;
		while (current->next)
		{
			current = current->next;
		}
		current->next = new;
		new->prev = current;
	}
	return (0);
}

int	add_plane(t_scn_el_lst *el, t_plane **planes)
{
	t_plane	*current;
	t_plane	*new;

	new = init_pl_data(el);
	if (new == NULL)
		return (1);
	set_pl_uv_axes(new);
	if (*planes == NULL)
		*planes = new;
	else
	{
		current = *planes;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	return (0);
}

int	add_cone(t_scn_el_lst *el, t_cone **cones)
{
	t_cone	*current;
	t_cone	*new;

	new = init_co_data(el);
	if (new == NULL)
		return (1);
	if (*cones == NULL)
		*cones = new;
	else
	{
		current = *cones;
		while (current->next)
			current = current->next;
		current->next = new;
		new->prev = current;
	}
	return (0);
}
