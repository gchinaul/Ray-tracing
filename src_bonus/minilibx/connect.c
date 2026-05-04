/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:13:12 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:24:28 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*cnct(void)
{
	void	*connection_id;

	write(1, "attempt to create connection\n", 30);
	connection_id = mlx_init();
	if (connection_id == NULL)
	{
		write(1, "connection to mlx failed\n", 26);
		write(1, "	exiting with status 1\n", 24);
		exit (1);
	}
	write(1, "	success\n", 10);
	return (connection_id);
}
