/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 08:24:28 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_UTILS_H
# define BONUS_UTILS_H

# include "miniRT.h"

typedef struct s_cone_params
{
	float		*u;
	float		*v;
	t_vec3		*point;
	t_bump_map	*bump_map;
}				t_cone_params;

typedef struct s_mat_vec_params
{
	int			n;
	float		(*mat)[3];
	float		*vec;
	float		*result;
}				t_mat_vec_params;

typedef struct s_mat_calc_params
{
	int			n;
	float		(*a)[3];
	float		(*b)[3];
	float		(*result)[3];
	int			i;
	int			j;
}				t_mat_calc_params;

#endif
