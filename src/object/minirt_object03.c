/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:50:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:47 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates and returns a cylinder object
 * creates a cylinder object/struct 
 * @param	location
 * @param	diameter
 * @param	col
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	cylinder(t_tuple location, t_float diameter, t_float height, t_color col)
{
	t_object	cy;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	cy.type = CYLINDER;
	cy.diameter = diameter;
	cy.radius = cy.diameter / 2;
	cy.origin = location;
	cy.height = height;
	cy.max = height;
	cy.min = 0;
	cy.color = col;
	cy.material = material(param, col);
	cy.material.has_pattern = false;
	cy.transform = id_matrix4();
	return (cy);
}
