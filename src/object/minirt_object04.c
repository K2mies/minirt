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

