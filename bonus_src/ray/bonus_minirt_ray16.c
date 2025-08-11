/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:45:23 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:54:41 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to calculate the local normal vector
 * caculates wether the intersection is on a cap or the side of
 * the cylinder and returns a different normal vector depending on
 * that
 *
 * @param object_point	point in object/local space
 * @param obj			pobject
 * @return				normal[local] vector from calculation
 */
static t_tuple	calculate_local_normal(t_tuple object_point, t_object obj)
{
	t_float	obj_point_sqr[3];
	t_float	distance;
	t_tuple	local_normal;

	obj_point_sqr[x] = object_point.x * object_point.x;
	obj_point_sqr[z] = object_point.z * object_point.z;
	distance = obj_point_sqr[x] + obj_point_sqr[z];
	local_normal = vector(object_point.x, 0, object_point.z);
	if (distance < 1.0f + C_EPSILON && object_point.y >= obj.max - C_EPSILON)
		return (vector(0, -1, 0));
	if (distance < 1.0f + C_EPSILON && object_point.y <= obj.min + C_EPSILON)
		return (vector(0, 1, 0));
	return (local_normal);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cylinder cap
 * caculates the normal of a point/intersection on a cylinder cap
 *
 * @param obj			object(cylinder cap) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cylinder_cap(t_object obj, t_tuple world_point)
{
	t_matrix4	matrix[2];
	t_tuple		normal[2];

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	normal[local] = multiply_matrix4_tuple(matrix[inverse], world_point);
	normal[local] = calculate_local_normal(normal[local], obj);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}
