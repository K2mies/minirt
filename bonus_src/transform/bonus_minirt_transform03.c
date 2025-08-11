/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform03.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:57:38 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:02 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates a shearing transformation matrix
 * shearing moves each coordinate in proportion to the other two coordinates
 * the proportions array should contain the following values
 *	proportions[XY], proportions[XZ]
 *	proportions[YX], proportions[YZ]
 *	proportions[ZX], proportions[ZY]
 *ie: XY is moving X in proportion to Y
 *
 * @param proportions	Array of 6 floats [XY, XZ, YX, YZ, ZX, ZY]
 * @return	t_matrix The shearing transformation matrix
 */
t_matrix4	shearing(t_float proportions[6])
{
	t_matrix4	res;

	res = id_matrix4();
	res.m[0][1] = proportions[XY];
	res.m[0][2] = proportions[XZ];
	res.m[1][0] = proportions[YX];
	res.m[1][2] = proportions[YZ];
	res.m[2][0] = proportions[ZX];
	res.m[2][1] = proportions[ZY];
	return (res);
}
