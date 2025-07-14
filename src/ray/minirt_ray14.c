/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray14.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:44:23 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/14 15:45:11 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

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

