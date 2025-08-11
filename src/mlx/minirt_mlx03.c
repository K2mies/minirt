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
 * @brief	handle LOCATION key presses
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
	if(mlx_is_key_down(rt->mlx, MLX_KEY_Z))
		handle_z_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_X))
		handle_x_press(rt);
}

/**
 * @brief	handle ROTATION key presses
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
 * @brief	handle SCALE key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_scaling(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_Y))
		handle_y_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_U))
		handle_u_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_I))
		handle_i_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_O))
		handle_o_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_H))
		handle_h_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_J))
		handle_j_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_K))
		handle_k_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_L))
		handle_l_press(rt);
}

/**
 * @brief	handle OTHER key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_other(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_G))
		handle_g_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_P))
		handle_p_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_M))
		handle_m_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_N))
		handle_n_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_R))
		handle_r_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_T))
		handle_t_press(rt);
	if(mlx_is_key_down(rt->mlx, MLX_KEY_C))
		handle_c_press(rt);
}

/**
 * @brief	handle ESC key presses
 * takes input and redirects the apropriate key press to function
 * @param	void *param pointer to rt data struct
 */
void handle_key_esc(void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if (mlx_is_key_down(rt->mlx, MLX_KEY_ESCAPE))
		handle_esc_press(rt);
}
