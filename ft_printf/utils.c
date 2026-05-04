/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:53:06 by van               #+#    #+#             */
/*   Updated: 2024/12/24 12:19:31 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_skip_atoi(const char	**input)
{
	if (**input == '-' || **input == '+')
		(*input)++;
	while ('0' <= **input && **input <= '9')
		(*input)++;
}

char	ft_after_atoi(const char **input)
{
	int	i;

	i = 0;
	if ((*input)[i] == '-' || (*input)[i] == '+')
		i++;
	while ('0' <= (*input)[i] && (*input)[i] <= '9')
		i++;
	return ((*input)[i]);
}

int	needed_ilen(int d)
{
	int	len;

	if (d == -2147483648)
		return (11);
	len = 1;
	if (d < 0)
	{
		d = -d;
		len++;
	}
	while (d > 9)
	{
		len++;
		d = d / 10;
	}
	return (len);
}

int	needed_ulen(unsigned int u)
{
	int	len;

	len = 1;
	while (u > 9)
	{
		u = u / 10;
		len++;
	}
	return (len);
}

int	hexa_size(unsigned long long n)
{
	int	size;

	size = 1;
	while (n > 15)
	{
		size = size + 1;
		n = n / 16;
	}
	return (size);
}
