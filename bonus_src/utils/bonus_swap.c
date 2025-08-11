/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:13:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:37 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	function to swap two floats
 * Function to swap to floats based on their pointers
 *
 * @param a		pointer to float a
 * @param b		pointer to float b
 */
void	swapf(t_float *a, t_float *b)
{
	t_float	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
