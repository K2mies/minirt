/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:42:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/24 12:34:26 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


/**
 * @brief	(helper) calculates the transform matrix of the cube
 * from vector and origin
 * @param	cb
 * @return	t_matrix4 transform matrx
 */
static t_matrix4	calculate_matrix_transform(t_object cb)
{
	t_matrix4	res;
	t_matrix4	matrix[3][3];
	t_float		axis[3];
	t_float		magnitude;
	t_tuple		unit_vector;

	res = id_matrix4();
	matrix[translate][0] = translation(cb.origin.x, cb.origin.y, cb.origin.z);
	unit_vector = normalize_vector(cb.vector);
	magnitude = get_magnitude(vector(unit_vector.x, 0, unit_vector.z));
	axis[x] = atan2f(magnitude, unit_vector.y);
	axis[y] = atan2f(unit_vector.x, unit_vector.z);
	matrix[rotate][x] = rotation_x(rad_to_deg(axis[x]));
	matrix[rotate][y] = rotation_y(rad_to_deg(axis[y]));
	matrix[scale][0] = scaling(cb.height, cb.height, cb.height);
	res = multiply_matrix4(res, matrix[translate][0]);
	res = multiply_matrix4(res, matrix[rotate][y]);
	res = multiply_matrix4(res, matrix[rotate][x]);
	res = multiply_matrix4(res, matrix[scale][0]);
	return (res);
}
/**
 * @brief	creates and returns a cube object
 * creates a Cube object/struct 
 * @param	vec[origin] & vec[direction]
 * @param	col
 * @return	t_object struct with type CUBE
 */
t_object	cube(t_tuple origin, t_tuple direction, t_color col, t_float scale)
{
	t_object	cube;
	t_float		material_param[7];

	material_param[ambient] = 0.1;
	material_param[diffuse] = 0.9;
	material_param[specular] = 0.9;
	material_param[shininess] = 200.0;
	material_param[reflective] = 0;
	material_param[transparency] = 0;
	material_param[refractive_index] = 1.0;
	cube.type = CUBE;
	cube.origin = origin;
	cube.vector = direction;
	cube.color = col;
	cube.material = material(material_param, col);
	cube.material.has_pattern = false;
//	cube.material.pattern = pattern(color(0,0,0), color(1,1,1), CHECKER);
//	cube.material.pattern.transform = scaling(0.5,0.5,0.5);
	cube.height = scale;
	cube.transform = calculate_matrix_transform(cube);
	return (cube);
}
