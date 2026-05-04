/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 19:30:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/08/10 23:48:34 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

typedef struct s_vec3	t_vec3;
typedef struct s_plane	t_plane;

t_vec3					checkerboard_color_for_plane(t_plane *pl,
							t_vec3 *point);

#endif
