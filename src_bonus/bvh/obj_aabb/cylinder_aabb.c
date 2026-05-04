/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_aabb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:36:41 by van               #+#    #+#             */
/*   Updated: 2025/09/05 17:09:40 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// version approxiamtive moins couteuse (box plus large)
t_aabb	compute_cylinder_aabb_safe(t_cylinder *cyl)
{
	float	r_max;
	t_vec3	top;

	r_max = (cyl->diameter / 2) * sqrtf(2.0f);
	top = (t_vec3){
		cyl->coo.x + cyl->orientation.x * cyl->height,
		cyl->coo.y + cyl->orientation.y * cyl->height,
		cyl->coo.z + cyl->orientation.z * cyl->height
	};
	return ((t_aabb){
		.min = {
			fminf(cyl->coo.x, top.x) - r_max,
			fminf(cyl->coo.y, top.y) - r_max,
			fminf(cyl->coo.z, top.z) - r_max
		},
		.max = {
			fmaxf(cyl->coo.x, top.x) + r_max,
			fmaxf(cyl->coo.y, top.y) + r_max,
			fmaxf(cyl->coo.z, top.z) + r_max
		}
	});
}

// // version approxiamtive moins couteuse (box plus large)
// t_aabb	compute_cylinder_aabb_safe(t_cylinder *cyl)
// {
// 	// Rayon maximal projeté sur chaque axe
// 	float r_max = (cyl->diameter / 2) * sqrtf(2.0f);
		// ← Correction clé (sqrt(2) pour le pire cas)

// 	t_vec3 top = {
// 		cyl->coo.x + cyl->orientation.x * cyl->height,
// 		cyl->coo.y + cyl->orientation.y * cyl->height,
// 		cyl->coo.z + cyl->orientation.z * cyl->height
// 	};

// 	return (t_aabb){
// 		.min = {
// 			fminf(cyl->coo.x, top.x) - r_max,
// 			fminf(cyl->coo.y, top.y) - r_max,
// 			fminf(cyl->coo.z, top.z) - r_max
// 		},
// 		.max = {
// 			fmaxf(cyl->coo.x, top.x) + r_max,
// 			fmaxf(cyl->coo.y, top.y) + r_max,
// 			fmaxf(cyl->coo.z, top.z) + r_max
// 		}
// 	};
// }

// //	version rigoureuse et plus couteuse
// t_aabb	compute_cylinder_aabb(t_cylinder *cyl)
// {
// 	t_vec3 top_center = {
// 		cyl->coo.x + cyl->orientation.x * cyl->height,
// 		cyl->coo.y + cyl->orientation.y * cyl->height,
// 		cyl->coo.z + cyl->orientation.z * cyl->height
// 	};

// 	// Vecteurs orthogonaux à l'orientation
// 	t_vec3 axis = cyl->orientation;
// 	t_vec3 u, v;

// 	// Trouver un vecteur perpendiculaire arbitraire
// 	if (fabsf(axis.x) > 0.1f) {
// 		u = (t_vec3){-axis.y, axis.x, 0.0f};
// 	} else {
// 		u = (t_vec3){0.0f, -axis.z, axis.y};
// 	}
// 	normalize(&u);
// 	v = cross(&axis, &u);

// 	// Points extrêmes du cercle (base inférieure)
// 	t_vec3 bottom[4] = {
// 		{cyl->coo.x + (cyl->diameter / 2) * u.x,
// 		 cyl->coo.y + (cyl->diameter / 2) * u.y,
// 		 cyl->coo.z + (cyl->diameter / 2) * u.z},
// 		{cyl->coo.x - (cyl->diameter / 2) * u.x,
// 		 cyl->coo.y - (cyl->diameter / 2) * u.y,
// 		 cyl->coo.z - (cyl->diameter / 2) * u.z},
// 		{cyl->coo.x + (cyl->diameter / 2) * v.x,
// 		 cyl->coo.y + (cyl->diameter / 2) * v.y,
// 		 cyl->coo.z + (cyl->diameter / 2) * v.z},
// 		{cyl->coo.x - (cyl->diameter / 2) * v.x,
// 		 cyl->coo.y - (cyl->diameter / 2) * v.y,
// 		 cyl->coo.z - (cyl->diameter / 2) * v.z}
// 	};

// 	// Points extrêmes du cercle (base supérieure)
// 	t_vec3 top[4];
// 	for (int i = 0; i < 4; i++) {
// 		top[i] = (t_vec3){
// 			top_center.x + bottom[i].x - cyl->coo.x,
// 			top_center.y + bottom[i].y - cyl->coo.y,
// 			top_center.z + bottom[i].z - cyl->coo.z
// 		};
// 	}

// 	// Calcul des min/max
// 	t_aabb bbox = {
// 		.min = {INFINITY, INFINITY, INFINITY},
// 		.max = {-INFINITY, -INFINITY, -INFINITY}
// 	};

// 	for (int i = 0; i < 4; i++) {
// 		// Base inférieure
// 		bbox.min.x = fminf(bbox.min.x, bottom[i].x);
// 		bbox.min.y = fminf(bbox.min.y, bottom[i].y);
// 		bbox.min.z = fminf(bbox.min.z, bottom[i].z);

// 		bbox.max.x = fmaxf(bbox.max.x, bottom[i].x);
// 		bbox.max.y = fmaxf(bbox.max.y, bottom[i].y);
// 		bbox.max.z = fmaxf(bbox.max.z, bottom[i].z);

// 		// Base supérieure
// 		bbox.min.x = fminf(bbox.min.x, top[i].x);
// 		bbox.min.y = fminf(bbox.min.y, top[i].y);
// 		bbox.min.z = fminf(bbox.min.z, top[i].z);

// 		bbox.max.x = fmaxf(bbox.max.x, top[i].x);
// 		bbox.max.y = fmaxf(bbox.max.y, top[i].y);
// 		bbox.max.z = fmaxf(bbox.max.z, top[i].z);
// 	}

// 	return bbox;
// }
