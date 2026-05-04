/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusHandler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:11:51 by van               #+#    #+#             */
/*   Updated: 2024/12/24 11:11:59 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	plus_handler(char c, int size, va_list argl, int *count)
{
	int	d;

	if (c == 'd' || c == 'i')
	{
		d = va_arg(argl, int);
		size = size - needed_ilen(d);
		if (d >= 0)
			size--;
		fill(size, ' ', count);
		if (d >= 0)
			*count = *count + ft_printf("+%d", d);
		else
			*count = *count + ft_printf("%d", d);
	}
}
