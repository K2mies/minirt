/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:10:55 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:27:51 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand q key press case
 * rotates object on the x axis by 10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_q_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	*rot_mat_x;
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[x] = rotation_x(10);
		obj = &rt->w.objs[rt->active_object.index];
		rot_mat_x = &obj->transforms[rotate][x];
		*rot_mat_x = multiply_matrix4(*rot_mat_x, rot[x]);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object rotated on x by 10degree\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand w key press case
 * rotates object on the y axis by 10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_w_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	*rot_mat_y;
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[y] = rotation_y(10);
		obj = &rt->w.objs[rt->active_object.index];
		rot_mat_y = &obj->transforms[rotate][y];
		*rot_mat_y = multiply_matrix4(*rot_mat_y, rot[y]);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object rotated on y by 10degree\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand e key press case
 * rotates object on the z axis by 10 degree
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_e_press(t_minirt *rt)
{
	t_matrix4	rot[3];
	t_matrix4	*rot_mat_z;
	t_object	*obj;

	if (rt->is_active_object)
	{
		rot[z] = rotation_z(10);
		obj = &rt->w.objs[rt->active_object.index];
		rot_mat_z = &obj->transforms[rotate][z];
		*rot_mat_z = multiply_matrix4(*rot_mat_z, rot[z]);
		apply_transforms(obj);
		printf("object rotated on z by 10degree\n");
		printf("scene rendered\n");
	}
}
