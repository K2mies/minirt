/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:27:15 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:26:03 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	handles Y key press case
 * scales on the x axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_h_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		scale_matrix = scaling(0.9, 1, 1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("objec scaled on x by 0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles J key press case
 * scales on the y axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_j_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1, 0.9, 1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on y by 0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles K key press case
 * scales on the z axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_k_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1, 1, 0.9);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on z by 0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles L key press case
 * scales on all axies by 1.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_l_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		scale_matrix = scaling(0.9, 0.9, 0.9);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on all axis by 0.5\n");
		printf("scene rendered\n");
	}
}
