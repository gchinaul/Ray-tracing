/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_co_obj.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:09:12 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/03 15:30:27 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone_bonus.h"
#include "miniRT.h"

int	add_co_obj(t_scn_el_lst *el, t_scn_obj **objs)
{
	t_scn_obj	*obj;

	obj = new_obj();
	if (obj == NULL)
		return (1);
	write(1, "Setting type to CN\n", 19);
	obj->type = CN;
	write(1, "Calling init_co_data\n", 21);
	obj->data = init_co_data(el);
	if (obj->data == NULL)
	{
		write(1, "init_co_data returned NULL\n", 27);
		free(obj);
		delete_objs(objs);
		return (1);
	}
	write(1, "init_co_data successful\n", 23);
	obj->bbox = compute_cone_aabb_bonus(obj->data);
	append_obj(objs, obj);
	return (0);
}
