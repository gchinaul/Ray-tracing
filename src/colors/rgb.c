/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:00:58 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:25:14 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* store rgb in an int
 */
int	rgb_to_int(int r, int g, int b)
{
	if (!(0 <= r && r <= 255)
		|| !(0 <= g && g <= 255)
		|| !(0 <= b && b <= 255))
		return (err_rgb_range(-1));
	return ((r << 16) | (g << 8) | b);
}

/* extract red value from rgb int format
 */
int	get_red(int rgb)
{
	return ((rgb & 0xFF0000) >> 16);
}

/* extract green value from rgb int format
 */
int	get_green(int rgb)
{
	return ((rgb & 0x00FF00) >> 8);
}

/* extract blue value from rgb int format
 */
int	get_blue(int rgb)
{
	return (rgb & 0x0000FF);
}

/* returns the rgb int format corresponding to rgb
 */
int	rgb_vec3_to_int(t_vec3 *rgb)
{
	int	color;

	color = roundf(rgb->x);
	color = (color << 8) + roundf(rgb->y);
	color = (color << 8) + roundf(rgb->z);
	return (color);
}
