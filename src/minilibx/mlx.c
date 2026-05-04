/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:02:58 by van-nguy          #+#    #+#             */
/*   Updated: 2025/08/10 17:24:41 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	mlx_ini(t_mlx *mlx, int width, int height, char *title)
{
	mlx->win = NULL;
	mlx->mlx = NULL;
	mlx->img = malloc(sizeof(t_img));
	if (mlx->img == NULL)
		return (1);
	mlx->img->img = NULL;
	mlx->img->addr = NULL;
	mlx->mlx = cnct();
	if (mlx->mlx == NULL)
		return (mlx_free(mlx));
	mlx->win = new_win(mlx->mlx, width, height, title);
	if (mlx->win == NULL)
		return (mlx_free(mlx));
	mlx->width = width;
	mlx->height = height;
	mlx->pos_x = 0;
	mlx->pos_y = 0;
	return (0);
}

int	mlx_free(t_mlx *mlx)
{
	if (mlx == NULL)
		return (1);
	if (mlx->img != NULL)
	{
		if (mlx->mlx && mlx->img->img != NULL)
			mlx_destroy_image(mlx->mlx, mlx->img->img);
		free (mlx->img);
	}
	if (mlx->mlx)
	{
		if (mlx->win)
			mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	return (1);
}

int	mlx_free_image(t_mlx *mlx)
{
	if (mlx == NULL || mlx->mlx == NULL)
		return (1);
	if (mlx->img)
	{
		if (mlx->img->img)
			mlx_destroy_image(mlx->mlx, mlx->img->img);
	}
	return (0);
}
