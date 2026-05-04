/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 09:08:33 by van               #+#    #+#             */
/*   Updated: 2025/09/05 17:02:21 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_UTILS_H
# define FREE_UTILS_H

# include "cone.h"

//	delete_rt.c
void		delete_rt(t_rt *rt);
void		delete_bvh(t_bvhnode *head);
void		delete_scn(t_scn *scn);
void		free_lights(t_light *lights);
void		delete_bmaps(t_bump_map *maps);
//	delete_rt2.c
void		free_planes(t_plane *planes);
void		free_plane(t_plane *plane);
void		free_cones(t_cone *cones);
void		free_cone(t_cone *cone);

#endif
