/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray07.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:28 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:49:53 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to calculate var a
 *
 * @param ray		Ray to use for calculation
 * @return			t_flaot var a
 */

static t_float	calculate_var_a(t_ray ray)
{
	t_float	ray_direction_sqr[3];
	t_float	var_a;

	ray_direction_sqr[x] = ray.direction.x * ray.direction.x;
	ray_direction_sqr[y] = ray.direction.y * ray.direction.y;
	ray_direction_sqr[z] = ray.direction.z * ray.direction.z;
	var_a = ray_direction_sqr[x] - ray_direction_sqr[y] + ray_direction_sqr[z];
	return (var_a);
}

/**
 * @brief	helper function to calculate var b
 *
 * @param ray		Ray to use for calculation
 * @return			t_flaot var a
 */
static t_float	calculate_var_b(t_ray ray)
{
	t_float	ray_origin_by_dir[3];
	t_float	var_b;

	ray_origin_by_dir[x] = ray.origin.x * ray.direction.x;
	ray_origin_by_dir[y] = ray.origin.y * ray.direction.y;
	ray_origin_by_dir[z] = ray.origin.z * ray.direction.z;
	var_b = ray_origin_by_dir[x] - ray_origin_by_dir[y] + ray_origin_by_dir[z];
	var_b = 2.0f * var_b;
	return (var_b);
}

/**
 * @brief	helper function to calculate var c
 *
 * @param ray		Ray to use for calculation
 * @return			t_flaot var c
 */
static t_float	calculate_var_c(t_ray ray)
{
	t_float	ray_origin_sqr[3];
	t_float	var_c;

	ray_origin_sqr[x] = ray.origin.x * ray.origin.x;
	ray_origin_sqr[y] = ray.origin.y * ray.origin.y;
	ray_origin_sqr[z] = ray.origin.z * ray.origin.z;
	var_c = ray_origin_sqr[x] - ray_origin_sqr[y] + ray_origin_sqr[z];
	return (var_c);
}

static void	handle_discriminant(t_float	var[3], t_intersections *res,
								t_float discriminant)
{
	t_float	sum[2];

	sum[a] = 0;
	sum[b] = 0;
	if (discriminant <= EPSILON)
	{
		res->t[res->count] = -var[b] / (2.0f * var[a]);
		res->t[res->count + 1] = res->t[res->count];
	}
	else
	{
		sum[a] = (-var[b] - sqrtf(discriminant)) / (2.0 * var[z]);
		sum[b] = (-var[b] + sqrtf(discriminant)) / (2.0 * var[z]);
		res->t[res->count] = sum[a];
		res->t[res->count + 1] = sum[b];
	}
}

/**
 * @brief	intersections  of a ray and a cylinder
 *
 * @param cylinder	cyliunder object to be intersected
 * @param ray		Ray to cast
 * @return			t_intersections	result of intersections
 */
t_intersections	cone_intersection(t_object *cone, t_ray ray)
{
	t_intersections	res;
	t_float			discriminant;
	t_float			var[3];

	ray = transform(ray, inverse_matrix4(cone->transform));
	cone->saved_ray = ray;
	res.count = 0;
	var[a] = calculate_var_a(ray);
	var[b] = calculate_var_b(ray);
	var[c] = calculate_var_c(ray);
	discriminant = var[b] * var[b] - 4.0f * var[a] * var[c];
	handle_discriminant(var, &res, discriminant);
	if (fabs(var[a]) < EPSILON)
	{
		if (fabs(var[b]) < EPSILON)
			return (res);
		truncate_cone(cone, ray, &res);
		res = intersect_cone_caps(cone, ray, res);
		return (res);
	}
	if (discriminant < -EPSILON)
		return (res);
	truncate_cone(cone, ray, &res);
	res = intersect_cone_caps(cone, ray, res);
	return (res);
}
