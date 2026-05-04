/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:26:17 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:19:21 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "cone_bonus.h"

/*	if ray intersect an obj: set ray.hit to closest obj, ret face
 *	else: ret 0
 */
int	objects_intersect(t_ray *ray, t_bvhnode *node, float *t, void *self)
{
	float	t_obj;
	int		face;
	int		i;
	bool	hit;

	hit = 0;
	i = -1;
	while (++i < node->object_count)
	{
		if (self && node->objs[i]->data == self)
			continue ;
		t_obj = INFINITY;
		face = redirect_intersect_type_ft(node, ray, &t_obj, i);
		if (t_obj < *t)
		{
			*t = t_obj;
			ray->hit = node->objs[i]->data;
			ray->type = node->objs[i]->type;
			ray->face = face;
			hit = 1;
		}
	}
	if (hit && *t < INFINITY)
		return (1);
	return (0);
}

int	redirect_intersect_type_ft(t_bvhnode *node, t_ray *ray, float *t_obj, int i)
{
	if (node->objs[i]->type == SP)
		return (ray_sphere_intersect(ray, node->objs[i]->data, t_obj));
	else if (node->objs[i]->type == CY)
		return (ray_cylinder_full_intersect(ray, node->objs[i]->data, t_obj));
	else if (node->objs[i]->type == CN)
		return (ray_cone_full_intersect_bonus(ray, node->objs[i]->data, t_obj));
	return (0);
}
