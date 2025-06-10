/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:12:39 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/10 15:14:13 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	renders a canvas 
 * creates and writes to a canvas from camera point and world.
 * @param cam		Pointer to camera object
 * @return			t_canvas object
 */
t_canvas	*render(t_camera cam, t_world world)
{
	t_canvas	*img;
	t_color		col;
	t_ray		ray;
	int			x;
	int			y;

	img = canvas(cam.dim[width], cam.dim[height]);

	y = -1;
	while (++y < cam.dim[height])
	{
		x = -1;
		while (++x < cam.dim[width])
		{
			ray = ray_for_pixel(cam, x, y);
			col = color_at(world, ray);	
			write_pixel_to_canvas(img, x, y, col);
		}
	}
	return (img);
}
