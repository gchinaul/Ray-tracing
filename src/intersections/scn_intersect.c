/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_intersect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:33:18 by van               #+#    #+#             */
/*   Updated: 2025/09/12 15:28:16 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	scn_intersect(t_rt *rt, t_ray *ray, float *t_min, void *self)
{
	planes_intersect(ray, rt->scn.planes, t_min, self);
	objs_intersect(rt, ray, t_min, self);
}

void	update_ray(t_ray *ray, t_scn_obj *current, int face)
{
	ray->type = current->type;
	ray->hit = current->data;
	ray->face = face;
}

void	objs_intersect(t_rt *rt, t_ray *ray, float *t_min, void *self)
{
	t_scn_obj	*current;
	float		t;
	int			face;

	current = rt->scn.objs;
	while (current)
	{
		if (current->data == self)
		{
			current = current->next;
			continue ;
		}
		t = INFINITY;
		if (current->type == SP)
			face = ray_sphere_intersect(ray, current->data, &t);
		else if (current->type == CY)
			face = ray_cylinder_full_intersect(ray, current->data, &t);
		if (t < *t_min)
		{
			update_ray(ray, current, face);
			*t_min = t;
		}
		current = current->next;
	}
}
