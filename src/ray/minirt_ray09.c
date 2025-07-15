/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:05:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/11 10:23:09 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"
/**
 * @brief	helper function to reduce duplication
 * Checks to see if the intersection at t is within a radus
 * of the object from the y axis
 *
 * @param ray		ray to use for calculation
 * @param t			t value to check
 * @param cylinder	pointer to the cylinder object to operate on
 * @return			t_float calculation
 */
static t_float	check_cap(t_ray ray, t_float t, t_object *obj)
{
	t_float	x;
	t_float	z;
	x = ray.origin.x + (t * ray.direction.x);
	z = ray.origin.z + (t * ray.direction.z);
	return (((x * x) + (z * z)) <= obj->radius);
}

/**
 * @brief	intersections  of a ray and a cylinder
 *
 * @param cylinder	cylinder object to be intersected
 * @param ray		Ray to cast
 * @return			t_intersections	result of intersections
 */
t_intersections	intersect_cylinder_caps(t_object *cylinder, t_ray ray, t_intersections xs)
{
	if (cylinder->closed == false || compare_floats(ray.direction.y, 0.0f))
		return (xs);
	xs.t[2] = (cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, xs.t[2], cylinder))
		xs.count += 1;
	xs.t[3] = (cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, xs.t[3], cylinder) )
		xs.count += 1;
	return (xs);
}

/**
 * @brief	intersections  of a ray and a cone
 *
 * @param cylinder	cone object to be intersected
 * @param ray		Ray to cast
 * @return			t_intersections	result of intersections
 */
t_intersections	intersect_cone_caps(t_object *cone, t_ray ray, t_intersections xs)
{
	xs.t[1] = (cone->height - ray.origin.y) / ray.direction.y;
	if (xs.t[1] > EPSILON && check_cap(ray, xs.t[2], cone))
	{
		xs.count += 1;
	}
	return (xs);
}
