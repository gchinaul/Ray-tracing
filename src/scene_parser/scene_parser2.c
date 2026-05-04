/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:01:32 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:02:01 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// check .rt requirements, set id to data[0]
int	check_data(t_scn_el_lst **lst)
{
	t_scn_el_lst	*current;

	if (lst == NULL || *lst == NULL)
		return (err(1, "Error\nThe provided map is empty\n"));
	current = *lst;
	while (current)
	{
		current->id = current->data[0];
		if (!is_valid_data(current))
			return (1);
		current = current->next;
	}
	if (check_number(lst))
		return (1);
	return (0);
}

// check .rt requirements for a specific node
int	is_valid_data(t_scn_el_lst *node)
{
	if (check_id(node))
		return (0);
	if (check_fields(node))
		return (0);
	return (1);
}

// check if id is allowed
int	check_id(t_scn_el_lst *node)
{
	if (ft_strlen(node->id) > 2)
	{
		write(2, "Error\n", 6);
		write(2, node->id, ft_strlen(node->id));
		return (err(1, ": Invalid identifier, max length = 2\n"));
	}
	if (!is_valid_id(node->id))
	{
		write(2, "Error\n", 6);
		write(2, node->id, ft_strlen(node->id));
		return (err(1, ": Invalid identifier, not handled\n"));
	}
	return (0);
}

// contain all valid ids, return 1 if s match one
int	is_valid_id(char *s)
{
	if (!ft_strncmp(s, "A", 2) || !ft_strncmp(s, "L", 2) || !ft_strncmp(s, "C",
			2) || !ft_strncmp(s, "sp", 2) || !ft_strncmp(s, "pl", 2)
		|| !ft_strncmp(s, "cy", 2))
		return (1);
	return (0);
}

// redirect to the needed check_fields ft
int	check_fields(t_scn_el_lst *node)
{
	if (!ft_strncmp(node->id, "A", 2))
		return (check_a_fields(node));
	if (!ft_strncmp(node->id, "C", 2))
		return (check_c_fields(node));
	if (!ft_strncmp(node->id, "L", 2))
		return (check_l_fields(node));
	if (!ft_strncmp(node->id, "sp", 2))
		return (check_sp_fields(node));
	if (!ft_strncmp(node->id, "pl", 2))
		return (check_pl_fields(node));
	if (!ft_strncmp(node->id, "cy", 2))
		return (check_cy_fields(node));
	return (err(1, "Error\ncheck_fields: Invalid identifier received\n"));
}
