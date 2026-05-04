/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 22:00:00 by van               #+#    #+#             */
/*   Updated: 2025/09/09 10:09:55 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_UTILS_H
# define CONE_UTILS_H

typedef struct s_quad_params
{
	float	a;
	float	b;
	float	c;
	float	*t0;
	float	*t1;
}	t_quad_params;

typedef struct s_cone_coeffs
{
	float	*a;
	float	*b;
	float	*c;
}	t_cone_coeffs;

bool	solve_quadratic(float a, float b, float c, float *t);
bool	check_cone_height(t_ray *ray, t_cone *cone, float t);
bool	ray_cone_side_intersect(t_ray *ray, t_cone *cone, float *t_out);
t_vec3	get_cone_apex(t_cone *cone);
bool	is_point_on_cone_side(t_ray *ray, t_cone *cone, float t);

#endif
