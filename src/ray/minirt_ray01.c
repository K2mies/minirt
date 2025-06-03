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

	ray = transform(ray, inverse_matrix4(sphere.transform));
	sphere_to_ray = sub_tuples(ray.origin, sphere.origin);	
	dp[a] = dot_product(ray.direction, ray.direction);
	dp[b] = 2.0 * dot_product(ray.direction, sphere_to_ray);
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
void	world_intersect(t_minirt *rt, t_ray *ray)
{
	int			i;
	t_intersections	xs;

	i = 0;
	rt->n_ts = 0;
	while (i < rt->n_objs)
	{
		if (rt->objs[i].type == SPHERE)
			xs = sphere_intersection(rt->objs[i], *ray);
		if (xs.count != 0)
		{
			rt->ts[rt->n_ts].t = xs.t[0];
			rt->ts[rt->n_ts].object = rt->objs[i];
			++rt->n_ts;
			rt->ts[rt->n_ts].t = xs.t[1];
			rt->ts[rt->n_ts].object = rt->objs[i];
			++rt->n_ts;
		}
		++i;
	}
	quicksort(rt->ts, 0, rt->n_ts -1);
}

/**
 * @brief	returns hit from list of intersections
 * returns a hit float which is the lowest positive
 * number from a list of intersection values
 *
 * @param rt	pointer to the main data struct
 * @return		hit value from list of intersections
 *				value with be -1 if none are found
 */
t_float	hit(t_minirt *rt)
{
	int		i;
	t_float	res;

	i = 0;
	res = 0;
	while (i < rt->n_ts)
	{
		if (rt->ts[i].t >= 0)
		{
			res = rt->ts[i].t;
			return (res);
		}
		i++;
	}
	return (-1.f);
}
