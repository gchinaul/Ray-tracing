/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:23:57 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:06:46 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	append_obj(t_scn_obj **lst, t_scn_obj *node)
{
	t_scn_obj	*current;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = node;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
}

t_scn_obj	*new_obj(void)
{
	t_scn_obj	*new_node;

	new_node = malloc(sizeof(t_scn_obj));
	if (new_node == NULL)
		return (NULL);
	set_obj_attr_null(new_node);
	return (new_node);
}

void	set_obj_attr_null(t_scn_obj *node)
{
	node->data = NULL;
	node->next = NULL;
	node->prev = NULL;
	node->type = -1;
}

void	delete_objs(t_scn_obj **objs)
{
	t_scn_obj	*current;
	t_scn_obj	*tmp;

	if (objs == NULL)
		return ;
	current = *objs;
	while (current)
	{
		if (current->data)
			free(current->data);
		tmp = current;
		current = current->next;
		free(tmp);
	}
	*objs = NULL;
}
