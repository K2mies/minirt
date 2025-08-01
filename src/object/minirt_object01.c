/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:56:11 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/24 12:23:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	(helper) calculates the transform matrix of the plane
 * from vector and origin
 * @param	pl
 * @return	t_matrix4 transform matrx
 */
static void	calculate_matrix_transform(t_object *pl)
{
	t_float		pos[3];
	t_float		axis[3];
	t_float		magnitude;
	t_tuple		unit_vector;

	pos[x] = pl->origin.x;
	pos[y] = pl->origin.y;
	pos[z] = pl->origin.z;
	pl->transforms[translate][xyz] = translation(pos[x], pos[y], pos[z]);
	unit_vector = normalize_vector(pl->vector);
	magnitude = get_magnitude(vector(unit_vector.x, 0, unit_vector.z));
	axis[x] = atan2f(magnitude, unit_vector.y);
	axis[y] = atan2f(unit_vector.x, unit_vector.z);
	pl->transforms[rotate][x] = rotation_x(rad_to_deg(axis[x]));
	pl->transforms[rotate][y] = rotation_y(rad_to_deg(axis[y]));
	pl->transforms[scale][xyz] = id_matrix4();
	apply_transforms(pl);
}

/**
 * @brief	creates and returns a plane object
 * creates a Cube object/struct 
 * @param	vec[origin] & vec[direction]
 * @param	col
 * @return	t_object struct with type PLANE
 */
t_object	plane(t_tuple origin, t_tuple direction, t_color col)
{
	t_object	plane;
	t_float		material_param[7];

	material_param[ambient] = 0.1;
	material_param[diffuse] = 0.9;
	material_param[specular] = 0;
	material_param[shininess] = 200.0;
	material_param[reflective] = 0;
	material_param[transparency] = 0;
	material_param[refractive_index] = 1.0;
	plane.type = PLANE;
	plane.origin = origin;
	plane.vector = direction;
	plane.color = col;
	plane.material = material(material_param, col);
	calculate_matrix_transform(&plane);
	plane.material.has_pattern = false;
	return (plane);
}
