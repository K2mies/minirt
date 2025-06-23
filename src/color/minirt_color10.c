/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color10.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 12:07:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/23 12:31:55 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_color	reflected_color(t_world world, t_computations comps, int *remaining)
{
	t_ray	reflect_ray;
	t_color	col;

	if (comps.object.material.reflective == 0 || remaining <= 0)
		return (color(0, 0, 0));
	reflect_ray = ray(comps.over_point, comps.v[reflectv]);
	--(*remaining);
	col = color_at(world, reflect_ray, remaining);
	return (multiply_color_by_scalar(col, comps.object.material.reflective));

}
