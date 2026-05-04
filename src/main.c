/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:17:52 by van               #+#    #+#             */
/*   Updated: 2025/09/10 17:38:29 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * clear; valgrind --leak-check=full --show-leak-kinds=all -s ./miniRT maps/.rt
 */

void	set_rt_null(t_rt *rt)
{
	rt->bvh = NULL;
	rt->mlx.mlx = NULL;
	rt->mlx.win = NULL;
	rt->mlx.img = NULL;
	rt->b_maps = NULL;
	rt->selected.type = CAM;
	rt->selected.cam = NULL;
	rt->selected.lights = NULL;
	rt->selected.objs = NULL;
	rt->selected.planes = NULL;
	rt->scn.amb = NULL;
	rt->scn.cam = NULL;
	rt->scn.lights = NULL;
	rt->scn.objs = NULL;
	rt->scn.planes = NULL;
	rt->scn.cones = NULL;
	rt->scn.arr = NULL;
	rt->scn.bvh = NULL;
	rt->scn.objs_count = 0;
}

/* bonus */
static int	init_data_and_scene(char *map_file, t_rt *data,
		t_scn_el_lst **scn_el)
{
	*scn_el = NULL;
	if (parse_scene(map_file, scn_el))
	{
		delete_lst(scn_el);
		return (1);
	}
	set_rt_null(data);
	if (init_scene(scn_el, &data->scn))
	{
		delete_lst(scn_el);
		delete_scn(&data->scn);
		return (1);
	}
	delete_lst(scn_el);
	return (0);
}

static void	setup_selected_objects(t_rt *data)
{
	data->selected.cam = data->scn.cam;
	data->selected.lights = data->scn.lights;
	data->selected.objs = data->scn.objs;
	data->selected.planes = data->scn.planes;
	data->selected.type = CAM;
}

static int	init_graphics_and_bvh(t_rt *data, t_hook *hook)
{
	if (mlx_ini(&data->mlx, WIDTH, HEIGHT, "Window 1"))
	{
		delete_rt(data);
		return (1);
	}
	if (init_img(data->mlx.mlx, data->mlx.img, WIDTH, HEIGHT))
	{
		delete_rt(data);
		return (1);
	}
	hook->mlx = &data->mlx;
	hook->extra_data = data;
	return (0);
}

int	main(int argc, char **argv)
{
	t_rt			data;
	t_scn_el_lst	*scn_el;
	t_hook			hook;

	printf("MANDATORY\n");
	if (argc <= 1)
		return (err(1, "No map provided\n"));
	if (init_data_and_scene(argv[1], &data, &scn_el))
		return (1);
	setup_selected_objects(&data);
	print_scn(&data.scn);
	if (init_graphics_and_bvh(&data, &hook))
		return (1);
	render_img(&data);
	mlx_hook(data.mlx.win, 2, 1L << 0, win_key_handler, &hook);
	mlx_hook(data.mlx.win, 17, 1L << 17, close_window, &hook);
	mlx_loop(data.mlx.mlx);
	delete_rt(&data);
	return (0);
}
