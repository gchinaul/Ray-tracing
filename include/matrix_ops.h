/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 10:13:03 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPS_H
# define MATRIX_OPS_H

# include "miniRT.h"

typedef float	t_matrix[4][4];

void	create_rotation_matrix_x(t_matrix rot, float angle);
void	create_rotation_matrix_y(t_matrix rot, float angle);
void	create_rotation_matrix_z(t_matrix rot, float angle);
t_vec3	apply_rotation(t_vec3 *vec, t_matrix rot);

#endif
