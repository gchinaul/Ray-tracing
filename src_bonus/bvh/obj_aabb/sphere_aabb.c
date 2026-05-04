/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_aabb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:06:08 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:22:58 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_aabb	compute_sphere_aabb(t_sphere *sp)
{
	t_aabb	bbox;
	float	r;

	r = sp->diameter / 2;
	bbox.min.x = sp->coo.x - r;
	bbox.min.y = sp->coo.y - r;
	bbox.min.z = sp->coo.z - r;
	bbox.max.x = sp->coo.x + r;
	bbox.max.y = sp->coo.y + r;
	bbox.max.z = sp->coo.z + r;
	return (bbox);
}
