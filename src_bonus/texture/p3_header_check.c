/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3_header_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:14:31 by van               #+#    #+#             */
/*   Updated: 2025/09/01 17:17:22 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// check p3 header format, set the attr rows,columns,scale of bmap
int	check_header(int fd, t_bump_map *map)
{
	if (check_header_1(fd)
		|| check_header_2(fd, map)
		|| check_header_3(fd, map))
		return (1);
	return (0);
}

int	check_header_1(int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (err_malloc(1));
	if (ft_strncmp(line, "P3\n", 4))
	{
		free(line);
		return (err(1, "Unrecognized format\n"));
	}
	free(line);
	return (0);
}

int	check_header_2(int fd, t_bump_map *map)
{
	char	*line;
	char	*w;
	char	*h;

	line = get_next_line(fd);
	if (line == NULL)
		return (err_malloc(1));
	w = get_nth_word(line, 1);
	h = get_nth_word(line, 2);
	if (count_words(line) != 2 || !is_number(w) || !is_number(h))
	{
		free(line);
		return (err(1, "Incorrect format\n"));
	}
	map->columns = ft_atoi(w);
	map->rows = ft_atoi(h);
	free(line);
	if (map->rows == 0 || map->columns == 0)
		return (err(1, "Empty bump_map\n"));
	return (0);
}

int	check_header_3(int fd, t_bump_map *map)
{
	char	*line;
	char	*scale;

	line = get_next_line(fd);
	if (line == NULL)
		return (err_malloc(1));
	scale = get_nth_word(line, 1);
	if (count_words(line) != 1 || !is_number(scale))
	{
		free(line);
		return (err(1, "Incorrect format\n"));
	}
	map->scale = ft_atoi(scale);
	free(line);
	if (map->scale < 1)
		return (err(1, "Invalid scale\n"));
	return (0);
}
