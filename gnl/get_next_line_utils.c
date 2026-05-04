/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:44:54 by van               #+#    #+#             */
/*   Updated: 2025/07/22 13:28:25 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strchr_gnl(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

int	ft_strlen_gnl(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (-1);
	while (s[len])
		len++;
	return (len);
}

void	ft_strncpy(char *src, char *dst, int size)
{
	if (!src)
		return ;
	while (*src && size)
	{
		*dst = *src;
		src++;
		dst++;
		size--;
	}
	*dst = '\0';
}
