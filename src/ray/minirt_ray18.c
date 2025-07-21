/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray18.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:48:59 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:11:32 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to calculate the local normal vector
 * caculates wether the intersection is on a cap or the side of
 * the cone and returns a different normal vector depending on
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

	(void)obj;
//	(void)object_point;
	obj_point_sqr[x] = object_point.x * object_point.x;
	obj_point_sqr[z] = object_point.z * object_point.z;
	obj_point_sqr[y] = obj_point_sqr[x] + obj_point_sqr[z];
	obj_point_sqr[y] = obj_point_sqr[y] * obj_point_sqr[y];
	if (object_point.y > 0)
		obj_point_sqr[y] = -obj_point_sqr[y];
	distance = obj_point_sqr[x] + obj_point_sqr[z];
	local_normal = vector(object_point.x, obj_point_sqr[y], object_point.z);
//	if (distance > 0.0f)
//		local_normal.y = -local_normal.y;
//	if (get_magnitude(local_normal) < EPSILON)
//		return (vector(0, 0, 0));
	if (distance < 1.0f + C_EPSILON && object_point.y >= obj.max - C_EPSILON)
		local_normal = vector(0, 1, 0);
	if (distance < 1.0f + C_EPSILON && object_point.y <= obj.min + C_EPSILON)
		local_normal = vector(0, -1, 0);
//	local_normal = vector(0, 1, 0);
	return (local_normal);

}

/**
 * @brief	calculates the normal at a given point/intersection of a cone cap
 * caculates the normal of a point/intersection on a cylinder cap
 *
 * @param obj			object(cone cap) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cone_cap(t_object obj, t_tuple world_point)
{

	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_tuple		object_point;

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	normal[local] = calculate_local_normal(object_point, obj);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}
