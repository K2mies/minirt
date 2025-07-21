/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object09.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:54:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:13:57 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	Helper function to calculate pixel size on canvas
 * calculates the size of a pixel on the canvas
 * @param cam		pointer to the camera object to operate on
 */
static void	calculate_pixel_size(t_camera *cam)
{
	cam->half_view = tanf(cam->fov / 2.f);
	cam->aspect = cam->dim[width] / cam->dim[height];
	if (cam->aspect >= 1)
	{
		cam->half[width] = cam->half_view;
		cam->half[height] = cam->half_view / cam->aspect;
	}
	else
	{
		cam->half[width] = cam->half_view * cam->aspect;
		cam->half[height] = cam->half_view;
	}
	cam->pixel_size = (cam->half[width] * 2.f) / cam->dim[width];
}

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

	cam.dim[height] = h_size;
	cam.dim[width] = w_size;
	cam.fov = fov;
	cam.transform = id_matrix4();
	calculate_pixel_size(&cam);
	return (cam);
}
