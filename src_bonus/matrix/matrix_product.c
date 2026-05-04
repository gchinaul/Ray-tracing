/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchinaul <gchinaul@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:36:59 by van               #+#    #+#             */
/*   Updated: 2025/09/06 20:14:57 by gchinaul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include "bonus_utils.h"

static void	multiply_row_vec(t_mat_vec_params *p, int row)
{
	int	j;

	p->result[row] = 0.0;
	j = 0;
	while (j < p->n)
	{
		p->result[row] += p->mat[row][j] * p->vec[j];
		j++;
	}
}

void	product_mat_vec(int n, float mat[][3], float vec[3], float result[3])
{
	t_mat_vec_params	p;
	int					i;

	p = (t_mat_vec_params){n, mat, vec, result};
	i = 0;
	while (i < n)
	{
		multiply_row_vec(&p, i);
		i++;
	}
}

static void	calc_mat_element(t_mat_calc_params *p)
{
	int	k;

	p->result[p->i][p->j] = 0.0;
	k = 0;
	while (k < p->n)
	{
		p->result[p->i][p->j] += p->a[p->i][k] * p->b[k][p->j];
		k++;
	}
}

void	product_mat_mat(int n, float a[][3], float b[][3], float result[][3])
{
	t_mat_calc_params	p;
	int					i;
	int					j;

	p = (t_mat_calc_params){n, a, b, result, 0, 0};
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			p.i = i;
			p.j = j;
			calc_mat_element(&p);
			j++;
		}
		i++;
	}
}

void	rotation_y(int n, float angle_deg, float r[][3])
{
	float	angle_rad;
	float	c;
	float	s;

	angle_rad = angle_deg * M_PI / 180.0;
	c = cos(angle_rad);
	s = sin(angle_rad);
	r[0][0] = c;
	r[0][1] = 0;
	r[0][2] = s;
	r[1][0] = 0;
	r[1][1] = 1;
	r[1][2] = 0;
	r[2][0] = -s;
	r[2][1] = 0;
	r[2][2] = c;
	(void)n;
}
