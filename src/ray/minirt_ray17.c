/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray17.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:46:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:57:53 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_float	calculate_distance(t_tuple object_point)
{
	t_float	res;
	t_float	obj_point_sqr[3];

	obj_point_sqr[x] = object_point.x * object_point.x;
	obj_point_sqr[z] = object_point.z * object_point.z;
	res = obj_point_sqr[x] + obj_point_sqr[z];
	return (res);
}

static t_tuple	calculate_local_normal(t_tuple object_point)
{
	t_float	distance;
	t_tuple	local_normal;

	distance = calculate_distance(object_point);
	local_normal = vector(object_point.x, distance, object_point.z);
	if (distance > 0.0f)
		local_normal.y = -local_normal.y;
	if (get_magnitude(local_normal) < EPSILON)
		return (vector(0, 0, 0));
	return (local_normal);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cone
 * caculates the normal of a point/intersection on a cone
 *
 * @param obj			object(cone) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cone(t_object obj, t_tuple world_point)
{
	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_tuple		object_point;

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	normal[local] = calculate_local_normal(object_point);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}
