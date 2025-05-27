/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:47:25 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/27 16:16:02 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and returns a ray struct
 * creates a ray consisting of an origin (Point) and a direction (Vector)
 * and returns the two as a struct of t_ray type.
 *
 * @param origin	Point that is the origin of the ray
 * @param direction	Vector that gives the direction of the ray
 * @return	t_ray with both origin and direction stored within
 */
t_ray	ray(t_tuple origin, t_tuple direction)
{
	t_ray	res;

	res.origin = origin;
	res.direction = direction;
	return (res);
}

/**
 * @brief	gives the position of a ray at point t in length
 * gives the position of a ray point in time (t) along a certain direction
 * using ray.origin and ray.direction to caculate the ray.
 *
 * @param ray	ray struct to use to project the ray
 * @param t		t = time and given time along the ray to reach a point
 * @return		t_tuple that is the given point along the ray
 */
t_tuple	position(t_ray ray, t_float t)
{
	t_tuple	r;
	t_tuple res;

	r = multiply_tuple_by_scalar(ray.direction, t);
	res = add_tuples(ray.origin, r);


	return (res);
}
