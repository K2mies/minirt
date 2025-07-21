/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:33:15 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:11:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	intersections  of a ray and a cube
 * creates a hit value from ray hitting a cube
 * and returns as two values if there is a hit, 0 if 
 * it is a miss.
 *
 * @param sphere	plane object to be intersected
 * @param ray		Ray to cast
 * @return	t_intersections	result of intersections
 */
t_intersections	cube_intersection(t_object *cube, t_ray ray)
{
	t_cube_intersect_param	p;
	t_intersections			res;

	ray = transform(ray, inverse_matrix4(cube->transform));
	cube->saved_ray = ray;
	check_axis(ray.origin.x, ray.direction.x, &p.xt[min], &p.xt[max]);
	check_axis(ray.origin.y, ray.direction.y, &p.yt[min], &p.yt[max]);
	check_axis(ray.origin.z, ray.direction.z, &p.zt[min], &p.zt[max]);
	res.t[0] = max_3(p.xt[min], p.yt[min], p.zt[min]);
	res.t[1] = min_3(p.xt[max], p.yt[max], p.zt[max]);
	if (res.t[0] > res.t[1])
	{
		res.count = 0;
		return (res);
	}
	res.count = 2;
	return (res);
}

