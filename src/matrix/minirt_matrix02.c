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

/**
 * Function to multiply a tuple by a 4X4 Matrices
 *
 * @param a		pointer to 4x4 matrix
 * @param b		pointer to tuple to multiply
 *
 * @return		new tuple with multiplied values
 */
t_tuple matrix4_multiply_tuple(t_matrix4 *m, t_tuple *t)
{
    t_tuple res;

    res.x = m->m[0][0] * t->x + m->m[0][1] * t->y + m->m[0][2] * t->z + m->m[0][3] * t->w;
    res.y = m->m[1][0] * t->x + m->m[1][1] * t->y + m->m[1][2] * t->z + m->m[1][3] * t->w;
    res.z = m->m[2][0] * t->x + m->m[2][1] * t->y + m->m[2][2] * t->z + m->m[2][3] * t->w;
    res.w = m->m[3][0] * t->x + m->m[3][1] * t->y + m->m[3][2] * t->z + m->m[3][3] * t->w;
//  not sure what this is doing in the case that w > 1; 
//    if (res.w != 1 && res.w != 0)
//    {
//        res.x /= res.w;
//        res.y /= res.w;
//        res.z /= res.w;
//    }
    return (res);

}
