/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:20:25 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:04:22 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "scene.h"

int	init_objects(t_scn_el_lst **lst, t_scn_obj **objs)
{
	t_scn_el_lst	*current;

	*objs = NULL;
	if (lst == NULL || *lst == NULL)
		return (err(1, "Empty element list\n"));
	current = *lst;
	while (current)
	{
		if (add_obj(current, objs))
			return (1);
		current = current->next;
	}
	printf("\nobjs\n");
	print_objects(objs);
	printf("\n\n");
	return (0);
}

int	add_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	if (!ft_strncmp(el->id, "sp", 2))
		return (add_sp_obj(el, objs));
	if (!ft_strncmp(el->id, "cy", 2))
		return (add_cy_obj(el, objs));
	return (err(1, "add_obj():\nUnknow identifier received\n"));
}

int	add_a_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	obj->type = A;
	obj->data = init_a_data(el);
	if (obj->data == NULL)
	{
		free(obj);
		delete_objs(objs);
		return (1);
	}
	append_obj(objs, obj);
	return (0);
}

int	add_c_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	obj->type = C;
	obj->data = init_c_data(el);
	if (obj->data == NULL)
	{
		free(obj);
		delete_objs(objs);
		return (1);
	}
	append_obj(objs, obj);
	return (0);
}

int	add_l_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	obj->type = L;
	obj->data = init_l_data(el);
	if (obj->data == NULL)
	{
		free(obj);
		delete_objs(objs);
		return (1);
	}
	append_obj(objs, obj);
	return (0);
}
