/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:21:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/04 13:45:29 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and return a point_light object
 * creates and returns a point_light.
 *
 * @param origin		Point that is the origin of the light
 * @param brightness	Brightness of light (intensity)
 * @param col			Color of the light
 * @return				t_light object
 */
t_light	point_light(t_tuple origin, t_float brightness, t_color col)
{
	t_light	light;

	light.origin = origin;
	light.brightness = brightness;
	light.color = multiply_color_by_scalar(col, light.brightness);
	return (light);
		
}
