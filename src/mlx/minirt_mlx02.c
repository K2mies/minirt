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

void	handle_e_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	transform;

	rot[z] = rotation_z(10);
	if (rt->is_active_object)
	{
		transform = rt->w.objs[rt->active_object.index].transform;
		transform = multiply_matrix4(transform, rot[z]);
		rt->w.objs[rt->active_object.index].transform = transform;
		printf("object rotated on z by 10degree\n");
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}

}

void	handle_w_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	transform;

	rot[y] = rotation_y(10);
	if (rt->is_active_object)
	{
		transform = rt->w.objs[rt->active_object.index].transform;
		transform = multiply_matrix4(transform, rot[y]);
		rt->w.objs[rt->active_object.index].transform = transform;
		printf("object rotated on y by 10degree\n");
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}

}

void	handle_q_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	transform;

	rot[x] = rotation_x(10);
	if (rt->is_active_object)
	{
		transform = rt->w.objs[rt->active_object.index].transform;
		transform = multiply_matrix4(transform, rot[x]);
		rt->w.objs[rt->active_object.index].transform = transform;
		printf("object rotated on x by 10degree\n");
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}

}

void handle_key_press(mlx_key_data_t keydata, void *param)
{
	t_minirt	*rt;

	rt = (t_minirt *)param;
	if(mlx_is_key_down(rt->mlx, MLX_KEY_Q))
	{
		handle_q_press(rt);
		printf("key: %d\n", keydata.key);
	}
	if(mlx_is_key_down(rt->mlx, MLX_KEY_W))
	{
		handle_w_press(rt);
		printf("key: %d\n", keydata.key);
	}
	if(mlx_is_key_down(rt->mlx, MLX_KEY_E))
	{
		handle_w_press(rt);
		printf("key: %d\n", keydata.key);
	}
}
