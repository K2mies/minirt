/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:40:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/04 14:46:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and asigned a material object
 * creates, asigns and returns a material object
 * param[ambient]
 * param[diffuse]
 * param[specular]
 * param[shininess]
 * @param param			array of 4 float paramaters as listed above
 * @param col			Color of material
 * @return				t_material object
 */
t_material material(t_float param[4], t_color col)
{
	t_material m;

	m.color = col;
	m.ambient = param[ambient];
	m.diffuse = param[diffuse];
	m.specular = param[specular];
	m.shininess = param[shininess];
	return (m);
}
