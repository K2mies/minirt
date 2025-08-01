/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx05.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 14:38:05 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/01 15:18:00 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand UP key press case
 * translates object on the y axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_up_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(0, 0.5, 0);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[translate][xyz] = multiply_matrix4(
			obj->transforms[translate][xyz], transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on y by 0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand DOWN key press case
 * translates object on the y axis by -0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_down_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(0, -0.5, 0);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[translate][xyz] = multiply_matrix4(
			obj->transforms[translate][xyz], transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on y by -0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand LEFT key press case
 * translates object on the x axis by -0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_left_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(-0.5, 0, 0);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[translate][xyz] = multiply_matrix4(
			obj->transforms[translate][xyz], transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on x by -0.5\n");
		printf("scene rendered\n");
	}
}

/**
 * @brief	hand RIGHT key press case
 * translates object on the x axis by 0.5
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_right_press(t_minirt *rt)
{
	t_matrix4	transform;
	t_object	*obj;

	if (rt->is_active_object)
	{
		transform = translation(0.5, 0, 0);
		obj = &rt->w.objs[rt->active_object.index];
		obj->transforms[translate][xyz] = multiply_matrix4(
			obj->transforms[translate][xyz], transform);
		apply_transforms(obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("object translated on x by 0.5\n");
		printf("scene rendered\n");
	}
}
