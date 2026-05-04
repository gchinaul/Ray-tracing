/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 13:06:26 by van               #+#    #+#             */
/*   Updated: 2025/09/10 16:28:15 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bump_map.h"
#include "bvh.h"
#include "free_utils.h"
#include "miniRT.h"

void	delete_rt(t_rt *rt)
{
	delete_scn(&rt->scn);
	mlx_free(&rt->mlx);
}

void	delete_scn(t_scn *scn)
{
	free(scn->amb);
	free(scn->cam);
	free_lights(scn->lights);
	delete_objs(&scn->objs);
	free_planes(scn->planes);
}

void	free_lights(t_light *lights)
{
	if (lights == NULL)
		return ;
	while (lights->next)
	{
		lights = lights->next;
		free(lights->prev);
	}
	free(lights);
}
