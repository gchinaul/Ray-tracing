/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:46:12 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:25:27 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* scale rgb vec3
 */
void	scale_rgb(t_vec3 *rgb)
{
	float	max;
	float	scale;

	max = fmaxf(rgb->x, rgb->y);
	max = fmaxf(rgb->z, max);
	if (max <= 255)
		return ;
	scale = 255.0f / max;
	rgb->x *= scale;
	rgb->y *= scale;
	rgb->z *= scale;
}
