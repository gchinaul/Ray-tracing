/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checkers1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:46:43 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:25:39 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// Contains checkers for the different formats

int	is_dot_format_in_range_1(char *s)
{
	if (ft_strlen(s) == 1 && (*s == '0' || *s == '1'))
		return (1);
	if (ft_strlen(s) != 3)
		return (0);
	if (s[0] != '0' && s[0] != '1')
		return (0);
	if (s[1] != '.')
		return (0);
	if (s[0] == '0')
	{
		if (!ft_isdigit(s[2]))
			return (0);
	}
	else
	{
		if (s[2] != '0')
			return (0);
	}
	return (1);
}

int	is_rgb_format(char *s)
{
	int	count;
	int	i;

	i = -1;
	while (++i < 3)
	{
		count = 0;
		while (ft_isdigit(s[count]))
			count++;
		if (count == 0 || count > 3)
			return (0);
		if (ft_atoi(s) > 255)
			return (0);
		if (i == 2)
		{
			if (s[count])
				return (0);
			break ;
		}
		if (s[count] != ',')
			return (0);
		s += count + 1;
	}
	return (1);
}

int	is_one_digit_after_dot(char *s, int *count)
{
	int	n;

	(*count)++;
	n = 0;
	while (ft_isdigit(s[*count + n]))
		n++;
	if (n != 1)
		return (0);
	*count += n;
	return (1);
}

int	is_coo_format(char *s)
{
	int	i;
	int	count;

	i = -1;
	while (++i < 3)
	{
		count = 0;
		if (s[0] == '-')
			count++;
		while (ft_isdigit(s[count]))
			count++;
		if (count - (s[0] == '-') < 1 || count - (s[0] == '-') > 2
			|| (s[count] == '.' && !is_one_digit_after_dot(s, &count)))
			return (0);
		if (i == 2)
		{
			if (s[count])
				return (0);
			break ;
		}
		if (s[count] != ',')
			return (0);
		s += ++count;
	}
	return (1);
}

int	is_fov_format(char *s)
{
	int	len;
	int	sum;

	len = ft_strlen(s);
	sum = ft_atoi(s);
	if (!len || len > 3 || !is_made_of(s, "0123456789")
		|| !(0 <= sum && sum <= 180))
		return (0);
	return (1);
}
