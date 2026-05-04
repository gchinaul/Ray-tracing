/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:12:23 by van               #+#    #+#             */
/*   Updated: 2025/09/01 17:10:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// alloc the bmaps lst with the required size, check bmaps format and perm 
int	alloc_bump_maps(t_rt *rt)
{
	if (register_objs_texture(rt) || register_planes_texture(rt))
		return (1);
	if (!have_bmaps_valid_ext(rt->b_maps))
		return (1);
	if (!are_bmaps_openable(rt->b_maps))
		return (err_open(1, ""));
	return (0);
}

bool	have_bmaps_valid_ext(t_bump_map *map)
{
	t_bump_map	*current;

	current = map;
	while (current)
	{
		if (ft_strlen(current->name) < 4
			|| ft_strncmp(current->name + ft_strlen(current->name) - 4,
				".ppm", 5))
		{
			printf("%s: file is not .ppm\n", current->name);
			return (false);
		}
		current = current->next;
	}
	return (true);
}

bool	are_bmaps_openable(t_bump_map *maps)
{
	int		fd;
	char	path[256];

	ft_strlcpy(path, "textures/", 10);
	while (maps)
	{
		printf("%s\n", maps->name);
		ft_strlcpy(path + 9, maps->name, ft_strlen(maps->name) + 1);
		fd = open(path, O_RDONLY);
		if (fd < 0)
			return (false);
		close(fd);
		maps = maps->next;
	}
	return (true);
}

int	register_objs_texture(t_rt *rt)
{
	t_scn_obj	*objs;
	t_bump_map	*map;
	char		*name;

	objs = rt->scn.objs;
	while (objs)
	{
		name = get_obj_bmap_name(objs);
		if (name && is_new_map(rt->b_maps, name))
		{
			map = malloc(sizeof(t_bump_map));
			if (map == NULL)
				return (err_malloc(1));
			set_map_attr_null(map);
			append_bump_map(rt, map);
			map->name = ft_strdup(name);
			if (map->name == NULL)
				return (err_malloc(1));
		}
		objs = objs->next;
	}
	return (0);
}

int	register_planes_texture(t_rt *rt)
{
	t_plane		*planes;
	t_bump_map	*map;

	planes = rt->scn.planes;
	while (planes)
	{
		if (planes->bmap_name && is_new_map(rt->b_maps, planes->bmap_name))
		{
			map = malloc(sizeof(t_bump_map));
			if (map == NULL)
				return (err_malloc(1));
			set_map_attr_null(map);
			append_bump_map(rt, map);
			map->name = ft_strdup(planes->bmap_name);
			if (map->name == NULL)
				return (err_malloc(1));
		}
		planes = planes->next;
	}
	return (0);
}
