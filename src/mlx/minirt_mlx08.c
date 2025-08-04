/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:59:10 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/04 12:01:29 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "minirt.h"

/**
 * @brief	hand key P key press case
 * changes selected object to patterned checker
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_p_press(t_minirt *rt)
{
	t_object	*obj;

	if (rt->is_active_object)
	{
		obj = &rt->w.objs[rt->active_object.index];
		if (obj->material.has_pattern == false)
			obj->material.has_pattern = true;
		else
			obj->material.has_pattern = false;
		obj->material.pattern = pattern(color(0,0,0), color(1,1,1), CHECKER);
		obj->material.pattern.transform = scaling(0.5, 0.5, 0.5);
		printf("pattern set to checkered\n");
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}

}

/**
 * @brief	hand key M key press case
 * changes selected objects material to glass
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_m_press(t_minirt *rt)
{
	t_object *obj;

	if (rt->is_active_object)
	{
		obj = &rt->w.objs[rt->active_object.index];
		if (obj->material.refractive_index == 1.0)
		{
			obj->material.refractive_index = 1.5;
			obj->material.transparency = 0.5;
		}
		else
		{
			obj->material.refractive_index = 1.0;
			obj->material.transparency = 1.0;
		}
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}
}


void	handle_r_press(t_minirt *rt)
{
	int32_t	big[2];
	int32_t	small[2];

	big[width] = 100 * 10;
	big[height] = 50 * 10;
	small[width] = 100 * 3;
	small[height] =  50  * 3;
	if(rt->w.camera.dim[width] == small[width])
	{
		mlx_delete_image(rt->mlx, rt->img);
		rt->w.camera.dim[width] = big[width];
		rt->w.camera.dim[height] = big[height];
//		mlx_resize_image(rt->img, big[width], big[height]);
		rt->mlx->width = big[width];
		rt->mlx->height = big[height];
		mlx_set_window_size(rt->mlx, big[width], big[height]);
		rt->img = mlx_new_image(rt->mlx, big[width], big[height]);
		mlx_image_to_window(rt->mlx, rt->img, 0, 0);
		printf("scene size set to BIG\n");
	}
	else
	{
		mlx_delete_image(rt->mlx, rt->img);
		rt->w.camera.dim[width] = small[width];
		rt->w.camera.dim[height] = small[height];
//		mlx_resize_image(rt->img, small[width], small[height]);
		rt->mlx->width = small[width];
		rt->mlx->height = small[height];
		mlx_set_window_size(rt->mlx, small[width], small[height]);
		rt->img = mlx_new_image(rt->mlx, small[width], small[height]);
		mlx_image_to_window(rt->mlx, rt->img, 0, 0);
		printf("scene size set to SMALL\n");
	}
	mlx_render(rt, rt->w.camera, rt->w);
	printf("scene rendered\n");
}
