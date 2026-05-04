/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus_temp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 00:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:17:00 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "miniRT.h"

/*
** Fonctions temporaires pour le linking
*/
t_cone_hit	ray_cone_full_intersect_bonus(t_ray *ray, t_cone *cone,
		float *t_out)
{
	return (ray_cone_full_intersect(ray, cone, t_out));
}

bool	ray_cone_intersect_bonus(t_ray *ray, t_cone *cone, float *t_out)
{
	t_cone_hit	hit;

	hit = ray_cone_full_intersect(ray, cone, t_out);
	return (hit);
}
