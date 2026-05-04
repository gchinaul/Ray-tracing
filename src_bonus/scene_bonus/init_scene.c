/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 12:28:17 by van               #+#    #+#             */
/*   Updated: 2025/09/05 08:17:12 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_scene(t_scn_el_lst **lst, t_scn *scn)
{
	t_scn_el_lst	*current;

	set_scn_attr_null(scn);
	if (lst == NULL || *lst == NULL)
		return (err(1, "Empty element list\n"));
	current = *lst;
	while (current)
	{
		if (process_current_el(current, scn))
			return (1);
		current = current->next;
	}
	return (0);
}

void	set_scn_attr_null(t_scn *scn)
{
	scn->amb = NULL;
	scn->cam = NULL;
	scn->lights = NULL;
	scn->objs = NULL;
	scn->planes = NULL;
	scn->cones = NULL;
	scn->arr = NULL;
	scn->bvh = NULL;
	scn->objs_count = 0;
	scn->objs = NULL;
}

bool	process_current_el(t_scn_el_lst *current, t_scn *scn)
{
	int	ret;

	ret = process_shape(current, scn);
	if (ret)
		return (ret > 0);
	if (!ft_strncmp(current->id, "A", 2))
	{
		scn->amb = init_a_data(current);
		if (scn->amb == NULL)
			return (true);
	}
	else if (!ft_strncmp(current->id, "C", 2))
	{
		scn->cam = init_c_data(current);
		if (scn->cam == NULL)
			return (true);
	}
	else if (!ft_strncmp(current->id, "L", 2))
	{
		if (add_light(current, &scn->lights))
			return (true);
	}
	else
		return (err(1, "Unknown object type in init_scene\n"));
	return (false);
}

int	process_shape(t_scn_el_lst *current, t_scn *scn)
{
	if (has_bounded_volume(current))
	{
		if (add_obj(current, &scn->objs))
			return (1);
		scn->objs_count++;
		return (-1);
	}
	else if (!ft_strncmp(current->id, "pl", 2))
	{
		if (add_plane(current, &scn->planes))
			return (1);
		return (-1);
	}
	return (0);
}

bool	has_bounded_volume(t_scn_el_lst *el)
{
	if (!ft_strncmp(el->id, "A", 2))
		return (false);
	if (!ft_strncmp(el->id, "C", 2))
		return (false);
	if (!ft_strncmp(el->id, "L", 2))
		return (false);
	if (!ft_strncmp(el->id, "pl", 2))
		return (false);
	return (true);
}
