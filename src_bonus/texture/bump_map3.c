/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:03:29 by van               #+#    #+#             */
/*   Updated: 2025/09/01 17:13:12 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	append_bump_map(t_rt *rt, t_bump_map *map)
{
	t_bump_map	*current;

	current = rt->b_maps;
	if (!current)
		rt->b_maps = map;
	else
	{
		while (current->next)
			current = current->next;
		current->next = map;
	}
}

bool	is_new_map(t_bump_map *maps, char *name)
{
	int	len;

	if (maps == NULL)
		return (true);
	while (maps)
	{
		len = ft_strlen(maps->name);
		if ((int)ft_strlen(name) == len
			&& !ft_strncmp(maps->name, name, len + 1))
			return (false);
		maps = maps->next;
	}
	return (true);
}

void	set_map_attr_null(t_bump_map *map)
{
	map->name = NULL;
	map->next = NULL;
	map->map = NULL;
}

// init a single t_bump_map
int	init_bump_map(t_bump_map *map)
{
	int			fd;
	char		path[128];

	printf("file: %s\n", map->name);
	map->map = NULL;
	ft_strlcpy(path, "textures/", 10);
	ft_strlcpy(path + 9, map->name, ft_strlen(map->name) + 1);
	printf("path: %s\n", path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (err_open(1, map->name));
	if (check_header(fd, map))
		return (1);
	printf("map:\n");
	printf("\trows: %d\n", map->rows);
	printf("\tcolumns: %d\n", map->columns);
	printf("\tscale: %d\n", map->scale);
	if (init_map(map, fd))
		return (free_map(map));
	close(fd);
	return (0);
}
