/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:39:44 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/02 17:04:33 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	transforms ray with transformation matrix
 * transforms a ray based on transformation matrix
 * as input
 *
 * @param r		ray that is to be transformed
 * @param m		transformation matrix used to transform ray
 * @return		returns newley transformed ray
 */
t_ray transform(t_ray r, t_matrix4 m)
{
	t_ray	res;

	res.origin = multiply_matrix4_tuple(m, r.origin);
	res.direction = multiply_matrix4_tuple(m, r.direction);
	return (res);
}

/**
 * @brief	sets the transformation property of object
 * sets the transformation matrix of the pointed to object
 * based on the transformation matrix passed as an argument
 *
 * @param s		pointer to the object from which the property will be altered
 * @param m		transformation matrix used to update transform property
 */
void	set_transform(t_object *s, t_matrix4 m)
{
	s->transform = m;
}
