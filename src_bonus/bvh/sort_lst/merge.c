/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:05:31 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:55:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* MergeSort récursif - O(n log n) */
t_scn_obj	*merge_sort(t_scn_obj *head, int axis)
{
	t_scn_obj	*slow;
	t_scn_obj	*fast;
	t_scn_obj	*mid;

	if (!head || !head->next)
		return (head);
	slow = head;
	fast = head->next;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	mid = slow->next;
	slow->next = NULL;
	return (merge(
			merge_sort(head, axis),
			merge_sort(mid, axis),
			axis
		));
}

void	set_next(t_scn_obj *tail, t_scn_obj *a, t_scn_obj *b)
{
	if (!a)
		tail->next = b;
	if (tail->next)
		tail->next->prev = tail;
}

/* Fusionne deux listes triées */
t_scn_obj	*merge(t_scn_obj *a, t_scn_obj *b, int axis)
{
	t_scn_obj	dummy;
	t_scn_obj	*tail;

	tail = &dummy;
	while (a && b)
	{
		if (centroid_comparator(a, b, axis) <= 0)
		{
			tail->next = a;
			a->prev = tail;
			a = a->next;
		}
		else
		{
			tail->next = b;
			b->prev = tail;
			b = b->next;
		}
		tail = tail->next;
	}
	tail->next = a;
	set_next(tail, a, b);
	return (dummy.next);
}

/* Point d'entrée */
void	sort_list(t_scn_obj **head, int axis)
{
	*head = merge_sort(*head, axis);
	if (*head)
		(*head)->prev = NULL;
}
