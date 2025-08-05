/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx11.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:23:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/05 14:23:41 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand key N key press case
 * changes material to reflective
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_n_press(t_minirt *rt)
{
	t_object	*obj;

	if (rt->is_active_object)
	{
		obj = &rt->w.objs[rt->active_object.index];
		if (obj->material.reflective == 0)
		{
			obj->material.reflective = 1.0f;
			printf("reflective set to 1.0\n");
		}
		else
		{
			obj->material.reflective = 0;
			printf("reflective set to 0\n");
		}
	}
	mlx_render(rt, rt->w.camera, rt->w);
	printf("scene rendered\n");
}
