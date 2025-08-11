/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:46:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:14 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to compare wether two tuples are 
 * equivilant
 *
 * @param tupa	first tuple for comparison
 * @param tupa	fsecond tuple for comparison
 *
 * @return		true or false depending on wether they are equivilant or not
 */
bool	compare_tuples(t_tuple tupa, t_tuple tupb)
{
	if (compare_floats(tupa.x, tupb.x) == false)
		return (false);
	if (compare_floats(tupa.y, tupb.y) == false)
		return (false);
	if (compare_floats(tupa.z, tupb.z) == false)
		return (false);
	if (compare_floats(tupa.w, tupb.w) == false)
		return (false);
	return (true);
}

/**
 * Function to check if tuple is a vectgor
 *
 * @param tup	tuple to check 
 *
 * @return		true or false depending on wether it is a vector or not
 */
bool	is_tuple_vector(t_tuple tup)
{
	if (tup.w == 0)
		return (true);
	return (false);
}

/**
 * Function to check if tuple is a point
 *
 * @param tup	tuple to check 
 *
 * @return		true or false depending on wether it is a point or not
 */
bool	is_tuple_point(t_tuple tup)
{
	if (tup.w == 1)
		return (true);
	return (false);
}
