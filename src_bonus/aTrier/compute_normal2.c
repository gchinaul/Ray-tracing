/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_normal2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 14:28:00 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "cone_bonus.h"

bool	set_co_texture_data(t_ray *ray, float *u, float *v, t_bump_map **map)
{
	if (!((t_cone *)ray->hit)->bmap_name)
		return (true);
	*map = ((t_cone *)ray->hit)->bmap;
	ray->scale = ((t_cone *)ray->hit)->scale;
	ray->intensity = ((t_cone *)ray->hit)->intensity;
	cartesian_to_cone_bonus(ray, u, v, &ray->point);
	return (false);
}
