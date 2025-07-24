/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:56:11 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:42 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix4	calculate_matrix_transform(t_object plane)
{
	t_matrix4	m;
	t_matrix4	move;

	m = id_matrix4();
	move = translation(plane.origin.x, plane.origin.y, plane.origin.z);
	m = multiply_matrix4(m, move);
	return (m);
}

/**
 * @brief	creates and returns a plane object
 * creates a Cube object/struct 
 * @param	vec[origin] & vec[direction]
 * @param	col
 * @return	t_object struct with type PLANE
 */
t_object	plane(t_tuple vec[2], t_color col)
{
	t_object	p;
	t_float		param[7];

	param[ambient] = 0.1;
	param[diffuse] = 0.9;
	param[specular] = 0.9;
	param[shininess] = 200.0;
	param[reflective] = 0;
	param[transparency] = 0;
	param[refractive_index] = 1.0;
	p.type = PLANE;
	p.origin = vec[origin];
	p.vector = vec[direction];
	p.color = col;
	p.material = material(param, col);
	p.material.has_pattern = false;
	p.transform = calculate_matrix_transform(p);
	return (p);
}
