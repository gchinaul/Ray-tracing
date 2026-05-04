/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:31:16 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "cone.h"
#include "errors.h"
#include "miniRT.h"
#include "scene_parser.h"

void	init_cone_material(t_cone *cone)
{
	cone->ka = 0.1f;
	cone->kd = 0.7f;
	cone->ks = 0.3f;
	cone->pe = 16;
	cone->kr = 0.0f;
	cone->angle = atanf(cone->radius / cone->height);
	cone->bmap_name = NULL;
	cone->bmap = NULL;
	cone->scale = 1.0f;
	cone->intensity = 1.0f;
	cone->bbox = compute_cone_aabb(cone);
}

int	validate_cone_params(t_cone *cone, char **tokens)
{
	cone->radius = ft_atof(tokens[3]) / 2.0f;
	if (cone->radius <= 0)
		return (1);
	cone->height = ft_atof(tokens[4]);
	if (cone->height <= 0)
		return (1);
	return (0);
}
