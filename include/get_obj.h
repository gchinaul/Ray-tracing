/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:19:12 by van               #+#    #+#             */
/*   Updated: 2025/08/10 17:46:34 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_OBJ_H
# define GET_OBJ_H

typedef struct s_scn_obj	t_scn_obj;
typedef enum e_obj_type		t_obj_type;

t_scn_obj					*get_obj(t_scn_obj *objs, t_obj_type type);

#endif
