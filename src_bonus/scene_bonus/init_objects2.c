/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:19:43 by van               #+#    #+#             */
/*   Updated: 2025/09/05 11:57:48 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	add_sp_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	obj->type = SP;
	obj->data = init_sp_data(el);
	if (obj->data == NULL)
	{
		free(obj);
		delete_objs(objs);
		return (1);
	}
	obj->bbox = compute_sphere_aabb(obj->data);
	append_obj(objs, obj);
	return (0);
}

int	add_cy_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	obj->type = CY;
	obj->data = init_cy_data(el);
	if (obj->data == NULL)
	{
		free(obj);
		delete_objs(objs);
		return (1);
	}
	obj->bbox = compute_cylinder_aabb_safe(obj->data);
	append_obj(objs, obj);
	return (0);
}
