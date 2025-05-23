/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/23 17:14:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to create an identity 4X4 matrix
 
 * @return		identity matrix struct
 */
t_matrix4	id_matrix4(void)
{
	t_matrix4	mat;

	mat = (t_matrix4)
	{{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	}};
	return (mat);
}
/**
 * Function to create an empty 4X4 matrix
 
 * @return		empty matrix struct
 */
t_matrix4	matrix4(void)
{
	t_matrix4	mat;

	mat = (t_matrix4)
	{{
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
	}};
	return (mat);
}

/**
 * Function to create an empty 3X3 matrix
 
 * @return		empty matrix struct
 */
t_matrix3	matrix3(void)
{
	t_matrix3	mat;

	mat = (t_matrix3)
	{{
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
	}};
	return (mat);
}

/**
 * Function to create an empty 2X2 matrix
 
 * @return		empty matrix struct
 */
t_matrix2	matrix2(void)
{
	t_matrix2	mat;

	mat = (t_matrix2)
	{{
	{0, 0},
	{0, 0}
	}};
	return (mat);
}
