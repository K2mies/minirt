/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples05.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 15:33:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/14 15:51:51 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to get the dot product from two vectors
 *
 * @param a		Vector a
 * @param b		Vector b
 *
 * @return		dot product of Vector a and Vector b
 */
t_float	dot_product(t_tuple *a, t_tuple *b)
{
	t_float res;

	res = (a->x * b->x) + (a->y * b->y) + (a->z * b->z) + (a->w * b->w);
	return (res);
}

/**
 * Function to get the cross product from two vectors
 *
 * @param a		Vector a
 * @param b		Vector b
 *
 * @return		cross product of Vector a and Vector b
 */
t_tuple	cross_product(t_tuple *a, t_tuple *b)
{
	t_tuple res;
	t_float		x;
	t_float		y;
	t_float		z;

	x = (a->y * b->z) - (a->z * b->y);
	y = (a->z * b->x) - (a->x * b->z);
	z = (a->x * b->y) - (a->y * b->x);
	res = vector(x, y, z);
	return (res);

}
