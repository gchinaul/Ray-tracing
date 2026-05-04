/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_transformations_cone_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 10:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/08 22:28:01 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"
#include "math_for_phys_1.h"
#include "math_for_phys_2.h"
#include "matrix.h"
#include "matrix_ops.h"
#include "miniRT.h"
#include "minilibx.h"

int	handle_cn_translations_bonus(t_cone *cn, int keycode)
{
	if (keycode == KEY_W)
		cn->coo.y -= 1;
	else if (keycode == KEY_S)
		cn->coo.y += 1;
	else if (keycode == KEY_A)
		cn->coo.x -= 1;
	else if (keycode == KEY_D)
		cn->coo.x += 1;
	else if (keycode == KEY_Q)
		cn->coo.z += 1;
	else if (keycode == KEY_E)
		cn->coo.z -= 1;
	else
		return (0);
	cn->bbox = compute_cone_aabb(cn);
	return (1);
}

static void	apply_cone_rotation_bonus(t_cone *cn, t_matrix rot)
{
	cn->orientation = apply_rotation(&cn->orientation, rot);
	normalize(&cn->orientation);
	cn->bbox = compute_cone_aabb(cn);
}

int	handle_cn_rotation_bonus(t_cone *cn, int keycode)
{
	t_matrix	rot;

	if (keycode == KEY_UP)
		create_rotation_matrix_x(rot, -5.7);
	else if (keycode == KEY_DOWN)
		create_rotation_matrix_x(rot, 5.7);
	else if (keycode == KEY_LEFT)
		create_rotation_matrix_y(rot, -5.7);
	else if (keycode == KEY_RIGHT)
		create_rotation_matrix_y(rot, 5.7);
	else if (keycode == KEY_COMMA)
		create_rotation_matrix_z(rot, -5.7);
	else if (keycode == KEY_DOT)
		create_rotation_matrix_z(rot, 5.7);
	else
		return (0);
	apply_cone_rotation_bonus(cn, rot);
	return (1);
}
