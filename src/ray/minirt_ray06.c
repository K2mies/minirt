/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:06:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/06 16:41:22 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	returns hit from list of intersections
 * returns a hit float which is the lowest positive
 * number from a list of intersection values
 *
 * @param w		pointer to the world object to calculate hit
 * @return		hit value from list of intersections
 *				value with be -1 if none are found
 */
t_intersection	hit(t_world *w)
{
	int		i;
	t_intersection	res;

	i = 0;
	while (i < w->n_ts)
	{
		if (w->ts[i].t >= 0)
		{
			w->hit_index = i;
			res = w->ts[i];
			return (res);
		}
		i++;
	}
	res.t = -1;
	return (res);
}

t_color	shade_hit(t_world w, t_computations comps)
{
	t_color	res;

	res = lighting(comps.object.material, w.light, comps.v);
	return (res);
}
