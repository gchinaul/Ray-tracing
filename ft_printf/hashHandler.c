/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashHandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:05:35 by van               #+#    #+#             */
/*   Updated: 2024/12/24 11:38:24 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	hash_handler(char c, int size, va_list argl, int *count)
{
	unsigned int	u;

	if (c == 'x' || c == 'X')
	{
		u = va_arg(argl, unsigned int);
		if (u == 0)
		{
			*count = *count + ft_printf("0");
			return ;
		}
		size = size - hexa_size(u) - 2;
		fill (size, ' ', count);
		if (c == 'x')
			*count = *count + ft_printf("0x%x", u);
		else
			*count = *count + ft_printf("0X%X", u);
	}
}
