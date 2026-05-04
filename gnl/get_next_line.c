/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:31:41 by van               #+#    #+#             */
/*   Updated: 2025/08/26 10:42:26 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 128
#endif

void	buff_to_line(char **line, char *buff)
{
	int		end;
	char	*new_line;

	end = ft_strlen_gnl(buff);
	if (ft_strchr_gnl(buff, '\n') >= 0)
		end = ft_strchr_gnl(buff, '\n') + 1;
	if (*line == NULL)
	{
		*line = malloc (1);
		if (*line == NULL)
			return ;
		*line [0] = '\0';
	}
	new_line = malloc (ft_strlen_gnl(*line) + end + 1);
	if (new_line == NULL)
		return ;
	ft_strncpy(*line, new_line, ft_strlen_gnl(*line));
	ft_strncpy(buff, new_line + ft_strlen_gnl(*line), end);
	free (*line);
	*line = new_line;
	ft_strncpy(buff + end, buff, ft_strlen_gnl(buff) - end);
	return ;
}

int	last_check(char **line, char *buff, ssize_t nread)
{
	if (ft_strlen_gnl(*line) > 0 || ft_strlen_gnl(buff) || nread != BUFFER_SIZE)
	{
		buff[nread] = '\0';
		buff_to_line(line, buff);
		if (ft_strlen_gnl(*line) <= 0)
		{
			free(*line);
			return (0);
		}
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		nread;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (ft_strlen_gnl(buff))
		buff_to_line(&line, buff);
	if (ft_strchr_gnl(line, '\n') >= 0)
		return (line);
	nread = read(fd, buff, BUFFER_SIZE);
	while (nread == BUFFER_SIZE)
	{
		buff_to_line(&line, buff);
		if (ft_strchr_gnl(line, '\n') >= 0)
			return (line);
		nread = read(fd, buff, BUFFER_SIZE);
	}
	if (last_check(&line, buff, nread))
		return (line);
	return (NULL);
}
