/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:10:33 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/08 09:51:22 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	print_tree_indent(int depth)
{
	int	i;

	i = 0;
	while (i < depth)
	{
		printf("  ");
		i++;
	}
}

static void	print_leaf_objects(t_bvhnode *node, int depth)
{
	int	j;
	int	k;

	k = 0;
	while (k < node->object_count)
	{
		j = 0;
		while (j < depth + 1)
		{
			printf("  ");
			j++;
		}
		printf("type: %d\n", node->objs[k]->type);
		k++;
	}
}

void	print_bvh_tree(t_bvhnode *node, int depth)
{
	print_tree_indent(depth);
	printf("(%d)\n", depth);
	if (node->is_leaf)
		print_leaf_objects(node, depth);
	if (node->left)
		print_bvh_tree(node->left, depth + 1);
	if (node->right)
		print_bvh_tree(node->right, depth + 1);
}

void	print_bvh(t_bvhnode *head)
{
	if (!head)
		printf("BVH is NULL\n");
	else
	{
		print_bvh_tree(head, 0);
		printf("\n\n");
	}
}

int	lst_size(t_scn_obj *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}
