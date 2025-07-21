/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:42:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:45 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates and returns a cube object
 * creates a Cube object/struct 
 * @param	location
 * @param	col
 * @return	t_object struct with type CUBE
 */
t_object	cube(t_tuple origin, t_color col)
{
	t_object	cube;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	cube.type = CUBE;
	cube.origin = origin;
	cube.color = col;
	cube.material = material(param, col);
	cube.material.has_pattern = false;
	cube.transform = id_matrix4();
	return (cube);
}
