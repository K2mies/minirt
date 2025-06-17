/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_floats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:59:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/24 18:37:24 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

//#define EPSILON	0.00001

/**
 * Function to compare if two floats
 * are equivalant
 *
 * @param a		first float for comparison
 * @param b		second float for comparison
 *
 * @return		true if floats are equiviland and false if not.
 */
bool	compare_floats(t_float a, t_float b)
{
	if (fabs (a - b) < EPSILON)
		return (true);
	return (false);
}
