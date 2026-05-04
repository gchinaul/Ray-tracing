/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 11:35:00 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:23:02 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// returns a ptr to the first occurence of type from objs
t_scn_obj	*get_obj(t_scn_obj *objs, t_obj_type type)
{
	if (objs == NULL)
		return (NULL);
	while (objs)
	{
		if (objs->type == type)
			return (objs);
		objs = objs->next;
	}
	return (NULL);
}
