/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:49:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/02 17:13:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates and returns a sphere object
 * creates a Sphere object/struct 
 * and returns the two as a struct of t_ray type with a positions
 * of 0, 0, 0 and a randomised radius between 1 and 20
 *
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	sphere(t_tuple location, t_float diameter, t_color col)
{
	t_object	sp;
	t_float		param[5];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	sp.type = SPHERE;
	sp.diameter = diameter;
	sp.radius = sp.diameter / 2;
	sp.origin = location;
	sp.color = col;
	sp.material = material(param, col);
	sp.material.has_pattern = false;
	sp.transform = id_matrix4();
	return (sp);
}
