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
 * @param rt	pointer to the main data struct
 * @return		hit value from list of intersections
 *				value with be -1 if none are found
 */
t_float	hit(t_minirt *rt)
{
	int		i;
	t_float	res;

	i = 0;
	res = 0;
	while (i < rt->n_ts)
	{
		if (rt->ts[i].t >= 0)
		{
			res = rt->ts[i].t;
			return (res);
		}
		i++;
	}
	return (-1.f);
}

t_color	shade_hit(t_world w, t_computations comps)
{
	t_color	res;

	res = lighting(comps.object.material, w.light, comps.v);
	return (res);
}
