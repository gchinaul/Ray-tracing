/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fields_checkers_cone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/05 07:48:30 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "miniRT.h"

// co <coo> <orient> <diameter> <height> <rgb>
// 		<ka> <kd> <ks> <pe> <kr> [<bmap_name> <scale> <intensity>]
// node->data[3] // diameter
// node->data[4] // height
int	check_co_fields(t_scn_el_lst *node)
{
	int	len;

	len = arr_len((void *)node->data);
	if (len != 6 + 5 && len != 6 + 5 + 3)
		return (err(1, "Error\nco: Wrong argument count (11/14)\n"));
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
	if (check_fields_lighting(node, 6))
		return (1);
	if (len == 6 + 5)
		return (0);
	if (check_fields_texture(node, 12))
		return (1);
	return (0);
}
