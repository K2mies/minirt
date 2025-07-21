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
//__attribute__((used)) void	truncate_cone(t_object *cone, t_ray ray, t_intersections *res)
void	truncate_cone(t_object *cone, t_ray ray, t_intersections *res)
{
	t_float	y[2];
	y[0] = ray.origin.y + (res->t[0] * ray.direction.y);
//	if (cone->min < y[0] && y[0] < cone->max)
	if (y[0] > cone->min && y[0] < cone->max)
//	if (y[0] > 0.0f && y[0] < cone->max)
	{
//		res->t[res->count] = res->t[0];
		res->count += 1;
	}
	y[1] = ray.origin.y + res->t[1] * ray.direction.y;
//	if (cone->min < y[1] && y[1] < cone->max)
	if (y[1] > cone->min && y[1] < cone->max)
//	if (y[1] > 0.0f && y[1] < cone->max)
	{
//		res->t[res->count] = res->t[1];
		res->count += 1;
	}
}
