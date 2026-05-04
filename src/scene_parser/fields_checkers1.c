/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_checkers1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:40:21 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:01:12 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//	Contains a specific field checker for each type of valid scn obj

int	check_a_fields(t_scn_el_lst *node)
{
	if (arr_len((void *)node->data) != 3)
		return (err(1, "Error\nA: Wrong argument count (3)\n"));
	if (!is_dot_format_in_range_1(node->data[1]))
		return (err_dot_format_in_range_1(1, node->id, node->data[1]));
	if (!is_rgb_format(node->data[2]))
		return (err_rgb_format(1, node->id, node->data[2]));
	return (0);
}

int	check_c_fields(t_scn_el_lst *node)
{
	if (arr_len((void *)node->data) != 4)
		return (err(1, "Error\nC: Wrong argument count (4)\n"));
	if (!is_coo_format(node->data[1]))
		return (err_coo_format(1, node->id, node->data[1]));
	if (!is_orientation_format(node->data[2]))
		return (err_orientation_format(1, node->id, node->data[2]));
	if (!is_fov_format(node->data[3]))
	{
		write(2, "Error\nC: ", 9);
		write(2, node->data[3], ft_strlen(node->data[3]));
		write(2, ": Wrong FOV format or value ", 28);
		return (err(1, "([nn]n [0,180])\n"));
	}
	return (0);
}

int	check_l_fields(t_scn_el_lst *node)
{
	if (arr_len((void *)node->data) != 4)
		return (err(1, "Error\nL: Wrong argument count (4)\n"));
	if (!is_coo_format(node->data[1]))
		return (err_coo_format(1, node->id, node->data[1]));
	if (!is_dot_format_in_range_1(node->data[2]))
		return (err_dot_format_in_range_1(1, node->id, node->data[2]));
	if (!is_rgb_format(node->data[3]))
		return (err_rgb_format(1, node->id, node->data[3]));
	return (0);
}

int	check_sp_fields(t_scn_el_lst *node)
{
	int	len;

	len = arr_len((void *)node->data);
	if (len != 4)
		return (err(1, "Error\nsp: Wrong argument count (9/12)\n"));
	if (!is_coo_format(node->data[1]))
		return (err_coo_format(1, node->id, node->data[1]));
	if (!is_length_format(node->data[2]))
		return (err_length_format(1, node->id, node->data[2]));
	if (!is_rgb_format(node->data[3]))
		return (err_rgb_format(1, node->id, node->data[3]));
	return (0);
}

int	check_pl_fields(t_scn_el_lst *node)
{
	int	len;

	len = arr_len((void *)node->data);
	if (len != 4)
		return (err(1, "Error\npl: Wrong argument count (4)\n"));
	if (!is_coo_format(node->data[1]))
		return (err_coo_format(1, node->id, node->data[1]));
	if (!is_orientation_format(node->data[2]))
		return (err_orientation_format(1, node->id, node->data[2]));
	if (!is_rgb_format(node->data[3]))
		return (err_rgb_format(1, node->id, node->data[3]));
	return (0);
}
