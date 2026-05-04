/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 15:01:16 by van               #+#    #+#             */
/*   Updated: 2025/09/05 09:48:06 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "errors.h"

typedef struct s_vec3	t_vec3;

//	rgb.c
int		rgb_to_int(int r, int g, int b);
int		get_red(int rgb);
int		get_green(int rgb);
int		get_blue(int rgb);
int		rgb_vec3_to_int(t_vec3 *rgb);
//	rgb2.c
void	scale_rgb(t_vec3 *rgb);

#endif
