/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:49:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 14:06:17 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	(helper) calculates the transform matrix of the sphere
 * from origin
 * @param	sp (sphere)
 * @return	t_matrix4 transform matrx
 */
static void	calculate_transform_matrix(t_object *sp)
{
	t_float	pos[3];

	pos[x] = sp->origin.x;
	pos[y] = sp->origin.y;
	pos[z] = sp->origin.z;
	sp->transforms[translate][xyz] = translation(pos[x], pos[y], pos[z]);
	sp->transforms[rotate][x] = id_matrix4();
	sp->transforms[rotate][y] = id_matrix4();
	sp->transforms[rotate][z] = id_matrix4();
	sp->transforms[scale][xyz] = id_matrix4();
	apply_transforms(sp);
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
	calculate_transform_matrix(&sphere);
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
