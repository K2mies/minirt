/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:09:22 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:48 by mpierce          ###   ########.fr       */
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
t_object	cone(t_tuple location, t_float diameter, t_float height,
			  t_color col)
{
	t_object	con;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	con.type = CONE;
	con.diameter = diameter;
	con.radius = con.diameter / 2;
	con.origin = location;
	con.height = height;
	con.max = height;
	con.min = 0;
	con.color = col;
	con.material = material(param, col);
	con.material.has_pattern = false;
	con.transform = id_matrix4();
	return (con);
}
