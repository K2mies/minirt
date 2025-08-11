/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:50:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 14:05:53 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	(helper) calculates the transform matrix of the cylinder 
 * from vector and origin
 * @param	cy 
 * @return	t_matrix4 transform matrx
 */
static void	calculate_transform_matrix(t_object *cy)
{
	t_float		pos[3];
	t_float		axis[3];
	t_float		magnitude;
	t_tuple		unit_vector;

	pos[x] = cy->origin.x;
	pos[y] = cy->origin.y;
	pos[z] = cy->origin.z;
	cy->transforms[translate][xyz] = translation(pos[x], pos[y], pos[z]);
	unit_vector = normalize_vector(cy->vector);
	magnitude = get_magnitude(vector(unit_vector.x, 0, unit_vector.z));
	axis[x] = atan2f(magnitude, unit_vector.y);
	axis[y] = atan2f(unit_vector.x, unit_vector.z);
	cy->transforms[rotate][x] = rotation_x(rad_to_deg(axis[x]));
	cy->transforms[rotate][y] = rotation_y(rad_to_deg(axis[y]));
	cy->transforms[rotate][z] = id_matrix4();
	cy->transforms[scale][xyz] = id_matrix4();
	apply_transforms(cy);
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
	t_object	cylinder;
	t_float		material_param[7];

	material_param[ambient] = 0.1;
	material_param[diffuse] = 0.7;
	material_param[specular] = 0.3;
	material_param[shininess] = 200.0;
	material_param[reflective] = 0;
	material_param[transparency] = 0;
	material_param[refractive_index] = 1.0;
	cylinder.type = CYLINDER;
	cylinder.closed = true;
	cylinder.diameter = param.diameter;
	cylinder.radius = cylinder.diameter / 2;
	cylinder.origin = param.origin;
	cylinder.vector = param.direction;
	cylinder.height = param.height;
	cylinder.max = cylinder.height / 2;
	cylinder.min = -cylinder.max;
	cylinder.color = param.col;
	cylinder.material = material(material_param, cylinder.color);
	cylinder.material.has_pattern = false;
	calculate_transform_matrix(&cylinder);
	return (cylinder);
}
