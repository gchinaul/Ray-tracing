/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:13:28 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:25:48 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* return n, print s in stderr
 */
int	err(int n, char *s)
{
	write (STDERR_FILENO, s, ft_strlen(s));
	return (n);
}

void	*err_null(char *s)
{
	write (STDERR_FILENO, s, ft_strlen(s));
	return (NULL);
}

void	*err_malloc_null(void)
{
	perror("malloc");
	return (NULL);
}

int	err_malloc(int n)
{
	perror("malloc");
	return (n);
}

int	err_open(int n, char *file)
{
	write(2, file, ft_strlen(file));
	perror("\nopen");
	return (n);
}
