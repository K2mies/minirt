/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray19.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 11:31:38 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:54:09 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	calculates the reflected vector
 * calculates the reflected vector from the in vector and normal
 *
 * @param in			incomming vector
 * @param normal		normal vector to bounce off
 * @return				reflected vector
 */
t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	res;
	t_tuple	scaled_norm;

	scaled_norm = multiply_tuple_by_scalar(normal, 2 * dot_product(in, normal));
	res = sub_tuples(in, scaled_norm);
	return (res);
}
