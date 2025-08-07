/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 14:03:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/06 14:15:58 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * @brief function to run MLX logic and loop
 * @param	t_minirt *rt pointer to main data struct
 */
void	run_mlx(t_minirt *rt)
{
	rt->w = world_scene(rt);
	mlx_start(rt, CAM_WIDTH, CAM_HEIGHT);
	color_fill(rt);
	mlx_render(rt, rt->w.camera,  rt->w);
	mlx_loop_hook(rt->mlx, handle_key_esc, rt);
	mlx_loop_hook(rt->mlx, handle_key_location, rt);
	mlx_loop_hook(rt->mlx, handle_key_rotation, rt);
	mlx_loop_hook(rt->mlx, handle_key_scaling, rt);
	mlx_loop_hook(rt->mlx, handle_key_other, rt);
	mlx_mouse_hook(rt->mlx, handle_mouse_click, rt);
	mlx_cursor_hook(rt->mlx, handle_mouse_move, rt);
	mlx_loop(rt->mlx);
	mlx_delete_image(rt->mlx, rt->img);
	mlx_terminate(rt->mlx);
}
