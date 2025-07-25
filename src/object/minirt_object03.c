/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:50:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/24 12:38:43 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	(helper) calculates the transform matrix of the cylinder 
 * from vector and origin
 * @param	cy 
 * @return	t_matrix4 transform matrx
 */
static t_matrix4	calculate_transform_matrix(t_object cy)
{
	t_matrix4	res;
	t_matrix4	matrix[3][3];
	t_float		axis[3];
	t_float		magnitude;
	t_tuple		unit_vector;

	res = id_matrix4();
	matrix[translate][0] = translation(cy.origin.x, cy.origin.y, cy.origin.z);
	unit_vector = normalize_vector(cy.vector);
	magnitude = get_magnitude(vector(unit_vector.x, 0, unit_vector.z));
	axis[x] = atan2f(magnitude, unit_vector.y);
	axis[y] = atan2f(unit_vector.x, unit_vector.z);
	matrix[rotate][x] = rotation_x(rad_to_deg(axis[x]));
	matrix[rotate][y] = rotation_y(rad_to_deg(axis[y]));
	res = multiply_matrix4(res, matrix[translate][0]);
	res = multiply_matrix4(res, matrix[rotate][y]);
	res = multiply_matrix4(res, matrix[rotate][x]);
	return (res);
}

/**
 * @brief	creates and returns a cylinder object
 * creates a cylinder object/struct 
 * @param	param.origin
 * @param	param.direction
 * @param	param.diameter
 * @param	param.height
 * @param	param.col
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	cylinder(t_p_cy	param)
{
	t_object	cy;
	t_float		material_param[7];

	material_param[ambient] = 0.1;
	material_param[diffuse] = 0.9;
	material_param[specular] = 0.9;
	material_param[shininess] = 200.0;
	material_param[reflective] = 0;
	material_param[transparency] = 0;
	material_param[refractive_index] = 1.0;
	cy.type = CYLINDER;
	cy.closed = true;
	cy.diameter = param.diameter;
	cy.radius = cy.diameter / 2;
	cy.origin = param.origin;
	cy.vector = param.direction;
	cy.height = param.height;
	cy.max = cy.height;
	cy.min = 0;
	cy.color = param.col;
	cy.material = material(material_param, cy.color);
	cy.material.has_pattern = false;
	cy.transform = calculate_transform_matrix(cy);
	return (cy);
}
