/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:44:35 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:11 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to multply a tuple by a scalar
 *
 * @param tup		tuple to be multiplied
 * @param scalar	scaler to multiply tuple by
 *
 * @return		Tuple multiplied by scalar
 */
t_tuple	multiply_tuple_by_scalar(t_tuple tup, t_float scalar)
{
	t_tuple	res;

	res.x = tup.x * scalar;
	res.y = tup.y * scalar;
	res.z = tup.z * scalar;
	res.w = tup.w * scalar;
	return (res);
}

/**
 * Function to devide a tuple by a scalar
 *
 * @param tup		tuple to be devided
 * @param scalar	scaler to devide tuple by
 *
 * @return		Tuple multiplied by scalar
 */
t_tuple	devide_tuple_by_scalar(t_tuple tup, t_float scalar)
{
	t_tuple	res;

	res.x = tup.x / scalar;
	res.y = tup.y / scalar;
	res.z = tup.z / scalar;
	res.w = tup.w / scalar;
	return (res);
}
