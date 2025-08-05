/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 15:44:14 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/05 15:47:32 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	handle Z key press case
 * translates object on the z axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_z_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_matrix4	*move;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(0, 0, 0.5);
		obj = &rt->w.objs[rt->active_object.index];
		move = &obj->transforms[translate][xyz];
		*move = multiply_matrix4(*move, transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on z by 0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	handle X key press case
 * translates object on the z axis by -0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_x_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_matrix4	*move;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(0, 0, -0.5);
		obj = &rt->w.objs[rt->active_object.index];
		move = &obj->transforms[translate][xyz];
		*move = multiply_matrix4(*move, transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on z by -0.5\n");
		printf("scene rendered\n");
	}
}
