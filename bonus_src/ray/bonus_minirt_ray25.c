/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray25.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:51:07 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:59:25 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray_for_pixel(t_camera cam, t_float px, t_float py)
{
	t_ray_for_pixel_param	p;
	t_matrix4				m;

	p.offset[x] = (px + 0.5) * cam.pixel_size;
	p.offset[y] = (py + 0.5) * cam.pixel_size;
	p.world[x] = cam.half[width] - p.offset[x];
	p.world[y] = cam.half[height] - p.offset[y];
	m = inverse_matrix4(cam.transform);
	p.pixel = multiply_matrix4_tuple(m, point(p.world[x], p.world[y], -1));
	p.origin = multiply_matrix4_tuple(m, point(0, 0, 0));
	p.direction = sub_tuples(p.pixel, p.origin);
	p.direction = normalize_vector(p.direction);
	return (ray(p.origin, p.direction));
}
