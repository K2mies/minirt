/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:52:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/16 16:47:14 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"


t_tuple	normal_at(t_object obj, t_tuple world_point)
{
	t_tuple res;
	if (obj.type == SPHERE)
		res = normal_at_sphere(obj, world_point);
	if (obj.type == PLANE)
		res = normal_at_plane(obj, world_point);
	return (res);
}

/**
 * @brief	calculates the normal at a given point/intersection
 * caculates the normal of a point/intersection on an object
 *
 * @param sp			object(currently sphere) to calculate normal on
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

t_tuple normal_at_plane(t_object obj, t_tuple world_point)
{
	t_tuple	local_point;
	t_tuple	local_normal;
	t_tuple	world_normal;

	local_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	local_normal = obj.vector;
	world_normal = multiply_matrix4_tuple(inverse_matrix4(obj.transform), local_normal);
	world_normal = transpose_matrix4(world_normal);
	world_normal.w = 0;
	world_normal = normalize_vector(world_normal);
	return (world_normal);
}

/**
 * @brief	calculates the reflected vector
 * calculates the reflected vector from the in vector and normal
 *
 * @param in			incomming vector
 * @param normal		normal vector to bounce off
 * @return				reflected vector
 */
t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple res;
	t_tuple scaled_norm;

	scaled_norm = multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal));
	res = sub_tuples(in, scaled_norm);
//	res = multiply_tuple_by_scalar(sub_tuples(in, normal), 2 * dot_product(in, normal));
	return (res);
}
