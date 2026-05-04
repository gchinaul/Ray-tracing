/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:10:47 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:14:51 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_bvhnode	*init_bvh(t_scn *scn, int count)
{
	t_scn_obj	*cpy;

	printf("INIT BVH\n");
	scn->arr = malloc (sizeof(t_scn_obj *) * (count + 1));
	if (scn->arr == NULL)
		return (NULL);
	scn->arr[count] = NULL;
	cpy = scn->objs;
	count = 0;
	while (cpy)
	{
		scn->arr[count++] = cpy;
		cpy = cpy->next;
	}
	return (build_bvh(scn->arr, count));
}

t_bvhnode	*build_bvh(t_scn_obj **objects, int count)
{
	t_aabb		global_bbox;
	int			axis;
	t_bvhnode	*left;
	t_bvhnode	*right;
	t_bvhnode	*node;

	if (count <= MAX_OBJECTS_PER_LEAF)
		return (create_leaf(objects, count));
	global_bbox = compute_combined_aabb(objects, count);
	axis = longest_axis(&global_bbox);
	if (count < 100)
		sort_objects_by_axis(objects, count, axis);
	else
		sort_list(objects, axis);
	left = build_bvh(objects, (count / 2));
	right = build_bvh(objects + (count / 2), count - (count / 2));
	node = malloc(sizeof(t_bvhnode));
	node->bbox = combine_aabb(&left->bbox, &right->bbox);
	node->left = left;
	node->right = right;
	node->objs = NULL;
	node->object_count = 0;
	node->is_leaf = 0;
	return (node);
}

t_bvhnode	*create_leaf(t_scn_obj **objects, int count)
{
	t_bvhnode	*node;

	node = malloc(sizeof(t_bvhnode));
	node->bbox = compute_combined_aabb(objects, count);
	node->objs = objects;
	node->object_count = count;
	node->left = NULL;
	node->right = NULL;
	node->is_leaf = 1;
	return (node);
}

// crée une boite de volume englobant les obj
t_aabb	compute_combined_aabb(t_scn_obj **objects, int count)
{
	t_aabb	bbox;
	int		i;

	if (count == 0)
		return ((t_aabb){{0, 0, 0}, {0, 0, 0}});
	bbox = objects[0]->bbox;
	i = -1;
	while (++i < count)
	{
		bbox.min = vec3_min(bbox.min, objects[i]->bbox.min);
		bbox.max = vec3_max(bbox.max, objects[i]->bbox.max);
	}
	return (bbox);
}

// combine 2 boite de volume
t_aabb	combine_aabb(const t_aabb *a, const t_aabb *b)
{
	return ((t_aabb){
		.min = vec3_min(a->min, b->min),
		.max = vec3_max(a->max, b->max)
	});
}
