/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 18:09:52 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:20:26 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*	faire en itérative pour perf?
 *	si précédemment calculé, passage de t_bbox de l'enfant au prochain appel
 * int	bvh_intersect(t_ray *ray, t_bvhnode *node, float *t, void *self,
 *		float skip)
 */
int	bvh_intersect(t_ray *ray, t_bvhnode *node, float *t, void **ss)
{
	float	tlr[2];
	float	t_bbox;

	if (!node || *(float *)(ss[1]) == -1.0f)
		return (0);
	if (*(float *)(ss[1]) == 0)
	{
		t_bbox = aabb_intersect(&node->bbox, ray);
		if (t_bbox < 0 || t_bbox >= *t)
			return (0);
	}
	else
		t_bbox = *(float *)(ss[1]);
	if (node->is_leaf)
		return (objects_intersect(ray, node, t, ss[0]));
	tlr[0] = aabb_intersect(&node->left->bbox, ray);
	tlr[1] = aabb_intersect(&node->right->bbox, ray);
	if ((tlr[0] < 0 || tlr[0] > *t) && (tlr[1] < 0 || tlr[1] > *t))
		return (0);
	if (!(tlr[0] < 0 || tlr[0] > *t) && !(tlr[1] < 0 || tlr[1] > *t)
		&& aabb_overlap(&node->left->bbox, &node->right->bbox))
		bvh_search_overlap(node, ray, (float *[3]){t, &tlr[0], &tlr[1]}, ss[0]);
	else
		bvh_search(node, ray, (float *[3]){t, &tlr[0], &tlr[1]}, ss[0]);
	return (0);
}

bool	bvh_search(t_bvhnode *node, t_ray *ray, float **t_t_left_t_right,
			void *self)
{
	if (*t_t_left_t_right[1] < *t_t_left_t_right[2])
	{
		if (bvh_intersect(ray, node->left, t_t_left_t_right[0],
				(void *[2]){self, t_t_left_t_right[1]}))
			return (1);
		return (bvh_intersect(ray, node->right, t_t_left_t_right[0],
				(void *[2]){self, t_t_left_t_right[2]}));
	}
	if (bvh_intersect(ray, node->right, t_t_left_t_right[0],
			(void *[2]){self, t_t_left_t_right[2]}))
		return (1);
	return (bvh_intersect(ray, node->left, t_t_left_t_right[0],
			(void *[2]){self, t_t_left_t_right[1]}));
}

bool	bvh_search_overlap(t_bvhnode *node, t_ray *ray,
			float **t_t_left_t_right, void *self)
{
	*t_t_left_t_right[1] = bvh_intersect(ray, node->left, t_t_left_t_right[0],
			(void *[2]){self, t_t_left_t_right[1]});
	*t_t_left_t_right[2] = bvh_intersect(ray, node->right, t_t_left_t_right[0],
			(void *[2]){self, t_t_left_t_right[2]});
	if (*t_t_left_t_right[1] || *t_t_left_t_right[2])
		return (1);
	return (0);
}

int	bvh_intersect_early_exit(t_ray *ray, t_bvhnode *node, float *t, void *self)
{
	float	t_bbox;

	if (!node)
		return (0);
	t_bbox = aabb_intersect(&node->bbox, ray);
	if (t_bbox < 0 || t_bbox >= *t)
		return (0);
	if (node->is_leaf)
		return (objects_intersect(ray, node, t, self));
	if (bvh_intersect_early_exit(ray, node->left, t, self))
		return (1);
	return (bvh_intersect_early_exit(ray, node->right, t, self));
}
