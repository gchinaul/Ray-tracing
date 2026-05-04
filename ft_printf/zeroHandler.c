/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroHandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:02:00 by van               #+#    #+#             */
/*   Updated: 2024/12/24 12:15:16 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

void	zero_handler2(char c, int size, va_list argl, int *count)
{
	unsigned int	u;

	if (c == 'u')
	{
		u = va_arg(argl, unsigned int);
		size = size - needed_ulen(u);
		fill(size, '0', count);
		ft_putu_fd(u, 1, count);
	}
	else if (c == 'x' || c == 'X')
	{
		u = va_arg(argl, unsigned int);
		size = size - hexa_size(u);
		fill (size, '0', count);
		printhexa(u, c, count);
	}
}

void	zero_handler(char c, int size, va_list argl, int *count)
{
	int				d;

	if (c == 'd' || c == 'i')
	{
		d = va_arg(argl, int);
		size = size - needed_ilen(d);
		if (d == -2147483648)
		{
			ft_putnbr_fd(d, 1);
			*count = *count + 11;
			return ;
		}
		else if (d < 0)
		{
			fill (1, '-', count);
			d = -d;
		}
		fill(size, '0', count);
		ft_putnbr_fd(d, 1);
		*count = *count + needed_ilen(d);
	}
	else
		zero_handler2(c, size, argl, count);
}
