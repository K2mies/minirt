/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:28:39 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:10:05 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to transpose a 4X4 Matrix
 *
 * @param m		a 4x4 matrix to tranpose
 *
 * @return		new transposed matrix
 */
t_matrix4	transpose_matrix4(t_matrix4 m)
{
	t_matrix4	res;

	res.m[0][0] = m.m[0][0];
	res.m[0][1] = m.m[1][0];
	res.m[0][2] = m.m[2][0];
	res.m[0][3] = m.m[3][0];
	res.m[1][0] = m.m[0][1];
	res.m[1][1] = m.m[1][1];
	res.m[1][2] = m.m[2][1];
	res.m[1][3] = m.m[3][1];
	res.m[2][0] = m.m[0][2];
	res.m[2][1] = m.m[1][2];
	res.m[2][2] = m.m[2][2];
	res.m[2][3] = m.m[3][2];
	res.m[3][0] = m.m[0][3];
	res.m[3][1] = m.m[1][3];
	res.m[3][2] = m.m[2][3];
	res.m[3][3] = m.m[3][3];
	return (res);
}

/**
 * Function to return determinent of a 2x2 Matrix
 *
 * @param m		a pointer to a 2x2 matrix to calculate determinent of
 *
 * @return		determinent as a t_float 
 */
t_float	determinent_of_matrix2(t_matrix2 m)
{
	t_float	res;

	res = (m.m[0][0] * m.m[1][1]) - (m.m[0][1] * m.m[1][0]);
	return (res);
}

/**
 * Function to return determinent of a 3x3 Matrix
 *
 * @param m		a 3x3 matrix to calculate determinent of
 *
 * @return		determinent as a t_float 
 */
t_float	determinent_of_matrix3(t_matrix3 m)
{
	t_float	res;

	res = (m.m[0][0] * cofactor3(m, 0, 0))
		+ (m.m[0][1] * cofactor3(m, 0, 1))
		+ (m.m[0][2] * cofactor3(m, 0, 2));
	return (res);
}

/**
 * Function to return determinent of a 4x4 Matrix
 *
 * @param m		a 4x4 matrix to calculate determinent of
 *
 * @return		determinent as a t_float 
 */
t_float	determinent_of_matrix4(t_matrix4 m)
{
	t_float	res;

	res = (m.m[0][0] * cofactor4(m, 0, 0))
		+ (m.m[0][1] * cofactor4(m, 0, 1))
		+ (m.m[0][2] * cofactor4(m, 0, 2))
		+ (m.m[0][3] * cofactor4(m, 0, 3));
	return (res);
}
