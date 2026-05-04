/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 15:22:15 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:10:35 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_objects(t_scn_obj **lst)
{
	t_scn_obj	*current;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	while (current)
	{
		print_id(current->type);
		print_data(current);
		current = current->next;
	}
	printf("\n");
}

void	print_id(int type)
{
	if (type == A)
		write(1, "A\n", 2);
	else if (type == C)
		write(1, "C\n", 2);
	else if (type == L)
		write(1, "L\n", 2);
	else if (type == SP)
		write(1, "sp\n", 3);
	else if (type == PL)
		write(1, "pl\n", 3);
	else if (type == CY)
		write(1, "cy\n", 3);
}

void	print_data(t_scn_obj *node)
{
	if (node->type == A)
		print_a_data(node->data);
	else if (node->type == C)
		print_c_data(node->data);
	else if (node->type == L)
		print_l_data(node->data);
	else if (node->type == SP)
		print_sp_data(node->data);
	else if (node->type == PL)
		print_pl_data(node->data);
	else if (node->type == CY)
		print_cy_data(node->data);
}

void	print_a_data(t_amb_light *data)
{
	printf("\tlight_ratio: %.2f\n", data->light_ratio);
	printf("\trgb: %d,%d,%d\n",
		get_red(data->color), get_green(data->color), get_blue(data->color));
}

void	print_c_data(t_camera *data)
{
	printf("\tcoo: %.2f,%.2f,%.2f\n",
		data->coo.x, data->coo.y, data->coo.z);
	printf("\torientation: %.2f,%.2f,%.2f\n",
		data->orientation.x, data->orientation.y, data->orientation.z);
	printf("\tFOV: %d\n", data->fov_h);
}
