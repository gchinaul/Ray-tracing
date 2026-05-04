/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:38:15 by van               #+#    #+#             */
/*   Updated: 2025/09/05 09:38:24 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	*err_open_null(char *file)
{
	write(2, file, ft_strlen(file));
	perror("\nopen");
	return (NULL);
}

bool	err_unexpected_eof(void)
{
	printf("Error: Unexpected end of file\n");
	perror("");
	return (1);
}
