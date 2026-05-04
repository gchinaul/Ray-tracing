/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_bvh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:21:54 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bvh.h"
#include "miniRT.h"

bool	intersect_bvh(t_aabb bbox, t_ray *ray)
{
	float	bounds[2];
	int		a;

	bounds[0] = 0.0f;
	bounds[1] = INFINITY;
	a = 0;
	while (a < 3)
	{
		if (!check_axis_intersection(bbox, ray, a, bounds))
			return (false);
		a++;
	}
	return (true);
}
