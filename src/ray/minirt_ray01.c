/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:15:41 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/28 17:02:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_intersections	sphere_intersection(t_object sphere, t_ray ray)
{
	t_tuple	sphere_to_ray;
	t_float dp[3];
	t_float	discriminant;
	t_intersections	res;

	sphere_to_ray = sub_tuples(ray.origin, sphere.origin);	
	dp[a] = dot_product(ray.direction, ray.direction);
	dp[b] = 2.0 * dot_product(ray.direction, sphere_to_ray);
	dp[c] = dot_product(sphere_to_ray, sphere_to_ray) - (sphere.radius * sphere.radius);
	discriminant = (dp[b] * dp[b]) - (4 * dp[a] * dp[c]);
	res.t[0] = (-dp[b] - sqrtf(discriminant)) / (2.0 * dp[a]);
	res.t[1] = (-dp[b] + sqrtf(discriminant)) / (2.0 * dp[a]);
	res.count = 2;
	return (res);
}
