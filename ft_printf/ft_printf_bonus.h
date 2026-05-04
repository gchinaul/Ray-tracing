/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:36:56 by van               #+#    #+#             */
/*   Updated: 2024/12/24 11:10:55 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

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
char	ft_after_atoi(const char **input);
void	ft_skip_atoi(const char	**input);
int		needed_ilen(int d);
int		needed_ulen(unsigned int u);
int		hexa_size(unsigned long long n);
void	fill(int size, char c, int *count);
void	dash_handler(char c, int size, va_list argl, int *count);
void	dot_handler(char c, int size, va_list argl, int *count);
void	zero_handler(char c, int size, va_list argl, int *count);
void	hash_handler(char c, int size, va_list argl, int *count);
void	space_handler(char c, int size, va_list argl, int *count);
void	plus_handler(char c, int size, va_list argl, int *count);
void	ft_bonus(const char **input, char c, va_list argl, int *count);

#endif