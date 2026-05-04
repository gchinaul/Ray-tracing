/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van-nguy <van-nguy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:09:44 by van-nguy          #+#    #+#             */
/*   Updated: 2025/01/16 17:59:42 by van-nguy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*dest_rem;

	dest_rem = (char *)dest;
	if ((char *)src + n - 1 >= (char *)dest && src < dest)
	{
		while (n--)
			*((char *)dest + n) = *((char *)src + n);
	}
	else
	{
		while (n)
		{
			*((char *)dest) = *((char *)src);
			dest++;
			src++;
			n--;
		}
	}
	return (dest_rem);
}
