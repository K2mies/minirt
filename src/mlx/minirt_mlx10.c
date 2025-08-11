/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx09.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:06:39 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/05 16:50:29 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	handles Y key press case
 * scales on the x axis by 1.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_y_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;
	

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1.1, 1, 1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on x by 1.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles Y key press case
 * scales on the y axis by 1.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_u_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;
	

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1, 1.1, 1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on y by 1.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles I key press case
 * scales on the z axis by 1.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_i_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;
	

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1, 1, 1.1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on z by 1.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handles O key press case
 * scales on all axies by 1.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_o_press(t_minirt *rt)
{
	t_matrix4	scale_matrix;
	t_matrix4	*scale_transform;
	t_object	*obj;
	

	if (rt->is_active_object)
	{
		scale_matrix = scaling(1.1, 1.1, 1.1);
		obj = &rt->w.objs[rt->active_object.index];
		scale_transform = &obj->transforms[scale][xyz];
		*scale_transform = multiply_matrix4(*scale_transform, scale_matrix);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object scaled on all axis by 1.5\n");
		printf("scene rendered\n");
	}
}
