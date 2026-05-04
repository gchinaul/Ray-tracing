/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: van <van@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:46:51 by van               #+#    #+#             */
/*   Updated: 2025/09/05 16:10:59 by van              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

void	product_mat_vec(int N, float mat[N][N], float vec[N], float result[N]);
void	product_mat_mat(int N, float A[N][N], float B[N][N],
			float result[N][N]);
void	rotation_y(int N, float angle_deg, float R[N][N]);

#endif
