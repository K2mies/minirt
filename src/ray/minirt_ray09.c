/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray07.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:34:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/09 11:15:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	fetches color at intersection point
 * returns a color from the hit point of an intersection
 * taking into account all the lighting computations
 * @param w			wpr;d object to operate on
 * @param r			ray to cast for intersections
 * @return			t_color returned color;
 */
t_color	color_at(t_world w, t_ray r)
{
	t_intersection	hit_point;
	t_color			res;

	world_intersect(&w, r);
	hit_point = hit(&w);
	if(hit_point.t >= 0)
	{
		w.cs[w.hit_index] = prepare_computations(hit_point, r);
		res = shade_hit(w, w.cs[w.hit_index], hit_point.object);
	}
	else
		res = color(0, 0, 0);
	return (res);
}
