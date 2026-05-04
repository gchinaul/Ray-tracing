/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 17:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 11:28:12 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix_ops.h"
#include <math.h>

void	create_rotation_matrix_x(t_matrix rot, float angle)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rot[0][0] = 1.0f;
	rot[0][1] = 0.0f;
	rot[0][2] = 0.0f;
	rot[0][3] = 0.0f;
	rot[1][0] = 0.0f;
	rot[1][1] = cos_a;
	rot[1][2] = -sin_a;
	rot[1][3] = 0.0f;
	rot[2][0] = 0.0f;
	rot[2][1] = sin_a;
	rot[2][2] = cos_a;
	rot[2][3] = 0.0f;
	rot[3][0] = 0.0f;
	rot[3][1] = 0.0f;
	rot[3][2] = 0.0f;
	rot[3][3] = 1.0f;
}

void	create_rotation_matrix_y(t_matrix rot, float angle)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rot[0][0] = cos_a;
	rot[0][1] = 0.0f;
	rot[0][2] = sin_a;
	rot[0][3] = 0.0f;
	rot[1][0] = 0.0f;
	rot[1][1] = 1.0f;
	rot[1][2] = 0.0f;
	rot[1][3] = 0.0f;
	rot[2][0] = -sin_a;
	rot[2][1] = 0.0f;
	rot[2][2] = cos_a;
	rot[2][3] = 0.0f;
	rot[3][0] = 0.0f;
	rot[3][1] = 0.0f;
	rot[3][2] = 0.0f;
	rot[3][3] = 1.0f;
}

void	create_rotation_matrix_z(t_matrix rot, float angle)
{
	float	cos_a;
	float	sin_a;

	cos_a = cos(angle);
	sin_a = sin(angle);
	rot[0][0] = cos_a;
	rot[0][1] = -sin_a;
	rot[0][2] = 0.0f;
	rot[0][3] = 0.0f;
	rot[1][0] = sin_a;
	rot[1][1] = cos_a;
	rot[1][2] = 0.0f;
	rot[1][3] = 0.0f;
	rot[2][0] = 0.0f;
	rot[2][1] = 0.0f;
	rot[2][2] = 1.0f;
	rot[2][3] = 0.0f;
	rot[3][0] = 0.0f;
	rot[3][1] = 0.0f;
	rot[3][2] = 0.0f;
	rot[3][3] = 1.0f;
}

t_vec3	apply_rotation(t_vec3 *vec, t_matrix rot)
{
	t_vec3	result;

	result.x = rot[0][0] * vec->x + rot[0][1] * vec->y + rot[0][2] * vec->z;
	result.y = rot[1][0] * vec->x + rot[1][1] * vec->y + rot[1][2] * vec->z;
	result.z = rot[2][0] * vec->x + rot[2][1] * vec->y + rot[2][2] * vec->z;
	return (result);
}
