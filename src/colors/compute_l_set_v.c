/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_l_set_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:07:39 by van               #+#    #+#             */
/*   Updated: 2025/09/10 17:13:56 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_l_set_v(t_compute_l *v, t_ray *ray)
{
	v->point = &ray->point;
	v->obj_data = ray->hit;
	v->ka = REFLEXION_COEF;
	v->kd = DIFFUSE_COEF;
	if (ray->type == SP)
		compute_l_set_v_sp(v, (t_sphere *)ray->hit);
	else if (ray->type == PL)
		compute_l_set_v_pl(v, (t_plane *)ray->hit);
	else if (ray->type == CY)
		compute_l_set_v_cy(v, (t_cylinder *)ray->hit);
}

void	compute_l_set_v_sp(t_compute_l *v, t_sphere *sp)
{
	v->type = SP;
	v->obj_rgb = &sp->rgb;
}

void	compute_l_set_v_pl(t_compute_l *v, t_plane *pl)
{
	v->type = PL;
	v->obj_rgb = &pl->rgb;
}

void	compute_l_set_v_cy(t_compute_l *v, t_cylinder *cy)
{
	v->type = CY;
	v->obj_rgb = &cy->rgb;
}
