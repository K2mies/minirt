/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx09.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 15:18:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:27:34 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand q key press case
 * rotates object on the x axis by -10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_a_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[x] = rotation_x(-10);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[rotate][x] = multiply_matrix4(
				obj->transforms[rotate][x], rot[x]);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object rotated on x by 10degree\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand w key press case
 * rotates object on the y axis by -10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_s_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[y] = rotation_y(-10);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[rotate][y] = multiply_matrix4(
				obj->transforms[rotate][y], rot[y]);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object rotated on y by 10degree\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand e key press case
 * rotates object on the z axis by -10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_d_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[z] = rotation_z(-10);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[rotate][z] = multiply_matrix4(
				obj->transforms[rotate][z], rot[z]);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object rotated on z by 10degree\n");
		printf("scene rendered\n");
	}
}
