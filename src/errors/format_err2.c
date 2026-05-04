/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_err2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:18:23 by van               #+#    #+#             */
/*   Updated: 2025/09/12 13:17:37 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	err_length_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong length format or value ([n]n[.n[n]] [0, 99.99])\n", 54);
	return (n);
}

int	err_positive_int_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong length format or value (n[nn] [0, 499])\n", 46);
	return (n);
}

int	err_float_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong length format or value (n[n][.nn])\n", 41);
	return (n);
}
