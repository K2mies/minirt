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
 * @param	cube 
 * @return	t_matrix4 transform matrx
 */
static t_matrix4	calculate_matrix_transform(t_object cube)
{
	t_matrix4	m;
	t_matrix4	trans;
	t_matrix4	view;

	m = id_matrix4();
	trans = translation(cube.origin.x, cube.origin.y, cube.origin.z);
	view = view_transform(cube.origin, cube.vector, vector(0, 1, 0));
	m = multiply_matrix4(trans, view);
	return (m);
}

/**
 * @brief	creates and returns a cube object
 * creates a Cube object/struct 
 * @param	vec[origin] & vec[direction]
 * @param	col
 * @return	t_object struct with type CUBE
 */
t_object	cube(t_tuple origin, t_tuple direction, t_color col, t_float height)
{
	t_object	cube;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	cube.type = CUBE;
	cube.origin = origin;
	cube.vector = direction;
	cube.color = col;
	cube.material = material(param, col);
	cube.material.has_pattern = false;
	cube.transform = calculate_matrix_transform(cube);
	cube.height = height;
	return (cube);
}
