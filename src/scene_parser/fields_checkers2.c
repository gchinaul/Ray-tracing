/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_checkers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:45:31 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:01:10 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_cy_fields(t_scn_el_lst *node)
{
	int	len;

	len = arr_len((void *)node->data);
	if (len != 6)
		return (err(1, "Error\ncy: Wrong argument count (6)\n"));
	if (!is_coo_format(node->data[1]))
		return (err_coo_format(1, node->id, node->data[1]));
	if (!is_orientation_format(node->data[2]))
		return (err_orientation_format(1, node->id, node->data[2]));
	if (!is_length_format(node->data[3]))
		return (err_length_format(1, node->id, node->data[3]));
	if (!is_length_format(node->data[4]))
		return (err_length_format(1, node->id, node->data[4]));
	if (!is_rgb_format(node->data[5]))
		return (err_rgb_format(1, node->id, node->data[5]));
	return (0);
}
