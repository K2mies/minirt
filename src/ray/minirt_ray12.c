/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray12.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:24:04 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/27 15:12:38 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"


t_color	refracted_color(t_world w, t_computations comps, int *remaining)
{
	t_refracted_color_param	p;

	p.n_ratio = comps.n[0] / comps.n[1];
	p.cos[a] = dot_product(comps.v[eyev], comps.v[normalv]);
//	p.sin2_t = powf(p.n_ratio, 2) * (1 - powf(p.cos[a], 2));
	p.sin2_t = (p.n_ratio * p.n_ratio) * (1 - (p.cos[a] * p.cos[a]));
	printf("p.sin2_t: %f\n", p.sin2_t);
	if (comps.object.material.transparency == 0
		|| p.sin2_t > 1 || *remaining <= 0)
		return (color(0, 0, 0));
	p.cos[b] = sqrtf(1.0 - p.sin2_t);
	p.calculation = p.n_ratio * p.cos[a] - p.cos[b];
	p.direction[a] = multiply_tuple_by_scalar(comps.v[normalv], p.calculation);
	p.direction[b] = multiply_tuple_by_scalar(comps.v[eyev], p.n_ratio);
	p.direction[c] = sub_tuples(p.direction[a], p.direction[b]);
	p.refract_ray = ray(comps.under_point, p.direction[c]);
	*remaining -= 1;
	p.res = color_at(w, p.refract_ray, remaining);
	p.res = multiply_color_by_scalar(p.res, comps.object.material.transparency);
	return(p.res);
}
