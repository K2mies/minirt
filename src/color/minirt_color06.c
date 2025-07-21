/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color06.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:11:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:09:29 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Returns a color based on x pos on pattern
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color	stripe_at(t_pattern pat, t_tuple point)
{
	if((int)floorf(point.x) % 2 == 0)
		return (pat.a);
	else
		return (pat.b);
}

/**
 * Returns a color based on x pos on pattern and object
 *
 * @param pattern			the pattern to operate on
 * @param obj				the object to operate on
 * @param world_point		the world point to be converted to pattern point
 * @return					t_color type struct
 */
t_color	stripe_at_object(t_pattern pattern, t_object obj, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = multiply_matrix4_tuple(
		inverse_matrix4(obj.transform), world_point);
	pattern_point = multiply_matrix4_tuple(
		inverse_matrix4(pattern.transform), object_point);
	return (stripe_at(pattern, pattern_point));
}
