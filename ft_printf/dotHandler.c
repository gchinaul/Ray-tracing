/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dotHandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:25:18 by van               #+#    #+#             */
/*   Updated: 2024/12/24 12:12:57 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

void	dot_handler3(char c, int size, va_list argl, int *count)
{
	unsigned long int	ul;

	if (c == 'x' || c == 'X')
	{
		ul = va_arg(argl, unsigned long int);
		size = size - hexa_size(ul);
		fill (size, '0', count);
		printhexa(ul, c, count);
	}
}

void	dot_handler2(char c, int size, va_list argl, int *count)
{
	int		d;
	char	*s;

	if (c == 'd' || c == 'i')
	{
		d = va_arg(argl, int);
		size = size - needed_ilen(d);
		if (d <= 0)
			size++;
		if (d < 0)
		{
			write(1, "-", 1);
			*count = *count + 1;
			if (d != -2147483648)
				d = -d;
		}
		fill (size, '0', count);
		s = ft_itoa(d);
		if (d == -2147483648)
			*count = *count + ft_printf("2147483648");
		else if (d != 0)
			*count = *count + ft_printf(s);
		free(s);
	}
	dot_handler3(c, size, argl, count);
}

void	dot_handler(char c, int size, va_list argl, int *count)
{
	char			*s;
	unsigned int	u;

	if (c == 's')
	{
		s = va_arg(argl, char *);
		while (size > 0 && *s)
		{
			write(1, s, 1);
			s++;
			size--;
			*count = *count + 1;
		}
	}
	else if (c == 'u')
	{
		u = va_arg(argl, unsigned int);
		size = size - needed_ulen(u);
		fill (size, '0', count);
		ft_putu_fd(u, 1, count);
	}
	else
		dot_handler2(c, size, argl, count);
}
