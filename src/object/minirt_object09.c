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
 * @brief	(helper) calculates the transform matrix of the camera
 * from origin and vector(direction)
 * @param	cam 
 * @return	t_matrix4 transform matrx
 */
static	t_matrix4	calculate_transform_matrix(t_camera cam)
{
	t_matrix4	m;
	t_matrix4	view;
//	t_tuple		direction;

	m = id_matrix4();
//	direction = add_tuples(cam.origin, cam.vector);
	view = view_transform(cam.origin, cam.vector, vector(0, 1, 0));
	m = multiply_matrix4(m, view);
	return (m);

}

/**
 * @brief	creates and returns a camera object
 * creates and asigned properties to a camera object
 * @param vec		vec[origin] and vec[direction]
 * @return			t_camera object
 */
t_camera	camera(t_tuple origin, t_tuple direction, t_float fov)
{
	t_camera	cam;

	cam.dim[height] = CAM_HEIGHT;
	cam.dim[width] = CAM_WIDTH;
	cam.origin = origin; 
	cam.vector = direction;
	cam.fov = fov;
	cam.transform = calculate_transform_matrix(cam);
	calculate_pixel_size(&cam);
	return (cam);
}
