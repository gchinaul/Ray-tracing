/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:53:20 by van               #+#    #+#             */
/*   Updated: 2025/08/25 18:03:14 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		ft_strchr_gnl(char *s, char c);
int		ft_strlen_gnl(char *s);
void	ft_strncpy(char *src, char *dst, int size);
ssize_t	read(int fd, void *buf, size_t count);

#endif
