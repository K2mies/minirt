/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object07.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:40:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:52 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates and asigned a material object
 * creates, asigns and returns a material object
 * param[ambient] = 0.1;
 * param[diffuse] = 0.9;
 * param[specular] = 0.9;
 * param[shininess] = 200.0;
 * param[reflective] = 0;
 * @param param			array of 4 float paramaters as listed above
 * @param col			Color of material
 * @return				t_material object
 */
t_material material(t_float param[7], t_color col)
{
	t_material m;

	m.color = col;
	m.ambient = param[ambient];
	m.diffuse = param[diffuse];
	m.specular = param[specular];
	m.shininess = param[shininess];
	m.reflective = param[reflective];
	m.transparency = param[transparency];
	m.refractive_index = param[refractive_index];
	return (m);
}
