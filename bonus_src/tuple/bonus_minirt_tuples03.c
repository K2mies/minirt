/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples03.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 12:37:55 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:12 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to get the magnitude of a vector
 *
 * @param vec		Vector to get the magnitude of
 *
 * @return		magnitude of the given vector;
 */
t_float	get_magnitude(t_tuple vec)
{
	t_float	mag;

	mag = sqrt((vec.x * vec.x) + (vec.y * vec.y)
			+ (vec.z * vec.z) + (vec.w * vec.w));
	return (mag);
}

/**
 * Function to Normalize the tuple to a unit vector
 *
 * @param tup	Tuple to be normalized
 *
 * @return		returns normalised version of the tuple. 
 */
t_tuple	normalize_vector(t_tuple vec)
{
	t_float	mag;
	t_tuple	res;

	mag = get_magnitude(vec);
	res.x = vec.x / mag;
	res.y = vec.y / mag;
	res.z = vec.z / mag;
	res.w = vec.w / mag;
	return (res);
}
