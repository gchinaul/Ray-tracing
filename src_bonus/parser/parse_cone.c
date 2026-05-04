/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 00:00:00 by gchinaul          #+#    #+#             */
/*   Updated: 2025/09/09 11:31:26 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "cone.h"
#include "errors.h"
#include "miniRT.h"
#include "scene_parser.h"

static int	parse_cone_coords(t_cone *cone, char **tokens)
{
	char	**split;
	int		ret;

	split = ft_split(tokens[1], ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		free_split(split);
		return (err_coo_format(1, "CN", tokens[1]));
	}
	ret = set_vec3(&cone->coo, ft_atof(split[0]), ft_atof(split[1]),
			ft_atof(split[2]));
	free_split(split);
	return (ret);
}

static int	parse_cone_orientation(t_cone *cone, char **tokens)
{
	char	**split;
	int		ret;

	split = ft_split(tokens[2], ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		free_split(split);
		return (err_orientation_format(1, "CN", tokens[2]));
	}
	ret = set_vec3(&cone->orientation, ft_atof(split[0]), ft_atof(split[1]),
			ft_atof(split[2]));
	free_split(split);
	if (ret != 0)
		return (err_orientation_format(1, "CN", tokens[2]));
	normalize(&cone->orientation);
	return (0);
}

static int	parse_cone_color(t_cone *cone, char **tokens)
{
	char	**split;
	int		ret;

	split = ft_split(tokens[5], ',');
	if (!split || !split[0] || !split[1] || !split[2])
	{
		free_split(split);
		return (err_rgb_format(1, "CN", tokens[5]));
	}
	ret = set_vec3(&cone->rgb, ft_atof(split[0]), ft_atof(split[1]),
			ft_atof(split[2]));
	free_split(split);
	if (ret != 0)
		return (err_rgb_format(1, "CN", tokens[5]));
	cone->color = rgb_to_int(cone->rgb.x, cone->rgb.y, cone->rgb.z);
	return (0);
}

t_cone	*parse_cone(char **tokens, int *err)
{
	t_cone	*cone;

	if (!tokens[1] || !tokens[2] || !tokens[3] || !tokens[4] || !tokens[5])
		return (NULL);
	cone = (t_cone *)malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	ft_memset(cone, 0, sizeof(t_cone));
	if (parse_cone_coords(cone, tokens) || parse_cone_orientation(cone, tokens)
		|| validate_cone_params(cone, tokens) || parse_cone_color(cone, tokens))
	{
		free(cone);
		*err = 1;
		return (NULL);
	}
	init_cone_material(cone);
	return (cone);
}
