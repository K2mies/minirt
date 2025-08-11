/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:38:44 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:55:46 by mpierce          ###   ########.fr       */
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
	ray_direction_sqr[z] = ray.direction.z * ray.direction.z;
	var_a = ray_direction_sqr[x] + ray_direction_sqr[z];
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
	t_float	ray_dir_by_origin[3];
	t_float	var_b;

	ray_dir_by_origin[x] = ray.origin.x * ray.direction.x;
	ray_dir_by_origin[z] = ray.origin.z * ray.direction.z;
	var_b = (2 * ray_dir_by_origin[x]) + (2 * ray_dir_by_origin[z]);
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
	ray_origin_sqr[z] = ray.origin.z * ray.origin.z;
	var_c = (ray_origin_sqr[x] + ray_origin_sqr[z]) - 1.0f;
	return (var_c);
}

/**
 * @brief	helper function to handle and asign t values from discrimintant
 *
 * @param var[3]		var[a-c] for calculations
 * @param discriminant	discriminant to use for calculation
 * @param res			pointer to the xs intersection to operate on
 */
static void	handle_discriminant(t_float var[3], t_float discriminant,
								t_intersections *res)
{
	res->t[0] = (-var[b] - sqrtf(discriminant)) / (2.0 * var[a]);
	res->t[1] = (-var[b] + sqrtf(discriminant)) / (2.0 * var[a]);
	if (res->t[0] > res->t[1])
		swapf(&res->t[0], &res->t[1]);
}

/**
 * @brief	intersections  of a ray and a cylinder
 *
 * @param cylinder	cyliunder object to be intersected
 * @param ray		Ray to cast
 * @return			t_intersections	result of intersections
 */
t_intersections	cylinder_intersection(t_object *cylinder, t_ray ray)
{
	t_intersections	res;
	t_float			discriminant;
	t_float			var[3];

	ray = transform(ray, inverse_matrix4(cylinder->transform));
	cylinder->saved_ray = ray;
	res.count = 0;
	var[a] = calculate_var_a(ray);
	var[b] = calculate_var_b(ray);
	var[c] = calculate_var_c(ray);
	discriminant = (var[b] * var[b]) - (4.0f * var[a] * var[c]);
	handle_discriminant(var, discriminant, &res);
	if (compare_floats(var[a], 0.0f))
	{
		truncate_cylinder(cylinder, ray, &res);
		res = intersect_cylinder_caps(cylinder, ray, res);
		return (res);
	}
	if (discriminant < 0)
		return (res);
	truncate_cylinder(cylinder, ray, &res);
	res = intersect_cylinder_caps(cylinder, ray, res);
	return (res);
}
