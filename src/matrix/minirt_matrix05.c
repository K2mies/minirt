/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix05.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:00:40 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:10:07 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to calculate the minor of a 4x4 matrix
 *
 * @param m		a 4x4 matrix to tranpose
 * @param row	row to knock out of 4x4 matrix
 * @param row	column to knock out of 4x4 matrix
 *
 * @return		the resulting minor (determinent of matrix2)
 */
t_float	minor4(t_matrix4 m, int row, int col)
{
	t_matrix3	sub_m3;
	t_float		res;

	sub_m3 = submatrix4(m, row, col);
	res = determinent_of_matrix3(sub_m3);
	return (res);
}

/**
 * Function to calculate the minor of a 3x3 matrix
 *
 * @param m		a 3x3 matrix to tranpose
 * @param row	row to knock out of 3x3 matrix
 * @param row	column to knock out of 3x3 matrix
 *
 * @return		the resulting minor (determinent of matrix2)
 */
t_float	minor3(t_matrix3 m, int row, int col)
{
	t_matrix2	sub_m2;
	t_float		res;

	sub_m2 = submatrix3(m, row, col);
	res = determinent_of_matrix2(sub_m2);
	return (res);
}

/**
 * Function to calculate the cofactor of a 3x3 matrix
 *
 * @param m		a 3x3 matrix to calculate
 * @param row	row to knock out of 3x3 matrix
 * @param row	column to knock out of 3x3 matrix
 *
 * @return		the resulting cofactor (minor of matrixi3x3)
 */
t_float	cofactor4(t_matrix4 m, int row, int col)
{
	t_float	res;

	res = minor4(m, row, col);
	if ((row + col) % 2 != 0)
		res = -res;
	return (res);
}

/**
 * Function to calculate the cofactor of a 3x3 matrix
 *
 * @param m		a 3x3 matrix to calculate
 * @param row	row to knock out of 3x3 matrix
 * @param row	column to knock out of 3x3 matrix
 *
 * @return		the resulting cofactor (minor of matrixi3x3)
 */
t_float	cofactor3(t_matrix3 m, int row, int col)
{
	t_float	res;

	res = minor3(m, row, col);
	if ((row + col) % 2 != 0)
		res = -res;
	return (res);
}
