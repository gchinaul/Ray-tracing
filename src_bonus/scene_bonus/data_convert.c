/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 13:37:08 by van               #+#    #+#             */
/*   Updated: 2025/09/01 21:11:24 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// convert n.n str into float
float	float_str_to_float(char *s)
{
	float	f;
	int		n;
	int		neg;

	if (*s == '-')
		neg = 1;
	else
		neg = 0;
	f = ft_atoi(s);
	if (!ft_strchr(s, '.'))
		return (f);
	if (ft_strchr(s, ',') && ft_strchr(s, '.') > ft_strchr(s, ','))
		return (f);
	s = ft_strchr(s, '.') + 1;
	n = 0;
	while (ft_isdigit(s[n]))
		n++;
	if (!neg)
		f += ft_atoi(s) / pow(10, n);
	else
		f -= ft_atoi(s) / pow(10, n);
	return (f);
}

// convert rrr,ggg,bbb [0,255] str into int
int	rgb_str_to_int(char *s, t_vec3 *rgb)
{
	int	r;
	int	g;
	int	b;

	if (!s || !rgb)
		return (1);
	r = ft_atoi(s);
	if (!ft_strchr(s, ','))
		return (1);
	s = ft_strchr(s, ',') + 1;
	g = ft_atoi(s);
	if (!ft_strchr(s, ','))
		return (1);
	s = ft_strchr(s, ',') + 1;
	b = ft_atoi(s);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (1);
	rgb->x = r;
	rgb->y = g;
	rgb->z = b;
	return (rgb_to_int(r, g, b));
}

// convert f.f,f.f,f.f to t_vec3
t_vec3	_3f_str_to_vec3(char *s)
{
	t_vec3	vec;

	vec.x = float_str_to_float(s);
	s = ft_strchr(s, ',') + 1;
	vec.y = float_str_to_float(s);
	s = ft_strchr(s, ',') + 1;
	vec.z = float_str_to_float(s);
	return (vec);
}
