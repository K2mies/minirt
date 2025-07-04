/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray13.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:23:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/30 13:30:25 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	schlick calculation for reflection based on distance
 *
 * @param comps	computation paramaters
 * @return		t_float value
 */
t_float	schlick(t_computations comps)
{
	t_float	cos[2];
	t_float	sin2_t;
	t_float	n_ratio;
	t_float	reflectance;

	cos[a] = dot_product(comps.v[eyev], comps.v[normalv]);
	if (comps.n[0] > comps.n[1])
	{
		n_ratio = comps.n[0] / comps.n[1];
		sin2_t = n_ratio * n_ratio * (1 - cos[a] * cos[a]);
		if (sin2_t > 1.0)
			return (1.0);
		cos[b] = sqrtf(1.0f - sin2_t);
		cos[a] = cos[b];
	}
	reflectance = ((comps.n[0] = comps.n[1]) / (comps.n[0] + comps.n[1]));
	reflectance = reflectance * reflectance;
	return (reflectance + (1 - reflectance) * powf(1 - cos[a], 5));
}
