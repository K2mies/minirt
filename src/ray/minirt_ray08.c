/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:41:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:44:16 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function truncate the cylinder
 *
 * @param cylinder	pointer to cylinder object
 * @param ray		ray to use for calculations
 * @param res		pointer to result values to update
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

/**
 * @brief	helper function truncate the cone
 *
 * @param cone		pointer to cone object
 * @param ray		ray to use for calculations
 * @param res		pointer to result values to update
 */
__attribute__((used)) void	truncate_cone(t_object *cone, t_ray ray, t_intersections *res)
{
	t_float	y[2];
	printf("INSIDE START TRUNC CONE\n");
	printf("origin.y: %f | res->t[0]: %f | ray.dir.y: %f\n", ray.origin.y, res->t[0], ray.direction.y);
	y[0] = ray.origin.y + (res->t[0] * ray.direction.y);
	printf("min: %f | y[0]: %f | max: %f\n", cone->min, y[0], cone->max);
	if (cone->min < y[0] && y[0] < cone->max)
	{
//		res->t[res->count] = res->t[0];
		res->count += 1;
	}
	printf("origin.y: %f | res->t[1]: %f | ray.dir.y: %f\n", ray.origin.y, res->t[1], ray.direction.y);
	y[1] = ray.origin.y + res->t[1] * ray.direction.y;
	printf("min: %f | y[1]: %f | max: %f\n", cone->min, y[1], cone->max);
	if (cone->min < y[1] && y[1] < cone->max)
	{
//		res->t[res->count] = res->t[1];
		res->count += 1;
	}
	printf("INSIDE END TRUNC CONE\n");
}
