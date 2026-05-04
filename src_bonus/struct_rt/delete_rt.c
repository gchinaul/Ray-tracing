/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:06:26 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:14:55 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bump_map.h"
#include "bvh.h"
#include "free_utils.h"
#include "miniRT.h"

void	delete_rt(t_rt *rt)
{
	delete_scn(&rt->scn);
	delete_bvh(rt->bvh);
	delete_bmaps(rt->b_maps);
	mlx_free(&rt->mlx);
}

void	delete_bmaps(t_bump_map *maps)
{
	t_bump_map	*next;

	while (maps)
	{
		next = maps->next;
		free_map(maps);
		maps = next;
	}
}

void	delete_bvh(t_bvhnode *node)
{
	if (node == NULL)
		return ;
	if (!node->is_leaf)
	{
		if (node->left)
			delete_bvh(node->left);
		if (node->right)
			delete_bvh(node->right);
	}
	free(node);
}

void	delete_scn(t_scn *scn)
{
	free(scn->amb);
	free(scn->cam);
	free(scn->arr);
	free_lights(scn->lights);
	delete_objs(&scn->objs);
	free_planes(scn->planes);
	free_cones(scn->cones);
}

void	free_lights(t_light *lights)
{
	if (lights == NULL)
		return ;
	while (lights->next)
	{
		lights = lights->next;
		free(lights->prev);
	}
	free(lights);
}
