/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scn_el_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:48:21 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:26:03 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	set_attr_null(t_scn_el_lst *node)
{
	node->next = NULL;
	node->data = NULL;
	node->id = NULL;
}

t_scn_el_lst	*new_node(void)
{
	t_scn_el_lst	*new_node;

	new_node = malloc (sizeof(t_scn_el_lst));
	if (new_node == NULL)
		return (err_malloc_null());
	set_attr_null(new_node);
	return (new_node);
}

int	append_node(t_scn_el_lst **lst, t_scn_el_lst *node)
{
	t_scn_el_lst	*current;

	if (lst == NULL)
		return (1);
	if (*lst == NULL)
	{
		*lst = node;
		return (0);
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = node;
	return (0);
}

void	delete_node(t_scn_el_lst **node)
{
	if (node == NULL || *node == NULL)
		return ;
	if ((*node)->data)
		free_split((*node)->data);
	free(*node);
	*node = NULL;
}

void	delete_lst(t_scn_el_lst **lst)
{
	t_scn_el_lst	*next;

	if (lst == NULL)
		return ;
	next = *lst;
	while (next)
	{
		next = (*lst)->next;
		delete_node(lst);
		*lst = next;
	}
	*lst = NULL;
}
