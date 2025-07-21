/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:42:25 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:27 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	get min and max values from each axis
 *
 * @param origin	origin.axis
 * @param direction	direction.axis
 * @param min		pointer to axis_t[min]
 * @param min		pointer to axis_t[max]
 */
void	check_axis(t_float origin, t_float direction, t_float *min, t_float *max)
{
	t_float	tmin_numerator;
	t_float	tmax_numerator;
	t_float	temp;

	tmin_numerator = (-1 - origin);
	tmax_numerator = (1 - origin);
	if (fabsf(direction) >= EPSILON)
	{
		*min = tmin_numerator / direction;
		*max = tmax_numerator / direction;
	}
	else
	{
		*min = tmin_numerator * BIG_NUMBER;
		*max = tmax_numerator * BIG_NUMBER;
	}
	if (*min > *max)
	{
		temp = *min;
		*min = *max;
		*max = temp;
	}
}

/**
 * @brief return max value from three floats
 *
 * @param a		first float for comparison
 * @param b		second float for comparison
 * @param c		third float for comparison
 * @return		largest float of the three
 */
t_float	max_3(t_float a, t_float b, t_float c)
{
	t_float	max;

	if (a > b)
		max = a;
	else
		max = b;
	if (max > c)
		return(max);
	else
		max = c;
	return (max);
}

/**
 * @brief return min value from three floats
 *
 * @param a		first float for comparison
 * @param b		second float for comparison
 * @param c		third float for comparison
 * @return		smallest float of the three
 */
t_float	min_3(t_float a, t_float b, t_float c)
{
	t_float	min;
	if (a < b)
		min = a;
	else
		min = b;
	if (min < c)
		return (min);
	else
		min = c;
	return (min);
}

