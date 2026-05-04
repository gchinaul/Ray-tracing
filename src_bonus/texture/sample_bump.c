/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_bump.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:33:08 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:37:21 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

float	sample_bump(t_bump_map *map, float u, float v)
{
	int		xy2[4];
	int		xy[2];
	float	h4[4];
	float	h2[2];
	float	dxy[2];

	get_indexes((float *[2]){&u, &v}, map, xy2, xy);
	dxy[0] = xy[0] - xy2[0];
	dxy[1] = xy[1] - xy2[2];
	h4[0] = map->map[xy2[2] * map->columns + xy2[0]];
	h4[1] = map->map[xy2[2] * map->columns + xy2[1]];
	h4[2] = map->map[xy2[3] * map->columns + xy2[0]];
	h4[3] = map->map[xy2[3] * map->columns + xy2[1]];
	h2[0] = h4[0] * (1.0f - dxy[0]) + h4[1] * dxy[0];
	h2[1] = h4[2] * (1.0f - dxy[0]) + h4[3] * dxy[0];
	return (h2[0] * (1.0f - dxy[1]) + h2[1] * dxy[1]);
}

void	get_indexes(float **uv, t_bump_map *map, int *xy2, int *xy)
{
	if (*uv[0] < 0 || *uv[0] > 1 || *uv[1] < 0 || *uv[1] > 1)
	{
		*uv[0] = fmod(*uv[0], 1.0f);
		*uv[1] = fmod(*uv[1], 1.0f);
		if (*uv[0] < 0)
			*uv[0] += 1.0f;
		if (*uv[1] < 0)
			*uv[1] += 1.0f;
	}
	xy[0] = *uv[0] * (map->columns - 1);
	xy[1] = *uv[1] * (map->rows - 1);
	xy2[0] = (int)floorf(xy[0]);
	xy2[2] = (int)floorf(xy[1]);
	xy2[1] = xy2[0] + 1;
	xy2[3] = xy2[2] + 1;
	if (xy2[1] >= map->columns)
		xy2[1] = map->columns - 1;
	if (xy2[3] >= map->rows)
		xy2[3] = map->rows - 1;
}
