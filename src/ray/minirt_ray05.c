/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:30:46 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/06 16:06:35 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_computations prepare_computations(t_intersection i, t_ray r)
{
	t_computations	comps;
	t_tuple			over_point;

	comps.t = i.t;
	comps.object = i.object;
	comps.v[pos] = position(r, comps.t);
	comps.v[eyev] = negate_tuple(r.direction);
	comps.v[normalv] = normal_at(comps.object, comps.v[pos]);
	if (dot_product(comps.v[normalv], comps.v[eyev]) < 0)
	{
		comps.inside = true;
		comps.v[normalv] = negate_tuple(comps.v[normalv]);
	}
	else
		comps.inside = false;
	over_point = multiply_tuple_by_scalar(comps.v[normalv], EPSILON);
	comps.over_point = add_tuples(comps.v[pos], over_point);
	return (comps);
}
