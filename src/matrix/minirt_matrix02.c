/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 17:05:24 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/23 17:27:26 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"


/**
 * Function to multiply two 4X4 Matrices
 *
 * @param a		pointer to first 4x4 matrix
 * @param b		pointer to second 4x4 matrix
 *
 * @return		new matrix with multiplied values
 */
t_matrix4	matrix4_multiply(t_matrix4 *a, t_matrix4 *b)
{
	t_matrix4	m;
	int			row;
	int			col;

	m = matrix4();

	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			m.m[row][col] = a->m[row][0] * b->m[0][col]
				+ a->m[row][1] * b->m[1][col]
				+ a->m[row][2] * b->m[2][col]
				+ a->m[row][3] * b->m[3][col];
		}
	}
	return (m);
}
