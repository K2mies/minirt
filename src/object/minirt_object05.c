/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:31:28 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/06 16:06:18 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and returns a world object
 * creates and populates from rt a word object
 * @param rt		Pointer to main data struct
 * @return			t_world object
 */
t_world	world(t_minirt *rt)
{
	t_world	w;

	w.light = rt->light;
	w.objs = rt->objs;
	w.n_objs = rt->n_objs;
	w.ts =	rt_malloc(rt ,sizeof(t_intersection) * (w.n_objs * 2));
	w.cs = rt_malloc(rt, sizeof(t_computations) * (w.n_objs * 2));
	w.n_ts = 0;
	return(w);
}

/**
 * @brief	creates a default world object
 * creates and populates a default world which is assumed to have two sphear
 * objects and a light. Also assumes that .rt file is default file
 * @param rt		Pointer to main data struct
 * @return			t_world object
 */
t_world	default_world(t_minirt *rt)
{
	t_world	w;
	t_color	col;

	w = world(rt);
	col = color(0.8, 1.0, 0.6);
	w.objs[0].color = col;
	w.objs[0].material.color = col;
	w.objs[0].material.diffuse = 0.7;
	w.objs[0].material.specular = 0.2;
	w.objs[1].transform = scaling(0.5, 0.5, 0.5);
	w.light = point_light(point(-10, 10, -10), 1.0, color(1, 1, 1));
	return (w);
}
