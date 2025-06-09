/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object05.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:54:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/09 16:48:44 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and returns a camera object
 * creates and asigned properties to a camera object
 * @param vsize		height of camera
 * @param hsize		width of camera
 * @return			t_camera object
 */
t_camera	camera(int h_size, int w_size, t_float fov)
{
	t_camera	cam;

	cam.dim[h] = h_size;
	cam.dim[w] = w_size;
	cam.fov = fov;
	cam.transform = id_matrix4();
	cam.half_view = tan(cam.fov / 2);
	cam.aspect = cam.dim[w] / cam.dim[h];
	if (cam.aspect >= 1)
	{
		cam.half[w] = cam.half_view;
		cam.half[h] = cam.half_view / cam.aspect;
	}
	else
	{
		cam.half[w] = cam.half_view * cam.aspect;
		cam.half[h] = cam.half_view;
	}
	cam.pixel_size = (cam.half[w] * 2) / cam.dim[w];
	return (cam);
}
