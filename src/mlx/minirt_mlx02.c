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

/**
 * @brief	handle location key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_location(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_UP))
		handle_up_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_DOWN))
		handle_down_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_LEFT))
		handle_left_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_RIGHT))
		handle_right_press(rt);
}

/**
 * @brief	handle rotation key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_rotation(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
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
}

/**
 * @brief	handle other key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_other(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_P))
		handle_p_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_M))
		handle_m_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_R))
		handle_r_press(rt);
}
