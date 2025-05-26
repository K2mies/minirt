/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:19:31 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/26 11:24:18 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to compare two 4X4 Matrices
 *
 * @param a		pointer to first 4x4 matrix
 * @param b		pointer to second 4x4 matrix
 *
 * @return		true if matrices are equal false if not
 */
bool	compare_matrix4(t_matrix4 *a, t_matrix4 *b)
{
	if (compare_floats(a->m[0][0], b->m[0][0])
		&& compare_floats(a->m[0][1], b->m[0][1])
		&& compare_floats(a->m[0][2], b->m[0][2])
		&& compare_floats(a->m[0][3], b->m[0][3])
		&& compare_floats(a->m[1][0], b->m[1][0])
		&& compare_floats(a->m[1][2], b->m[1][2])
		&& compare_floats(a->m[1][3], b->m[1][3])
		&& compare_floats(a->m[2][0], b->m[2][0])
		&& compare_floats(a->m[2][1], b->m[2][1])
		&& compare_floats(a->m[2][2], b->m[2][2])
		&& compare_floats(a->m[2][3], b->m[2][3])
		&& compare_floats(a->m[3][0], b->m[3][0])
		&& compare_floats(a->m[3][1], b->m[3][1])
		&& compare_floats(a->m[3][2], b->m[3][2])
		&& compare_floats(a->m[3][3], b->m[3][3]))
		return (true);
	return (false);
}

/**
 * Function to compare two 3X3 Matrices
 *
 * @param a		pointer to first 3x3 matrix
 * @param b		pointer to second 3x3 matrix
 *
 * @return		true if matrices are equal false if not
 */
bool	compare_matrix3(t_matrix3 *a, t_matrix3 *b)
{
	if (compare_floats(a->m[0][0], b->m[0][0])
		&& compare_floats(a->m[0][1], b->m[0][1])
		&& compare_floats(a->m[0][2], b->m[0][2])
		&& compare_floats(a->m[1][0], b->m[1][0])
		&& compare_floats(a->m[1][1], b->m[1][1])
		&& compare_floats(a->m[1][2], b->m[1][2])
		&& compare_floats(a->m[2][0], b->m[2][0])
		&& compare_floats(a->m[2][1], b->m[2][1])
		&& compare_floats(a->m[2][2], b->m[2][2]))
		return (true);
	return (false);
}

/**
 * Function to compare two 2X2 Matrices
 *
 * @param a		pointer to first 2x2 matrix
 * @param b		pointer to second 2x2 matrix
 *
 * @return		true if matrices are equal false if not
 */
bool	compare_matrix2(t_matrix2 *a, t_matrix2 *b)
{
	if (compare_floats(a->m[0][0], b->m[0][0])
		&& compare_floats(a->m[0][1], b->m[0][1])
		&& compare_floats(a->m[1][0], b->m[1][0])
		&& compare_floats(a->m[1][1], b->m[1][1]))
		return (true);
	return (false);
}
