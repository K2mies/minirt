/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:52:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/11 16:11:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	calculates the normal at a given point/intersection of a sub object
 * caculates the normal of a point/intersection on a sub object depending on
 * type
 *
 * @param obj			object to calculate normal on
 * @param world_point	intersection point in world space.
 * @return				normal vector from calculation
 */
t_tuple	normal_at(t_object obj, t_tuple world_point)
{
	t_tuple res;
	if (obj.type == SPHERE)
		res = normal_at_sphere(obj, world_point);
	if (obj.type == PLANE)
		res = normal_at_plane(obj);
	if (obj.type == CUBE)
		res = normal_at_cube(obj, world_point);
	if (obj.type == CYLINDER && obj.closed == true)
		res = normal_at_cylinder_cap(obj, world_point);
	else if (obj.type == CYLINDER)
		res = normal_at_cylinder(obj, world_point);
	if (obj.type == CONE && obj.closed == true)
		res = normal_at_cone_cap(obj, world_point);
	else if(obj.type == CONE)
		res = normal_at_cone(obj, world_point);
	return (res);
}
