/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rt2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:07:12 by van               #+#    #+#             */
/*   Updated: 2025/09/10 17:28:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_planes(t_plane *planes)
{
	t_plane	*tmp;

	while (planes)
	{
		tmp = planes->next;
		free_plane(planes);
		planes = tmp;
	}
}

void	free_plane(t_plane *plane)
{
	if (plane == NULL)
		return ;
	free(plane);
}
