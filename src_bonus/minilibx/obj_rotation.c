/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_rotation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:05:51 by van               #+#    #+#             */
/*   Updated: 2025/09/10 14:26:38 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// pour rotation axe quelconque
//	formule de Rodrigues ou une matrice de rotation générique

// void rotation_axis(float angle_deg, float *axis, float *n) {
// 	float theta = angle_deg * M_PI / 180.0;
// 	float c = cos(theta);
// 	float s = sin(theta);
// 	float t = 1.0 - c;

// 	// Normaliser l'axe (important !)
// 	float norm = sqrt(axis[0]*axis[0] + axis[1]*axis[1] + axis[2]*axis[2]);
// 	float ax = axis[0] / norm;
// 	float ay = axis[1] / norm;
// 	float az = axis[2] / norm;

// 	// Appliquer la matrice de rotation
// 	float nx = n[0] * (c + ax*ax*t) + n[1] * (ax*ay*t - az*s) 
// 		+ n[2] * (ax*az*t + ay*s);
// 	float ny = n[0] * (ay*ax*t + az*s) + n[1] * (c + ay*ay*t)
// 		+ n[2] * (ay*az*t - ax*s);
// 	float nz = n[0] * (az*ax*t - ay*s) + n[1] * (az*ay*t + ax*s)
// 		+ n[2] * (c + az*az*t);

// 	n[0] = nx; n[1] = ny; n[2] = nz;
// }

// modifies the orientation vector n to perform a rotation around axis
void	rotation_axis(float angle_deg, t_vec3 *axis, t_vec3 *n1)
{
	float	a[3];
	float	n[3];
	float	cst[3];
	float	theta_norm[2];

	theta_norm[0] = angle_deg * M_PI / 180.0f;
	cst[0] = cosf(theta_norm[0]);
	cst[1] = sinf(theta_norm[0]);
	cst[2] = 1.0f - cst[0];
	theta_norm[1] = norm(axis);
	a[0] = axis->x / theta_norm[1];
	a[1] = axis->y / theta_norm[1];
	a[2] = axis->z / theta_norm[1];
	n[0] = n1->x;
	n[1] = n1->y;
	n[2] = n1->z;
	n1->x = n[0] * (cst[0] + a[0] * a[0] * cst[2])
		+ n[1] * (a[0] * a[1] * cst[2] - a[2] * cst[1])
		+ n[2] * (a[0] * a[2] * cst[2] + a[1] * cst[1]);
	n1->y = n[0] * (a[1] * a[0] * cst[2] + a[2] * cst[1])
		+ n[1] * (cst[0] + a[1] * a[1] * cst[2])
		+ n[2] * (a[1] * a[2] * cst[2] - a[0] * cst[1]);
	n1->z = n[0] * (a[2] * a[0] * cst[2] - a[1] * cst[1])
		+ n[1] * (a[2] * a[1] * cst[2] + a[0] * cst[1])
		+ n[2] * (cst[0] + a[2] * a[2] * cst[2]);
}

int	handle_pl_rotation(t_plane *pl, int keycode)
{
	float	rot_degree;

	rot_degree = 12.0f;
	if (keycode == KEY_RIGHT)
	{
		rotation_axis(rot_degree, &(t_vec3){0, 1, 0}, &pl->orientation);
		return (1);
	}
	if (keycode == KEY_LEFT)
	{
		rotation_axis(-rot_degree, &(t_vec3){0, 1, 0}, &pl->orientation);
		return (1);
	}
	if (keycode == KEY_UP)
	{
		rotation_axis(rot_degree, &(t_vec3){1, 0, 0}, &pl->orientation);
		return (1);
	}
	if (keycode == KEY_DOWN)
	{
		rotation_axis(-rot_degree, &(t_vec3){1, 0, 0}, &pl->orientation);
		return (1);
	}
	return (0);
}

int	handle_cy_rotation(t_cylinder *cy, int keycode)
{
	float	rot_degree;

	rot_degree = 12.0f;
	if (keycode == KEY_RIGHT)
	{
		rotation_axis(rot_degree, &(t_vec3){0, 1, 0}, &cy->orientation);
		return (1);
	}
	if (keycode == KEY_LEFT)
	{
		rotation_axis(-rot_degree, &(t_vec3){0, 1, 0}, &cy->orientation);
		return (1);
	}
	if (keycode == KEY_UP)
	{
		rotation_axis(rot_degree, &(t_vec3){1, 0, 0}, &cy->orientation);
		return (1);
	}
	if (keycode == KEY_DOWN)
	{
		rotation_axis(-rot_degree, &(t_vec3){1, 0, 0}, &cy->orientation);
		return (1);
	}
	return (0);
}
