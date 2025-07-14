/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:30:24 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/08 15:33:03 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	intersections  of a ray and a plane
 * creates a hit value from ray hitting a plane
 * and returns as two values if there is a hit, 0 if 
 * it is a miss.
 *
 * @param sphere	plane object to be intersected
 * @param ray		Ray to cast
 * @return	t_intersections	result of intersections
 */
t_intersections	plane_intersection(t_object *plane, t_ray ray)
{
	t_intersections	res;

	ray = transform(ray, inverse_matrix4(plane->transform));
	plane->saved_ray = ray;
	if (fabsf(ray.direction.y) < EPSILON)
	{
		res.count = 0;
		return (res);
	}
	res.t[0] = -ray.origin.y / ray.direction.y;
	res.t[1] = res.t[0];
	res.count = 1;
	return (res);
}
