/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:09:14 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/27 11:09:54 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

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
