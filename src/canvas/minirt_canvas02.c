/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:12:39 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:09:14 by mpierce          ###   ########.fr       */
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
	t_render_param	p;
	int				x;
	int				y;

	p.img = canvas(cam.dim[width], cam.dim[height]);
	p.bounce_limit = BOUNCE_LIMIT;
	y = -1;
	while (++y < cam.dim[height])
	{
		x = -1;
		while (++x < cam.dim[width])
		{

			p.bounce_limit = BOUNCE_LIMIT;
			p.ray = ray_for_pixel(cam, x, y);
			p.col = color_at(world, p.ray, p.bounce_limit);	
			write_pixel_to_canvas(p.img, x, y, p.col);
		}
	}
	return (p.img);
}

/**
 * @brief	renders an img to mlx window
 * writes a pixel to mlx img per pixel
 * @param rt		Pointer to main data struct
 * @param cam		camera object for operations
 * @param world		world object for operations
 */
void	mlx_render(t_minirt *rt, t_camera cam, t_world world)
{
	t_render_param	p;
	int	y;
	int	x;

	p.bounce_limit = BOUNCE_LIMIT;
	y = -1;
	while (++y < cam.dim[height])
	{
		x = -1;
		while (++x < cam.dim[width])
		{
			p.bounce_limit = BOUNCE_LIMIT;
			p.ray = ray_for_pixel(cam, x, y);
			p.col = color_at(world, p.ray, p.bounce_limit);
			mlx_put_pixel(rt->img, x, y, p.col.rgba);
		}
	}
}
