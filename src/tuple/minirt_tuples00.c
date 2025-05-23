/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_touples.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:13:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/13 14:39:10 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

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

//	point = malloc(sizeof(t_tuple));
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
t_tuple	vector(t_float x, t_float y, t_float z)
{
	t_tuple	vector;

//	vector = malloc(sizeof(t_tuple));
	vector.x = x;
	vector.y = y;
	vector.z = z;
	vector.w = 0;
	return (vector);
}
