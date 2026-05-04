/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:52:54 by van               #+#    #+#             */
/*   Updated: 2024/12/12 15:37:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	percent(char c, va_list argl, int *count)
{
	char	*s;

	if (c == 'c')
	{
		*count = *count + 1;
		c = (char)va_arg(argl, int);
		write(1, &c, 1);
	}
	else if (c == 's')
	{
		s = va_arg(argl, char *);
		if (s == NULL)
			s = "(null)";
		*count = *count + ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	else if (c == 'p')
		percent_p(argl, count);
	else if (c == 'u')
		ft_putu_fd(va_arg(argl, unsigned int), 1, count);
	else if (c == 'x' || c == 'X')
		printhexa(va_arg(argl, int), c, count);
	else
		percent2(c, argl, count);
}

void	percent2(char c, va_list argl, int *count)
{
	int	n;
	int	n_cp;

	if (c == 'd' || c == 'i')
	{
		n = va_arg(argl, int);
		n_cp = n;
		if (n_cp < 0)
		{
			if (n == -2147483648)
				*count = *count + 9;
			*count = *count + 1;
			n_cp = -n_cp;
		}
		while (n_cp > 9)
		{
			*count = *count + 1;
			n_cp = n_cp / 10;
		}
		ft_putnbr_fd (n, 1);
	}
	else if (c == '%')
		write(1, &c, 1);
	*count = *count + 1;
}

int	ft_read(const char *input, va_list argl)
{
	int	count;

	count = 0;
	while (*input)
	{
		if (*input == '%')
		{
			if (ft_strchr("cspdiuxX%", *(input + 1)))
			{
				percent(*(input + 1), argl, &count);
				input++;
			}
		}
		else
		{
			count++;
			write (1, input, 1);
		}
		input++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	argl;
	int		count;

	va_start(argl, input);
	count = ft_read(input, argl);
	va_end(argl);
	return (count);
}
