/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaceHandler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:07:13 by van               #+#    #+#             */
/*   Updated: 2024/12/24 12:17:07 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	space_handler2(char c, int size, va_list argl, int *count)
{
	int		d;

	if (c == 'd' || c == 'i')
	{
		d = va_arg(argl, int);
		if (size >= 0)
		{
			size = size - needed_ilen(d);
			if (size <= 0 && d >= 0)
				size = 1;
			fill(size, ' ', count);
			*count = *count + ft_printf("%d", d);
		}
		else
		{
			*count = *count + ft_printf(" %d", d);
			size = size + 2;
			while (size++ < 0)
				*count = *count + ft_printf(" ");
		}
	}
}

void	space_handler(char c, int size, va_list argl, int *count)
{
	char	*s;

	if (c == 's')
	{
		s = va_arg(argl, char *);
		*count = *count + ft_printf(s);
	}
	else
		space_handler2(c, size, argl, count);
}
