/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderImg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:23:04 by van               #+#    #+#             */
/*   Updated: 2025/09/08 15:10:53 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	render_img(t_rt *rt)
{
	int			i;
	int			j;
	t_viewplane	vp;
	t_ray		ray;
	t_vec3		color;

	init_t_viewplane(&vp, rt->scn.cam, &rt->mlx);
	i = -1;
	while (++i < rt->mlx.height)
	{
		j = -1;
		while (++j < rt->mlx.width)
		{
			compute_new_ray(rt, &vp, &ray, (int [2]){i, j});
			color = (t_vec3){0, 0, 0};
			render_pixel(rt, &ray, 0, &color);
			tone_map(&color);
			clamp_rgb(&color);
			put_pixel(rt->mlx.img, j, i, rgb_vec3_to_int(&color));
		}
	}
	mlx_put_image_to_window(rt->mlx.mlx, rt->mlx.win, rt->mlx.img->img, 0, 0);
}

void	compute_new_ray(t_rt *rt, t_viewplane *vp, t_ray *ray, int *ij)
{
	t_vec3	tmp;

	tmp = scalar_mult(&vp->vec_right, (ij[1] + 0.5f) * vp->x_indent);
	ray->origin = add(&vp->top_left, &tmp);
	tmp = scalar_mult(&vp->vec_up, (ij[0] + 0.5f) * vp->y_indent);
	ray->origin = substract(&ray->origin, &tmp);
	ray->direction = substract(&ray->origin, &rt->scn.cam->coo);
	normalize(&ray->direction);
	ray->hit = NULL;
	ray->type = -1;
	ray->face = 0;
}

void	init_t_viewplane(t_viewplane *vp, t_camera *cam, t_mlx *mlx)
{
	t_vec3	vec_global_up;
	t_vec3	tmp;
	float	h;
	float	w;

	set_vp_hw(&h, &w, cam, mlx);
	vp->centre = add(&cam->coo, &cam->orientation);
	if (fabs(cam->orientation.y) > 0.99)
		vec_global_up = (t_vec3){1, 0, 0};
	else
		vec_global_up = (t_vec3){0, 1, 0};
	vp->vec_right = cross(&vec_global_up, &cam->orientation);
	normalize(&vp->vec_right);
	vp->vec_up = cross(&cam->orientation, &vp->vec_right);
	normalize(&vp->vec_up);
	tmp = scalar_mult(&vp->vec_right, w / 2);
	vp->top_left = substract(&vp->centre, &tmp);
	tmp = scalar_mult(&vp->vec_up, h / 2);
	vp->top_left = add(&vp->top_left, &tmp);
	vp->x_indent = w / mlx->width;
	vp->y_indent = h / mlx->height;
}

void	set_vp_hw(float *w, float *h, t_camera *cam, t_mlx *mlx)
{
	float	aspect_ratio;
	float	fov_radian;

	fov_radian = cam->fov_h * M_PI / 180.0f;
	aspect_ratio = (float)mlx->width / (float)mlx->height;
	*w = 2 * tan(fov_radian / 2);
	*h = *w / aspect_ratio;
}
