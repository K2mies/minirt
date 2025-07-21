/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray07.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 11:05:28 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/17 16:58:42 by mpierce          ###   ########.fr       */
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

static void	handle_discriminant(t_float	var[3], t_intersections *res, t_float discriminant)
{
	if (discriminant <= EPSILON)
	{
		printf("three\n");
		res->t[res->count] = -var[b] / (2.0f * var[a]);
		res->t[res->count + 1] = res->t[0];
//		res->count++;
	}
	else
	{
		printf("four\n");
		res->t[res->count] = (-var[b] - sqrtf(discriminant)) / (2.0 * var[a]);
		res->t[res->count + 1] = (-var[b] + sqrtf(discriminant)) / (2.0 * var[a]);
//		res->count++;
//		res->count++;
	}
}
/**
 * @brief	intersections  of a ray and a cylinder
 *
 * @param cylinder	cyliunder object to be intersected
 * @param ray		Ray to cast
 * @return			t_intersections	result of intersections
 */
t_intersections		cone_intersection(t_object *cone, t_ray ray)
{
	t_intersections	res;
	t_float			discriminant;
	t_float			var[3];
	t_float			t;

	ray = transform(ray, inverse_matrix4(cone->transform));
	cone->saved_ray = ray;
	res.count = 0;
	var[a] = calculate_var_a(ray);
	var[b] = calculate_var_b(ray);
	var[c] = calculate_var_c(ray);
	t = -var[c] / (2.0f * var[b]);
	printf("t = %f\n", t);
	printf("var[a] = %f\n", var[a]);
	printf("var[b] = %f\n", var[b]);
	printf("var[c] = %f\n", var[c]);
	discriminant = var[b] * var[b] - 4.0f * var[a] * var[c];
//	if (fabs(var[a]) < EPSILON)
	if (fabs(var[a]) <= 0.0f || compare_floats(fabs(var[a]), 0.0f))
//	if (compare_floats(var[a], 0.0f))
	{
		printf("one\n");
		if(fabs(var[b]) < EPSILON)
//		if (var[b] <= 0.0f || compare_floats(var[b], 0.0f))
//		if (compare_floats(var[b], 0.0f))
		{
			printf("two\n");
			return (res);
		}
		handle_discriminant(var, &res, discriminant);
		truncate_cone(cone, ray, &res);
		res = intersect_cone_caps(cone, ray, res);
//		truncate_cone(cone, ray, &res);
		return (res);
	}
	if (discriminant < -EPSILON)
		return (res);
	handle_discriminant(var, &res, discriminant);
	truncate_cone(cone, ray, &res);
	res = intersect_cone_caps(cone, ray, res);
//	truncate_cone(cone, ray, &res);
	return (res);
}
