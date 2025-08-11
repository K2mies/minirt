/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:15:41 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:52:19 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	creates a intersection
 * creates and returns an intersection object
 *
 * @param t		intersection value
 * @param obj	object being intersected
 * @return		t_intersection	result of intersection
 */
t_intersection	intersection(t_float t, t_object obj)
{
	t_intersection	res;

	res.t = t;
	res.object = obj;
	return (res);
}

/**
 * @brief	returns intersection of local object
 * creates and returns an intersection  of object
 *
 * @param obj	object being intersected
 * @param ray	ray to intersect
 * @return		t_intersection	result of intersection
 */
t_intersections	object_intersection(t_object *obj, t_ray ray)
{
	t_intersections	xs;

	if (obj->type == SPHERE)
		xs = sphere_intersection(obj, ray);
	if (obj->type == PLANE)
		xs = plane_intersection(obj, ray);
	if (obj->type == CUBE)
		xs = cube_intersection(obj, ray);
	if (obj->type == CYLINDER)
		xs = cylinder_intersection(obj, ray);
	if (obj->type == CONE)
		xs = cone_intersection(obj, ray);
	return (xs);
}

/**
 * @brief	run intersection on all world objects
 * creates a list of intersections for all objects
 * int the world from one ray
 *
 * @param rt	pointer to main data struct
 * @param ray		Ray to cast
 */
void	world_intersect(t_world *w, t_ray ray)
{
	int				i;
	t_intersections	xs;

	i = 0;
	w->n_ts = 0;
	while (i < w->n_objs)
	{
		xs = object_intersection(&w->objs[i], ray);
		add_intersections(w, xs, i);
		++i;
	}
	quicksort(w->ts, 0, w->n_ts -1);
}
