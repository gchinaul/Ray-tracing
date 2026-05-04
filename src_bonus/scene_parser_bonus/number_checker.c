/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:57:21 by van               #+#    #+#             */
/*   Updated: 2025/09/05 07:29:02 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// check each scene object for a valid number
int	check_number(t_scn_el_lst **lst)
{
	t_scn_el_lst	*current;
	int				acl_count[3];
	int				i;

	i = -1;
	while (++i < 3)
		acl_count[i] = 0;
	current = *lst;
	while (current)
	{
		if (!ft_strncmp(current->id, "A", 2))
			acl_count[0]++;
		if (!ft_strncmp(current->id, "C", 2))
			acl_count[1]++;
		if (!ft_strncmp(current->id, "L", 2))
			acl_count[2]++;
		current = current->next;
	}
	if (err_acl_count(acl_count))
		return (1);
	return (0);
}

int	err_acl_count(int *acl_count)
{
	if (acl_count[0] == 0)
		return (err(1, "Error\nAmbient lighting required\n"));
	if (acl_count[0] > 1)
		return (err(1, "Error\nOnly one ambient lighting accepted\n"));
	if (acl_count[1] == 0)
		return (err(1, "Error\nCamera required\n"));
	if (acl_count[1] > 1)
		return (err(1, "Error\nOnly one camera accepted\n"));
	return (0);
}
