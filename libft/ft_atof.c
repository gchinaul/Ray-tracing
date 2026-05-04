/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 10:48:41 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:13:53 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_sign(const char *str, int *i)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (sign);
}

static float	parse_decimal(const char *str, int *i, float result)
{
	float	power;

	power = 1.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (ft_isdigit(str[*i]))
		{
			result = result * 10.0 + (str[*i] - '0');
			power *= 10.0;
			(*i)++;
		}
	}
	return (result / power);
}

float	ft_atof(const char *str)
{
	int		sign;
	float	result;
	int		i;

	result = 0.0;
	i = 0;
	sign = parse_sign(str, &i);
	while (ft_isdigit(str[i]))
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	result = parse_decimal(str, &i, result);
	return (sign * result);
}
