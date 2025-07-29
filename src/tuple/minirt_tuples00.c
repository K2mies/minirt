/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:13:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:08 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to create and return a tuple
 * of t_tuple type for which w is custom;
 *
 * @param x		x variable of t_float type
 * @param y		y variable of t_float type
 * @param z		z variable of t_float type
 * @param w		w variable of t_float type
 *
 * @return		tuple of t_tuple type
 */
t_tuple	tuple(t_float x, t_float y, t_float z, t_float w)
{
	t_tuple tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

/**
 * Function to create and return a Point
 * of t_point4 type for which w = 1;
 *
 * @param x		x variable of t_float type
 * @param y		y variable of t_float type
 * @param z		z variable of t_float type
 *
 * @return		Vector of t_vec4 type
 */
t_tuple	point(t_float x, t_float y, t_float z)
{
	t_tuple	point;

	point.x = x;
	point.y = y;
	point.z = z;
	point.w = 1;
	return (point);
}

/**
 * Function to create and return a Vector
 * of t_vec4 type for which w = 0
 *
 * @param x		x variable of t_float type
 * @param y		y variable of t_float type
 * @param z		z variable of t_float type
 *
 * @return		Vector of t_vec4 type
 */
t_tuple	vector(const t_float x, t_float y, t_float z)
{
	t_tuple	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0;
	return (vector);
}
