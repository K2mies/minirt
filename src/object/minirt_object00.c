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
	t_object	sp;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	sp.type = SPHERE;
	sp.diameter = diameter;
	sp.radius = sp.diameter / 2;
	sp.origin = location;
	sp.color = col;
	sp.material = material(param, col);
	sp.material.has_pattern = false;
	sp.transform = calculate_transform_matrix(sp);
	return (sp);
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
	t_object	sp;

	sp = sphere(location, diameter, col);
	sp.material.transparency = 1.0;
	sp.material.refractive_index = 1.5;
	return (sp);
}
