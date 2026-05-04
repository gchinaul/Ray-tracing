/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_err1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:13:20 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:26:03 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* Holds the error messages produced by format parsing
 */

void	print_err_format_begining(char *id, char *data)
{
	write(2, "Error\n", 6);
	write(2, id, ft_strlen(id));
	write(2, ": ", 2);
	write(2, data, ft_strlen(data));
	write(2, ": ", 2);
}

int	err_dot_format_in_range_1(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong format or value (n[.n] [0.0,0.1])\n", 40);
	return (n);
}

int	err_rgb_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong rgb format or value ", 26);
	write(2, "([n][n]n,[n][n]n,[n][n]n [0,255])\n", 34);
	return (n);
}

int	err_coo_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong coordinates format or value ", 34);
	write(2, "([-][n]n[.n],[-][n]n[.n],[-][n]n[.n])\n", 38);
	return (n);
}

int	err_orientation_format(int n, char *id, char *data)
{
	print_err_format_begining(id, data);
	write(2, "Wrong orientation vector format or value ", 41);
	write(2, "([-][n]n[.n],[-][n]n[.n],[-][n]n[.n]) \\{0,0,0}\n", 47);
	return (n);
}
