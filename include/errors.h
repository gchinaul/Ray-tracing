/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:15:43 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:58 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

//	error.c
int		err(int n, char *s);
void	*err_malloc_null(void);
int		err_malloc(int n);
int		err_open(int n, char *file);
void	*err_null(char *s);
//	error2.c
void	*err_open_null(char *file);
bool	err_unexpected_eof(void);

//	format_err1.c
void	print_err_format_begining(char *id, char *data);
int		err_dot_format_in_range_1(int n, char *id, char *data);
int		err_rgb_format(int n, char *id, char *data);
int		err_coo_format(int n, char *id, char *data);
int		err_orientation_format(int n, char *id, char *data);
//	format_err2.c
int		err_length_format(int n, char *id, char *data);
int		err_positive_int_format(int n, char *id, char *data);
int		err_float_format(int n, char *id, char *data);

//	rgb_err.c
int		err_rgb_range(int n);

#endif
