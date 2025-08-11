/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform02.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 11:10:12 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:44:14 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to convert degree into radians
 *
 * @param degrees	degree to convert
 *
 * @return		value converted into radians
 */
double	rad_to_deg(t_float radians)
{
	return (radians * (180.0 / M_PI));
}

/**
 * Function to convert degree into radians
 *
 * @param degrees	degree to convert
 *
 * @return		value converted into radians
 */
double	deg_to_rad(t_float degrees)
{
	return (degrees * (M_PI / 180.0));
}

/**
 * Function to create a rotation Matrix around
 * the x axis
 *
 * @param degrees	degree to converted into radians
 *
 * @return		transformation matrix for x axis rotation
 */
t_matrix4	rotation_x(t_float deg)
{
	t_matrix4	res;
	double		r;

	r = deg_to_rad(deg);
	res = id_matrix4();
	res.m[1][1] = cos(r);
	res.m[1][2] = -sin(r);
	res.m[2][1] = sin(r);
	res.m[2][2] = cos(r);
	return (res);
}

/**
 * Function to create a rotation Matrix around
 * the y axis
 *
 * @param degrees	degree to converted into radians
 *
 * @return		transformation matrix for y axis rotation
 */
t_matrix4	rotation_y(t_float deg)
{
	t_matrix4	res;
	double		r;

	r = deg_to_rad(deg);
	res = id_matrix4();
	res.m[0][0] = cos(r);
	res.m[0][2] = sin(r);
	res.m[2][0] = -sin(r);
	res.m[2][2] = cos(r);
	return (res);
}

/**
 * Function to create a rotation Matrix around
 * the z axis
 *
 * @param degrees	degree to converted into radians
 *
 * @return		transformation matrix for z axis rotation
 */
t_matrix4	rotation_z(t_float deg)
{
	t_matrix4	res;
	double		r;

	r = deg_to_rad(deg);
	res = id_matrix4();
	res.m[0][0] = cos(r);
	res.m[0][1] = -sin(r);
	res.m[1][0] = sin(r);
	res.m[1][1] = cos(r);
	return (res);
}
