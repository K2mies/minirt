/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color11.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:55:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/14 16:31:35 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	calculates paramaters for refracted color
 *
 * @param w				world object to calculate from
 * @param comps			computations to use
 * @param remaining		pointer to remaining recursive bounces
 * @return				color for refracted color
 */
t_color	refracted_color(t_world w, t_computations comps, int remaining)
{
	t_refracted_color_param	p;

	if (remaining <= 0)
		return (color(0, 0, 0));
	if (comps.object.material.transparency == 0)
		return (color(0, 0, 0));
	p.n_ratio = comps.n[0] / comps.n[1];
	p.cos[a] = dot_product(comps.v[eyev], comps.v[normalv]);
	p.sin2_t = p.n_ratio * p.n_ratio * (1 - p.cos[a] * p.cos[a]);
	if (p.sin2_t > 1)
		return (color(0, 0, 0));
	p.cos[b] = sqrtf(1.0 - p.sin2_t);
	p.calculation = p.n_ratio * p.cos[a] - p.cos[b];
	p.direction[a] = multiply_tuple_by_scalar(comps.v[normalv], p.calculation);
	p.direction[b] = multiply_tuple_by_scalar(comps.v[eyev], p.n_ratio);
	p.direction[c] = sub_tuples(p.direction[a], p.direction[b]);
	p.refract_ray = ray(comps.under_point, p.direction[c]);
	p.res = color_at(w, p.refract_ray, remaining - 1);
	p.res = multiply_color_by_scalar(p.res, comps.object.material.transparency);
	return(p.res);
}
