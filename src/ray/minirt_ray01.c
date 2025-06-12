/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:15:41 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/02 17:12:29 by mpierce          ###   ########.fr       */
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
t_intersection intersection(t_float t, t_object obj)
{
	t_intersection	res;
	res.t = t;
	res.object = obj;
	return (res);
}

/**
 * @brief	intersections  of a ray and a sphere
 * creates a decriminant value from ray hitting a sphere
 * and returns as two values if there is a hit, 0 if 
 * it is a miss.
 *
 * @param sphere	sphere object to be intersected
 * @param ray		Ray to cast
 * @return	t_intersections	result of intersections
 */
t_intersections	sphere_intersection(t_object sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	t_float dp[3];
	t_float	discriminant;
	t_intersections	res;
	t_ray	ray2;

	ray2 = transform(ray, inverse_matrix4(sphere.transform));
	sphere_to_ray = sub_tuples(ray2.origin, sphere.origin);	
	dp[a] = dot_product(ray2.direction, ray2.direction);
	dp[b] = 2.0 * dot_product(ray2.direction, sphere_to_ray);
	dp[c] = dot_product(sphere_to_ray, sphere_to_ray)
			- (sphere.radius * sphere.radius);
	discriminant = (dp[b] * dp[b]) - (4.0 * dp[a] * dp[c]);
	if (discriminant < 0)
	{
		res.count = 0;
		return (res);
	}
	res.t[0] = (-dp[b] - sqrtf(discriminant)) / (2.0 * dp[a]);
	res.t[1] = (-dp[b] + sqrtf(discriminant)) / (2.0 * dp[a]);
	res.count = 2;
	return (res);
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
	int			i;
	t_intersections	xs;

	i = 0;
	w->n_ts = 0;
	while (i < w->n_objs)
	{
		if (w->objs[i].type == SPHERE)
			xs = sphere_intersection(w->objs[i], ray);
		if (xs.count != 0)
		{
			w->ts[w->n_ts].t = xs.t[0];
			w->ts[w->n_ts].object = w->objs[i];
			++w->n_ts;
			w->ts[w->n_ts].t = xs.t[1];
			w->ts[w->n_ts].object = w->objs[i];
			++w->n_ts;
		}
		++i;
	}
	quicksort(w->ts, 0, w->n_ts -1);
}
