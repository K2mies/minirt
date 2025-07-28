/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:49:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:08:35 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	(helper) calculates the transform matrix of the sphere
 * from origin
 * @param	sp (sphere)
 * @return	t_matrix4 transform matrx
 */
static t_matrix4 calculate_transform_matrix(t_object sp)
{
	t_matrix4	m;
	t_matrix4	move;

	m = id_matrix4();
	move = translation(sp.origin.x, sp.origin.y, sp.origin.z);
	m = multiply_matrix4(m, move);
	return (m);

}

/**
 * @brief	creates and returns a sphere object
 * creates a Sphere object/struct 
 * @param	location
 * @param	diameter
 * @param	col
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	sphere(t_tuple location, t_float diameter, t_color col)
{
	t_object	sphere;
	t_float		material_param[7];

	material_param[ambient] = 0.1;
	material_param[diffuse] = 0.7;
	material_param[specular] = 0.3;
	material_param[shininess] = 200.0;
	material_param[reflective] = 0;
	material_param[transparency] = 0;
	material_param[refractive_index] = 1.0;
	sphere.type = SPHERE;
	sphere.diameter = diameter;
	sphere.radius = sphere.diameter / 2;
	sphere.origin = location;
	sphere.color = col;
	sphere.material = material(material_param, col);
	sphere.material.has_pattern = false;
	sphere.transform = calculate_transform_matrix(sphere);
	return (sphere);
}

/**
 * @brief	helper function to create a glass sphere
 * creates a Sphere object/struct  with glass sphere properties
 * @param	location
 * @param	diameter
 * @param	col
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	glass_sphere(t_tuple location, t_float diameter, t_color col)
{
	t_object	glass_sphere;

	glass_sphere = sphere(location, diameter, col);
	glass_sphere.material.transparency = 1.0;
	glass_sphere.material.refractive_index = 1.5;
	return (glass_sphere);
}
