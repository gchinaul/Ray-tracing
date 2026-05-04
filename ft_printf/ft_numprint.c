/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:23:30 by van               #+#    #+#             */
/*   Updated: 2024/12/16 16:08:18 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

void	ft_putu_fd(unsigned int n, int fd, int *count)
{
	char	digit;

	if (n < 10)
	{
		*count = *count + 1;
		digit = n + '0';
		write (fd, &digit, 1);
	}
	else
	{
		ft_putu_fd(n / 10, fd, count);
		*count = *count + 1;
		digit = n % 10 + '0';
		write (fd, &digit, 1);
	}
}

void	printhexa1(unsigned int n, char c)
{
	if (n < 10)
		n = n + '0';
	else
		n = 'A' + n - 10 + c;
	write (1, &n, 1);
}

void	printhexa(unsigned int n, char c, int *count)
{
	if (c != 0 && c != 'a' - 'A')
	{
		if (c == 'X')
			c = 0;
		else
			c = 'a' - 'A';
	}
	if (n < 16)
	{
		*count = *count + 1;
		printhexa1(n, c);
	}
	else
	{
		*count = *count + 1;
		printhexa(n / 16, c, count);
		printhexa1(n % 16, c);
	}
}

void	p_hexa(unsigned long long n)
{
	if (n > 15)
	{
		p_hexa(n / 16);
		printhexa1((unsigned long)(n % 16), 'a' - 'A');
	}
	else
		printhexa1((unsigned long)n, 'a' - 'A');
}

void	percent_p(va_list argl, int *count)
{
	unsigned long long	n;
	unsigned long long	n2;

	n = va_arg(argl, unsigned long long);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
		return ;
	}
	n2 = n;
	while (n2 > 15)
	{
		*count = *count + 1;
		n2 = n2 / 16;
	}
	write(1, "0x", 2);
	*count = *count + 2 + 1;
	p_hexa(n);
}
