/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:31:42 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:24:51 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*new_win(void *connection_id, int size_x, int size_y, char *title)
{
	void	*win_id;

	write(1, "attempt to create new window\n", 30);
	win_id = mlx_new_window(connection_id, size_x, size_y, title);
	if (win_id == NULL)
	{
		write(1, "	faillure, exit with status 1\n", 31);
		return (NULL);
	}
	write(1, "	success\n", 10);
	return (win_id);
}
