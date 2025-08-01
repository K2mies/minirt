/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:19:44 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/29 16:21:04 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void handle_key_press(mlx_key_data_t keydata, void *param)
{
	t_minirt	*rt;

	(void)keydata;
	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_UP))
		handle_up_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_DOWN))
		handle_down_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_LEFT))
		handle_left_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_RIGHT))
		handle_right_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_Q))
		handle_q_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_W))
		handle_w_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_E))
		handle_w_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_A))
		handle_a_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_S))
		handle_s_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_D))
		handle_d_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_P))
		handle_p_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_M))
		handle_m_press(rt);
}
