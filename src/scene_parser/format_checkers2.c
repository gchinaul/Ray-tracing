/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checkers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:51:34 by van               #+#    #+#             */
/*   Updated: 2025/09/05 07:40:54 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// check for orientation format + value != vec nul
int	is_orientation_format(char *s)
{
	char	sub[5];
	int		len;
	int		i;
	char	*start;

	start = s;
	i = -1;
	while (++i < 3)
	{
		len = 0;
		if (s[0] == '-')
			s++;
		while (len < 5 && (ft_isdigit(s[len]) || s[len] == '.'))
			len++;
		ft_strlcpy(sub, s, len + 1);
		if (!is_dot_format_in_range_1(sub)
			|| (i != 2 && s[len] != ',') || (i == 2 && s[len]))
			return (0);
		s += len + 1;
	}
	if (is_orientation_vec_null(start))
		return (0);
	return (1);
}

int	is_length_format(char *s)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (i == 0)
		return (0);
	if (!s[i] && ft_atoi(s) <= CY_MAX_LEN)
		return (1);
	if (s[i] != '.' || ft_atoi(s) > CY_MAX_LEN)
		return (0);
	s += i + 1;
	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (i == 0 || i > 2)
		return (0);
	return (1);
}

int	is_orientation_vec_null(char *s)
{
	while (*s)
	{
		if (ft_isdigit(*s) && *s != '0')
			return (0);
		s++;
	}
	return (1);
}

bool	is_positive_int_format(char *s)
{
	int	value;

	value = ft_atoi(s);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	if (value > MAX_PHONG_EXPONENT)
		return (false);
	return (true);
}

bool	is_float_format(char *s)
{
	int	n;

	n = ft_atoi(s);
	while (*s && ft_isdigit(*s))
		s++;
	if (*s == '\0')
		return (n <= IS_FLOAT_MAX_INT);
	if (*s != '.')
		return (false);
	n = 0;
	s++;
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (n <= IS_FLOAT_MAX_DECIMAL_PLACES);
}
