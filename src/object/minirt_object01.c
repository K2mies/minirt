/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 12:56:11 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/17 11:37:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_object	plane(t_tuple origin, t_tuple normal, t_color col)
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
	p.origin = origin;
	p.vector = normal;
	p.color = col;
	p.material = material(param, col);
	p.material.has_pattern = false;
	p.transform = id_matrix4();
	return (p);
}
