/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:44:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/06 12:18:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	color_fill(t_minirt *rt)
{
	int	x;
	int	y;

	x = 0;
	while (x < rt->mlx_d[width])
	{
		y = 0;
		while (y < rt->mlx_d[height])
		{
			mlx_put_pixel(rt->img, x, y, BLACK);
			y++;
		}
		x++;
	}
}


void	mlx_start(t_minirt *rt, int x, int y)
{
	mlx_set_setting(MLX_MAXIMIZED, false);
	rt->mlx = mlx_init(x, y, "miniRT", true);
	rt->mlx_d[width] = x;
	rt->mlx_d[height] = y;
	if (!rt->mlx)
		rt_error(rt, MSG_ERROR_MLX, ERROR_MLX);
//	mlx_get_monitor_size(0, &rt->mlx_d[width], &rt->mlx_d[height]);
	printf("x: %d y: %d\n", rt->mlx_d[width], rt->mlx_d[height]);
	rt->img = mlx_new_image(rt->mlx, rt->mlx_d[width], rt->mlx_d[height]);
	if (!rt->img)
		rt_error(rt, MSG_ERROR_MLX_IMG, ERROR_IMG);
}
