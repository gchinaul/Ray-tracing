/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:04:27 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:41:47 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	sort_objects_by_axis(t_scn_obj **arr, int count, int axis)
{
	bool		swapped;
	int			i;
	t_scn_obj	*tmp;

	if (!arr || count < 2)
		return ;
	swapped = true;
	while (swapped)
	{
		swapped = false;
		i = -1;
		while (++i < count - 1)
		{
			if (centroid_comparator(arr[i], arr[i + 1], axis) > 0)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				swapped = true;
			}
		}
	}
}

void	swap_nodes(t_scn_obj *a, t_scn_obj *b)
{
	t_scn_obj	*temp_prev;
	t_scn_obj	*temp_next;

	if (!a || !b)
		return ;
	temp_prev = a->prev;
	temp_next = b->next;
	if (temp_prev)
		temp_prev->next = b;
	if (temp_next)
		temp_next->prev = a;
	a->next = temp_next;
	b->prev = temp_prev;
	a->prev = b;
	b->next = a;
}
