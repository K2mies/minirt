/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:06:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/11 16:11:04 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	calculates the normal at a given point/intersection of a sphere
 * caculates the normal of a point/intersection on a sphere
 *
 * @param obj			object(sphere) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_sphere(t_object obj, t_tuple world_point)
{
	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_tuple		object_point;

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	normal[local] = sub_tuples(object_point, point(0, 0, 0));
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}

/**
 * @brief	calculates the normal at a given point/intersection of a plane
 * caculates the normal of a point/intersection on a plane
 *
 * @param obj			object(plane) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple normal_at_plane(t_object obj)
{
	t_matrix4	matrix[2];
	t_tuple		normal[2];

	normal[local] = obj.vector;
	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cube
 * caculates the normal of a point/intersection on a cube
 *
 * @param obj			object(plane) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cube(t_object obj, t_tuple world_point)
{
	
	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_float		abs[3];
	t_tuple		object_point;
	t_float		maxc;

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	abs[x] = fabsf(object_point.x);
	abs[y] = fabsf(object_point.y);
	abs[z] = fabsf(object_point.z);
	maxc = max_3(abs[x], abs[y], abs[z]);
	if (maxc == abs[x])
		normal[local] = vector(object_point.x, 0, 0);
	if (maxc == abs[y])
		normal[local] = vector(0, object_point.y, 0);
	if (maxc == abs[z])
		normal[local] = vector(0, 0, object_point.z);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cylinder
 * caculates the normal of a point/intersection on a cylinder
 *
 * @param obj			object(cylinder) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cylinder(t_object obj, t_tuple world_point)
{

	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_tuple		object_point;
	
	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	normal[local] = vector(object_point.x, 0, object_point.z);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cylinder cap
 * caculates the normal of a point/intersection on a cylinder cap
 *
 * @param obj			object(cylinder cap) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cap(t_object obj, t_tuple world_point)
{

	t_matrix4	matrix[2];
	t_tuple		normal[2];
	t_float		obj_point_sqr[3];
	t_tuple		object_point;
	t_float		distance;

	matrix[inverse] = inverse_matrix4(obj.transform);
	matrix[transpose] = transpose_matrix4(matrix[inverse]);
	object_point = multiply_matrix4_tuple(matrix[inverse], world_point);
	obj_point_sqr[x] = object_point.x * object_point.x;
	obj_point_sqr[z] = object_point.z * object_point.z;
	distance = obj_point_sqr[x] + obj_point_sqr[z];
	normal[local] = vector(object_point.x, 0, object_point.z);
	if (distance < 1 && object_point.y >= obj.max - EPSILON)
		normal[local] = vector(0, 1, 0);
	else if (distance < 1 && object_point.y <= obj.min + EPSILON)
		normal[local] = vector(0, -1, 0);
	normal[world] = multiply_matrix4_tuple(matrix[transpose], normal[local]);
	normal[world].w = 0;
	normal[world] = normalize_vector(normal[world]);
	return (normal[world]);
//	return (vector(normal[world].x, 0, normal[world].z));
//	return (vector(object_point.x, 0, object_point.z));
}
