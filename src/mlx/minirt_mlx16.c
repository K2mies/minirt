/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx16.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:23:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:22:54 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand key R key press case
 * changes window resolution 
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_r_press(t_minirt *rt)
{
	int32_t	size[3][2];

	size[big][width] = 100 * 10;
	size[big][height] = 50 * 10;
	size[small][width] = 100 * 3;
	size[small][height] = 50 * 3;
	if (rt->w.camera.dim[width] == size[small][width])
	{
		rt->w.camera.dim[width] = size[big][width];
		rt->w.camera.dim[height] = size[big][height];
		resize_screen(size[big][width], size[big][height], rt);
		printf("scene size set to BIG\n");
	}
	else
	{
		rt->w.camera.dim[width] = size[small][width];
		rt->w.camera.dim[height] = size[small][height];
		resize_screen(size[small][width], size[small][height], rt);
		printf("scene size set to SMALL\n");
	}
	calculate_pixel_size(&rt->w.camera);
	mlx_render(rt, rt->w.camera, rt->w);
	printf("scene rendered\n");
}
