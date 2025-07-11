/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:41:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/10 14:31:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	helper function truncate the cylinder
 *
 * @param res		pointer to result values to update
 * @param cylinder	pointer to cylinder object
 * @param ray		ray to use for calculations
 */
void	truncate_cylinder(t_object *cylinder, t_ray ray, t_intersections *res)
{
	t_float	y[2];

	y[0] = ray.origin.y + (res->t[0] * ray.direction.y);
	if (cylinder->min < y[0] && y[0] < cylinder->max)
		res->count += 1;
	y[1] = ray.origin.y + res->t[1] * ray.direction.y;
	if (cylinder->min < y[1] && y[1] < cylinder->max)
		res->count += 1;
}
