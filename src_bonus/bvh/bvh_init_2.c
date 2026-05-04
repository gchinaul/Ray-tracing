/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_init_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:10:36 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:19:52 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Sorts objects by centroid position on given axis (-1/0/1 for qsort)
 */
int	centroid_comparator(t_scn_obj *a, t_scn_obj *b, int axis)
{
	float	ca;
	float	cb;

	if (axis == 0)
	{
		ca = (a->bbox.min.x + a->bbox.max.x) * 0.5f;
		cb = (b->bbox.min.x + b->bbox.max.x) * 0.5f;
	}
	else if (axis == 1)
	{
		ca = (a->bbox.min.y + a->bbox.max.y) * 0.5f;
		cb = (b->bbox.min.y + b->bbox.max.y) * 0.5f;
	}
	else
	{
		ca = (a->bbox.min.z + a->bbox.max.z) * 0.5f;
		cb = (b->bbox.min.z + b->bbox.max.z) * 0.5f;
	}
	return ((ca > cb) - (ca < cb));
}
