/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix07.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:36:40 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/26 17:14:37 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to create and return a translation
 * matrix from a x,y,z
 *
 * @param x		x variable of t_float type
 * @param y		y variable of t_float type
 * @param z		z variable of t_float type
 *
 * @return		returns a translation matrix
 */
t_matrix4	translation(t_float x, t_float y, t_float z)
{
	t_matrix4	res;

	res = id_matrix4();
	res.m[0][3] = x;
	res.m[1][3] = y;
	res.m[2][3] = z;
	return (res);
}

/**
 * Function to create and return a scaling
 * matrix from a x,y,z
 *
 * @param x		x variable of t_float type
 * @param y		y variable of t_float type
 * @param z		z variable of t_float type
 *
 * @return		returns a scaling matrix
 */
t_matrix4	scaling(t_float x, t_float y, t_float z)
{
	t_matrix4	res;

	res = id_matrix4();
	res.m[0][0] = x;
	res.m[1][1] = y;
	res.m[2][2] = z;
	return (res);
}
