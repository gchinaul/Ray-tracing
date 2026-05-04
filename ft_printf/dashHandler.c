/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dashHandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van-nguy <van-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:48:12 by van               #+#    #+#             */
/*   Updated: 2025/01/08 17:25:28 by van-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_bonus.h"

int	p_dash_handler(va_list argl, int *count)
{
	unsigned long long	n;
	unsigned long long	n2;
	int					len;

	n = va_arg(argl, unsigned long long);
	if (n == 0)
	{
		write(1, "(nil)", 5);
		*count = *count + 5;
		return (5);
	}
	len = 1;
	(*count)++;
	n2 = n;
	while (n2 > 15)
	{
		*count = *count + 1;
		n2 = n2 / 16;
		len++;
	}
	write(1, "0x", 2);
	*count = *count + 2;
	len = len + 2;
	p_hexa(n);
	return (len);
}

void	insert_utoa(char *s, unsigned int u)
{
	if (u < 10)
		*s = u + '0';
	else
	{
		*s = u % 10 + '0';
		insert_utoa(s - 1, u / 10);
	}
}

char	*ft_utoa(unsigned int u)
{
	int		len;
	char	*ptr;

	len = needed_ulen(u);
	ptr = malloc (len + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[len] = '\0';
	insert_utoa(ptr + len - 1, u);
	return (ptr);
}

void	dash_handler2(char c, int size, va_list argl, int *count)
{
	unsigned int	u;
	unsigned long	ul;

	if (c == 'p')
	{
		size = size - p_dash_handler(argl, count);
		fill (size, ' ', count);
	}
	else if (c == 'u')
	{
		u = va_arg(argl, unsigned int);
		*count = *count + ft_printf("%u", u);
		size = size - needed_ulen(u);
		fill (size, ' ', count);
	}
	else if (c == 'x' || c == 'X')
	{
		ul = va_arg(argl, unsigned long);
		if (c == 'x')
			*count = *count + ft_printf("%x", ul);
		else
			*count = *count + ft_printf("%X", ul);
		size = size - hexa_size(ul);
		fill(size, ' ', count);
	}
}

void	dash_handler(char c, int size, va_list argl, int *count)
{
	int		d;
	char	*s;

	if (c == 'c')
	{
		c = va_arg(argl, int);
		*count = *count + ft_printf("%c", c);
		size--;
		fill(size, ' ', count);
	}
	else if (c == 's')
	{
		s = va_arg(argl, char *);
		*count = *count + ft_printf(s);
		size = size - ft_strlen(s);
		fill(size, ' ', count);
	}
	else if (c == 'd' || c == 'i')
	{
		d = va_arg(argl, int);
		*count = *count + ft_printf("%d", d);
		size = size - needed_ilen(d);
		fill(size, ' ', count);
	}
	dash_handler2(c, size, argl, count);
}
