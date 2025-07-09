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
	if (obj.type == CUBE)
		res = normal_at_cube(obj, world_point);
	if (obj.type == CYLINDER)
		res = normal_at_cylinder(obj, world_point);
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
	t_tuple		local_normal;
	t_tuple		world_normal;
	t_matrix4	inverse_matrix;
	t_matrix4	transpose_matrix;

	local_normal = obj.vector;
	inverse_matrix = inverse_matrix4(obj.transform);
	transpose_matrix = transpose_matrix4(inverse_matrix);
	world_normal = multiply_matrix4_tuple(transpose_matrix, local_normal);
//	world_normal = multiply_matrix4_tuple(transpose_matrix4(inverse_matrix4(obj.transform)), local_normal);
	world_normal.w = 0;
	world_normal = normalize_vector(world_normal);
	return (world_normal);
}

/**
 * @brief	calculates the normal at a given point/intersection of a cube
 * caculates the normal of a point/intersection on a cube
 *
 * @param sphere		object(plane) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cube(t_object obj, t_tuple world_point)
{
	t_float	maxc;
	t_tuple	object_point;
	t_float	abs[3];

	object_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	abs[x] = fabsf(object_point.x);
	abs[y] = fabsf(object_point.y);
	abs[z] = fabsf(object_point.z);
	maxc = max_3(abs[x], abs[y], abs[z]);
	if (maxc == abs[x])
		return (vector(object_point.x, 0, 0));
	if (maxc == abs[y])
		return (vector(0, object_point.y, 0));
	if (maxc == abs[z])
		return (vector(0, 0, object_point.z));
	return (vector(0, 0, 0));
}

/**
 * @brief	calculates the normal at a given point/intersection of a cylinder
 * caculates the normal of a point/intersection on a cylinder
 *
 * @param sphere		object(cylinder) to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at_cylinder(t_object obj, t_tuple world_point)
{
	t_tuple	object_point;

	object_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	return(vector(object_point.x, 0, object_point.z));
}
