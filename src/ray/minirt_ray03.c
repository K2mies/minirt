/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:07:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/08 16:08:21 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	intersections  of a ray and a sphere
 * creates a decriminant value from ray hitting a sphere
 * and returns as two values if there is a hit, 0 if 
 * it is a miss.
 *
 * @param sphere	sphere object to be intersected
 * @param ray		Ray to cast
 * @return	t_intersections	result of intersections
 */
t_intersections	sphere_intersection(t_object *sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	t_float var[3];
	t_float	discriminant;
	t_intersections	res;

	ray = transform(ray, inverse_matrix4(sphere->transform));
	sphere->saved_ray = ray;
	sphere_to_ray = sub_tuples(ray.origin, sphere->origin);	
	var[a] = dot_product(ray.direction, ray.direction);
	var[b] = 2.0 * dot_product(ray.direction, sphere_to_ray);
	var[c] = dot_product(sphere_to_ray, sphere_to_ray)
			- (sphere->radius * sphere->radius);
	discriminant = (var[b] * var[b]) - (4.0 * var[a] * var[c]);
	if (discriminant < 0)
	{
		res.count = 0;
		return (res);
	}
	res.t[0] = (-var[b] - sqrtf(discriminant)) / (2.0 * var[a]);
	res.t[1] = (-var[b] + sqrtf(discriminant)) / (2.0 * var[a]);
	res.count = 2;
	return (res);
}
