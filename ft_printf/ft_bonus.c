/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van-nguy <van-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 22:30:40 by van-nguy          #+#    #+#             */
/*   Updated: 2025/01/08 17:25:05 by van-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

#include <stdio.h>

void	fill(int size, char c, int *count)
{
	char	s[2];

	s[0] = c;
	while (size > 0)
	{
		size--;
		*count = *count + 1;
		write(1, s, 1);
	}
}

void	no_flag_handler2(char c, int size, va_list argl, int *count)
{
	char				*s;
	unsigned long long	n;

	if (c == 's')
	{
		s = va_arg(argl, char *);
		size = size - ft_strlen(s);
		fill(size, ' ', count);
		*count = *count + ft_printf(s);
	}
	else if (c == 'p')
	{
		n = va_arg(argl, unsigned long long);
		size = size - 2 - hexa_size(n);
		fill(size, ' ', count);
		*count = *count + 2 + hexa_size(n);
		write(1, "0x", 2);
		p_hexa(n);
	}
}

void	no_flag_handler(const char **input, va_list argl, int *count)
{
	int					size;
	char				c;
	char				s2[2];

	(*input)++;
	size = ft_atoi(*input);
	c = ft_after_atoi(input);
	ft_skip_atoi(input);
	if (c == 'c')
	{
		s2[0] = (char)va_arg(argl, int);
		s2[1] = '\0';
		size--;
		fill(size, ' ', count);
		*count = *count + ft_printf(s2);
		if (s2[0] == 0)
			*count = *count + 1;
	}
	else
		no_flag_handler2(c, size, argl, count);
}

void	ft_bonus(const char **input, char c, va_list argl, int *count)
{
	int		size;

	if (!ft_strchr("-.0# +", *(*input + 1)))
		return (no_flag_handler(input, argl, count));
	(*input)++;
	(*input)++;
	size = ft_atoi(*input);
	ft_skip_atoi(input);
	if (c == '-')
		dash_handler(ft_after_atoi(input), size, argl, count);
	else if (c == '0')
		zero_handler(ft_after_atoi(input), size, argl, count);
	else if (c == '.')
		dot_handler(ft_after_atoi(input), size, argl, count);
	else if (c == '#')
		hash_handler(ft_after_atoi(input), size, argl, count);
	else if (c == ' ')
		space_handler(ft_after_atoi(input), size, argl, count);
	else if (c == '+')
		plus_handler(ft_after_atoi(input), size, argl, count);
}
