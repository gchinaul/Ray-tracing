/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 17:07:15 by van               #+#    #+#             */
/*   Updated: 2025/09/01 17:12:44 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// init rt.bmaps lst
int	init_bump_maps(t_rt *rt)
{
	t_bump_map	*maps;
	int			i;

	if (alloc_bump_maps(rt))
		return (1);
	maps = rt->b_maps;
	i = 0;
	while (maps)
	{
		i++;
		if (init_bump_map(maps))
			return (1);
		maps = maps->next;
	}
	printf("%d maps created\n\n\n", i);
	link_objs(rt);
	link_planes(rt);
	return (0);
}

// set bmap attr for planes
void	link_planes(t_rt *rt)
{
	t_plane		*plane;
	t_bump_map	*map;
	char		*name;

	plane = rt->scn.planes;
	while (plane)
	{
		if (!plane->bmap_name)
		{
			plane = plane->next;
			continue ;
		}
		name = plane->bmap_name;
		map = rt->b_maps;
		while (map)
		{
			if (!ft_strncmp(name, map->name, ft_strlen(name) + 1))
			{
				plane->bmap = map;
				break ;
			}
			map = map->next;
		}
		plane = plane->next;
	}
}

// set bmap attr for objs
void	link_objs(t_rt *rt)
{
	t_scn_obj	*objs;
	t_bump_map	*map;
	char		*name;

	objs = rt->scn.objs;
	while (objs)
	{
		name = NULL;
		name = get_obj_bmap_name(objs);
		if (name)
		{
			map = rt->b_maps;
			while (map)
			{
				if (!ft_strncmp(name, map->name, ft_strlen(name) + 1))
				{
					set_obj_bmap(objs, map);
					break ;
				}
				map = map->next;
			}
		}
		objs = objs->next;
	}
}

char	*get_obj_bmap_name(t_scn_obj *obj)
{
	if (obj->type == SP)
		return (((t_sphere *)obj->data)->bmap_name);
	if (obj->type == CY)
		return (((t_cylinder *)obj->data)->bmap_name);
	return (NULL);
}

void	set_obj_bmap(t_scn_obj *obj, t_bump_map *map)
{
	if (obj->type == SP)
		((t_sphere *)obj->data)->bmap = map;
	else if (obj->type == CY)
		((t_cylinder *)obj->data)->bmap = map;
}
