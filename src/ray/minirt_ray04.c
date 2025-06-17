/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:52:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/17 11:57:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	calculates the normal at a given point/intersection of a sub object
 * caculates the normal of a point/intersection on a sub object depending on
 * type
 *
 * @param obj			object to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at(t_object obj, t_tuple world_point)
{
	t_tuple res;
	if (obj.type == SPHERE)
		res = normal_at_sphere(obj, world_point);
	if (obj.type == PLANE)
		res = normal_at_plane(obj);
	return (res);
}

/**
 * @brief	calculates the normal at a given point/intersection of a sphere
 * caculates the normal of a point/intersection on a sphere
 *
 * @param sphere		object(sphere) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_sphere(t_object obj, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	object_normal;
	t_tuple	world_normal;
	t_tuple res;

	object_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	object_normal = sub_tuples(object_point, point(0, 0, 0));
	world_normal = multiply_matrix4_tuple(
		transpose_matrix4(inverse_matrix4(obj.transform)), object_normal);
	world_normal.w = 0;
	res = normalize_vector(world_normal);
	return (res);
}

/**
 * @brief	calculates the normal at a given point/intersection of a plane
 * caculates the normal of a point/intersection on a plane
 *
 * @param sphere		object(plane) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple normal_at_plane(t_object obj)
{
//	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	//local_point = multiply_matrix4_tuple(inverse_matrix4(obj.transform), world_point);
	local_normal = obj.vector;
	world_normal = multiply_matrix4_tuple(transpose_matrix4(inverse_matrix4(obj.transform)), local_normal);
	world_normal.w = 0;
	world_normal = normalize_vector(world_normal);
	return (world_normal);
}
