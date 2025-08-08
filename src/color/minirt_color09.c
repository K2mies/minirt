/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color09.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:38:57 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:09:39 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Returns a color based on x, y and z pos on pattern
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color	checker_at(t_pattern check, t_tuple p)
{
	int	sum;

	sum = (int)(floorf(p.x + PATTERN_SHIFT)) +
				(floorf(p.y + PATTERN_SHIFT)) +
				(floorf(p.z + PATTERN_SHIFT));
	if (sum % 2 == 0)
		return (check.a);
	return (check.b);
}

/**
 * Returns a color based on x, y and z pos on pattern
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color	checker_at_object(t_pattern src_pattern, t_object obj, t_tuple world_point)
{
	t_tuple		point[2];
	t_matrix4	mat[2];

	mat[inverse] = inverse_matrix4(obj.transform);
	point[object] = multiply_matrix4_tuple(mat[inverse], world_point);
	mat[inverse] = inverse_matrix4(src_pattern.transform);
	point[pat] = multiply_matrix4_tuple(mat[inverse], point[object]);
	return (checker_at(src_pattern, point[pat]));
}
