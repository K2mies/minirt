/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color07.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:37:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/18 16:50:45 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"


/**
 * Returns a color based on x pos on gradient
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color gradient_at(t_pattern gradient, t_tuple point)
{
	t_color	res;
	t_color	distance;
	t_float	fraction;

	distance = sub_colors(gradient.b, gradient.a);
	fraction = point.x - floorf(point.x);
	res = add_colors(gradient.a, distance);
	res = multiply_color_by_scalar(res, fraction);
	return (res);
}

/**
 * Returns a color based on x pos on pattern and object
 *
 * @param pattern			the pattern to operate on
 * @param obj				the object to operate on
 * @param world_point		the world point to be converted to pattern point
 * @return					t_color type struct
 */
t_color	gradient_at_object(t_pattern pattern, t_object obj, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	pattern_point = multiply_matrix4_tuple(
		inverse_matrix4(pattern.transform), object_point);
	return (gradient_at(pattern, pattern_point));
}
