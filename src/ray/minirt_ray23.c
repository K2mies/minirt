/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray23.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:06:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 14:15:15 by mpierce          ###   ########.fr       */
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

/**
 * @brief	calculates shading for hit intersection
 * returns a color calculated  from the shading
 *
 * @param w		world object to calculate hit
 * @param comps	computation paramaters
 * @return		color for shaded pixel
 */
t_color	shade_hit(t_world w, t_computations comps, t_object	obj, int remaining)
{
	t_lighting_param	param;
	t_color				col[3];
	t_material			material;
	t_float				reflectance;
	t_float				ref[2];


	param.ambient[env] = w.ambient.color;
	param.ratio = w.ambient.ratio;
	param.in_shadow = is_shadowed(w, comps.over_point);
	param.obj = obj;
	col[surface] = lighting(param, comps.object.material, w.light, comps.v);
	col[reflected] = reflected_color(w, comps, remaining);
	col[refracted] = refracted_color(w, comps, remaining);
	material = comps.object.material;
	if (material.reflective > 0 && material.transparency > 0)
	{
		reflectance = schlick(comps);
		ref[a] = reflectance;
		ref[b] = 1 - reflectance;
		col[reflected] = multiply_color_by_scalar(col[reflected], ref[a]);
		col[refracted] = multiply_color_by_scalar(col[refracted],  ref[b]);
		return (add_three_colors(col[surface], col[reflected], col[refracted]));
	}
	return (add_three_colors(col[surface], col[reflected], col[refracted]));
}
