/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_l_set_v.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 10:07:39 by van               #+#    #+#             */
/*   Updated: 2025/09/05 10:08:25 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	compute_l_set_v(t_compute_l *v, t_ray *ray)
{
	v->point = &ray->point;
	v->obj_data = ray->hit;
	if (ray->type == SP)
		compute_l_set_v_sp(v, (t_sphere *)ray->hit);
	else if (ray->type == PL)
		compute_l_set_v_pl(v, (t_plane *)ray->hit);
	else if (ray->type == CY)
		compute_l_set_v_cy(v, (t_cylinder *)ray->hit);
	else if (ray->type == CN)
		compute_l_set_v_co(v, (t_cone *)ray->hit);
}

void	compute_l_set_v_sp(t_compute_l *v, t_sphere *sp)
{
	v->type = SP;
	v->obj_rgb = &sp->rgb;
	v->ka = sp->ka;
	v->kd = sp->kd;
	v->ks = sp->ks;
	v->pe = sp->pe;
}

void	compute_l_set_v_pl(t_compute_l *v, t_plane *pl)
{
	v->type = PL;
	v->obj_rgb = &pl->rgb;
	v->ka = pl->ka;
	v->kd = pl->kd;
	v->ks = pl->ks;
	v->pe = pl->pe;
}

void	compute_l_set_v_cy(t_compute_l *v, t_cylinder *cy)
{
	v->type = CY;
	v->obj_rgb = &cy->rgb;
	v->ka = cy->ka;
	v->kd = cy->kd;
	v->ks = cy->ks;
	v->pe = cy->pe;
}

void	compute_l_set_v_co(t_compute_l *v, t_cone *co)
{
	v->type = CN;
	v->obj_rgb = &co->rgb;
	v->ka = co->ka;
	v->kd = co->kd;
	v->ks = co->ks;
	v->pe = co->pe;
}
