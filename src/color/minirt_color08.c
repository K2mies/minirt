/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color08.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 12:45:02 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 14:12:27 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Returns a color based on x and z pos on gradient
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color	ring_at(t_pattern ring, t_tuple p)
{
	if ((int)floorf(sqrtf((p.x * p.x) + (p.z * p.z))) % 2 == 0)
		return (ring.a);
	else
		return (ring.b);
}

/**
 * Returns a color based on x and z pos on pattern and object
 *
 * @param pattern			the pattern to operate on
 * @param obj				the object to operate on
 * @param world_point		the world point to be converted to pattern point
 * @return					t_color type struct
 */
t_color	ring_at_object(t_pattern pattern, t_object obj, t_tuple world_point)
{
	t_tuple	object_point;
	t_tuple	pattern_point;

	object_point = multiply_matrix4_tuple(
			inverse_matrix4(obj.transform), world_point);
	pattern_point = multiply_matrix4_tuple(
			inverse_matrix4(pattern.transform), object_point);
	return (ring_at(pattern, pattern_point));
}
