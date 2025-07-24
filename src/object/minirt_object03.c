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
	t_matrix4	m;
//	t_matrix4	view;
	t_matrix4	trans;
	t_matrix4	rot[3];
	t_float		axis[3];
	t_tuple		unit_vec;
	t_float		mag;

	m = id_matrix4();
	trans = translation(cy.origin.x, cy.origin.y, cy.origin.z);

	unit_vec = normalize_vector(cy.vector);
	mag = get_magnitude(point(unit_vec.x, 0, unit_vec.z));
	axis[x] = atan2(mag, unit_vec.y);
	axis[y] = atan2(unit_vec.x, unit_vec.z);
//	axis[x] = atan2f(cy.vector.z, cy.vector.y);
//	axis[y] = atan2f(cy.vector.x, cy.vector.z);
//	mag = get_magnitude(cy.vector);
//	axis[x] = acosf(dot_product(vector(1,0,0) ));
	rot[x] = rotation_x(rad_to_deg(axis[x]));
	rot[y] = rotation_y(rad_to_deg(axis[y]));
//	rot[z] = rotation_z(90);
//	m = multiply_matrix4(m, trans);
	m = multiply_matrix4(m, rot[x]);
	m = multiply_matrix4(m, rot[y]);
//	m = multiply_matrix4(m, trans);
//	m = multiply_matrix4(m, rot[z]);
//	m = multiply_matrix4(m, trans);
////	view = view_transform(cy.origin, cy.vector, vector(0, 1, 0));
////	m = multiply_matrix4(trans, view);
	return (m);
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
