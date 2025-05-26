/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix06.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:33:35 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/26 11:51:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to check if matrix is invertable or not
 *
 * @param m		matrix to check 
 *
 * @return		true if matrix is invertable, false if it is not
 */
bool	is_matrix4_invertable(t_matrix4 m)
{
	if (determinent_of_matrix4(m) == 0)
		return (false);
	return (true);
}

/**
 * Function to return the inverse of a matrix
 *
 * @param m		matrix to return inverse of
 *
 * @return		inverse matrix4
 */
t_matrix4	inverse_matrix4(t_matrix4 m)
{
	t_matrix4	res;
	int			row;
	int			col;
	t_float		c;

	if (is_matrix4_invertable(m) == false)
	{
		printf("matrix is not invertable\n");
		return (m);
	}
	row = -1;
	while (++row < 4)
	{
		col = -1;
		while (++col < 4)
		{
			c = cofactor4(m, row, col);
			res.m[col][row] = c / determinent_of_matrix4(m);
		}
	}
	return (res);
}
