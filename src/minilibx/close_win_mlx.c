/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 10:02:31 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 18:34:21 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	close_window(void *param)
{
	t_hook	*hook;

	hook = (t_hook *)param;
	if (!hook)
		return (0);
	if (hook->mlx && hook->mlx->mlx)
		mlx_loop_end(hook->mlx->mlx);
	return (0);
}
