/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parser1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:43:23 by van               #+#    #+#             */
/*   Updated: 2025/08/28 18:55:18 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// check the .rt format, ! can set lst data even in case of error
int	parse_scene(char *file, t_scn_el_lst **lst)
{
	int		fd;

	if (ft_strlen(file) < 3 || ft_strncmp(file + ft_strlen(file) - 3, ".rt", 3))
		return (err(1, "File is not .rt\n"));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\nCan't open file\n", 22);
		perror("open");
		return (1);
	}
	if (set_nodes(fd, lst))
	{
		close (fd);
		return (1);
	}
	close (fd);
	return (0);
}

// read the file and transform each line in a node
int	set_nodes(int fd, t_scn_el_lst **lst)
{
	char	*line;

	line = (void *)1;
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_made_of(line, " \t\n"))
		{
			free (line);
			continue ;
		}
		if (set_node (lst, line))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	if (check_data(lst))
		return (1);
	print_datas(lst);
	return (0);
}

// tranform the given line into a node and appends it to lst
int	set_node(t_scn_el_lst **lst, char *line)
{
	t_scn_el_lst	*node;

	node = new_node();
	if (node == NULL)
		return (1);
	node->data = ft_split2(line, " \t\n");
	if (node->data == NULL)
	{
		free (node);
		return (1);
	}
	if (append_node(lst, node))
		return (1);
	return (0);
}

// print lst datas (debugging)
void	print_datas(t_scn_el_lst **lst)
{
	t_scn_el_lst	*current;
	int				i;

	if (lst == NULL || *lst == NULL)
		return ;
	i = 0;
	current = *lst;
	while (current)
	{
		printf("--i: %d\n", ++i);
		print_arr(current->data);
		current = current->next;
	}
	printf("\n\n");
}
