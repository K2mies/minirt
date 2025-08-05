/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx10.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:20:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/05 14:21:05 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand key M key press case
 * changes selected objects material to GLASS/REFRACTION
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_m_press(t_minirt *rt)
{
	t_object	*obj;

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
