/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:19:27 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:24:38 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	init_img(void *connection_id, t_img *img, int width, int height)
{
	img->img = mlx_new_image(connection_id, width, height);
	if (img->img == NULL)
	{
		write(2, "	faillure, returning 1\n", 24);
		return (1);
	}
	img->addr = mlx_get_data_addr
		(img->img, &img->bpp, &img->line_len, &img->endian);
	if (img->addr == NULL)
	{
		mlx_destroy_image(connection_id, img->img);
		write(2, "	faillure, destroying img.img, returning 1\n", 44);
		return (1);
	}
	return (0);
}
