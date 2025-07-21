/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object05.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:38:29 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:50 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates and returns a wall object
 * creates a wall object to use to calculate projections
 *
 * @param origin	Point that is the origin of the wall
 * @param width		Width of the wall
 * @param height	Height of the wall
 * @return			t_wall object
 */
t_wall	wall(t_tuple origin, t_float width, t_float height)
{
	t_wall	w;

	w.origin = origin;
	w.width = width;
	w.height = height;
	return (w);
}
