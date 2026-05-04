/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_map4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:55:49 by van               #+#    #+#             */
/*   Updated: 2025/09/05 17:26:54 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// init bmap.map, the array of bump values
int	init_map(t_bump_map *map, int fd)
{
	char	*line;

	map->map = malloc(sizeof(float) * map->rows * map->columns);
	if (map->map == NULL)
		return (err_malloc(1));
	line = NULL;
	if (copy_file_content(map, &line, fd))
	{
		if (line)
			free(line);
		return (1);
	}
	free(line);
	return (0);
}

bool	copy_file_content(t_bump_map *map, char **line, int fd)
{
	int		ic[2];
	char	*current;

	ic[1] = 0;
	ic[0] = 0;
	while (ic[0] < map->rows * map->columns)
	{
		free(*line);
		*line = get_next_line(fd);
		if (*line == NULL)
			return (err_unexpected_eof());
		current = *line;
		if (ft_isspace(*current))
			current = get_next_word(current);
		while (current)
		{
			if (ic[1] == 0)
				map->map[ic[0]++] = (float)ft_atoi(current) / (float)map->scale;
			current = get_next_word(current);
			if (current == NULL)
				break ;
			ic[1] = (ic[1] + 1) % 3;
		}
	}
	return (0);
}

int	free_map(t_bump_map *map)
{
	free(map->name);
	free(map->map);
	free(map);
	return (1);
}
