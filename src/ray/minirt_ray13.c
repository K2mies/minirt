/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray13.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:42:52 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/14 16:08:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	helper function to calculate the local normal for a cube
 * caculates the local normal based on the max value from
 * abs[x], abs[y], abs[z]
 * and return the object point of the max
 *
 * @param object_point	point in object/local space
 * @return				t_tuple normal[local]
 */
static	t_tuple	calculate_local_normal(t_tuple object_point)
{
	t_tuple	local_normal;
	t_float	abs[3];
	t_float	maxc;

	abs[x] = fabsf(object_point.x);
	abs[y] = fabsf(object_point.y);
	abs[z] = fabsf(object_point.z);
	maxc = max_3(abs[x], abs[y], abs[z]);
	if (maxc == abs[x])
		local_normal = vector(object_point.x, 0, 0);
	if (maxc == abs[y])
		local_normal = vector(0, object_point.y, 0);
	if (maxc == abs[z])
		local_normal = vector(0, 0, object_point.z);
	return (local_normal);
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
