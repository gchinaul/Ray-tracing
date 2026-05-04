/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:26:01 by van               #+#    #+#             */
/*   Updated: 2024/12/12 17:02:36 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_putu_fd(unsigned int n, int fd, int *count);
void	printhexa1(unsigned int n, char c);
void	printhexa(unsigned int n, char c, int *count);
void	p_hexa(unsigned long long n);
void	percent_p(va_list argl, int *count);
void	percent(char c, va_list argl, int *count);
void	percent2(char c, va_list argl, int *count);
int		ft_read(const char *input, va_list argl);
int		ft_printf(const char *input, ...);

#endif