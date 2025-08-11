/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx13.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:21:25 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:24:09 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to set pattern transforms
 * changes the pattern transforms 
 * @param	t_pattern	*pat pattern to change transforms of
 */
static void	set_pattern_transforms(t_pattern *pat)
{
	pat->transforms[scale][xyz] = scaling(0.5, 0.5, 0.5);
}

/**
 * @brief	helper function to set material based on type
 * changes the selected objects material to CHECKER if flag is false
 * or if pattern is set to another type
 * @param	t_color		col[2] col[a] and col[b] to set gradient from
 * @param	t_object	*obj pointer to object to opperate on
 */
static void	set_material(t_color col[2], t_object *obj)
{
	t_pattern	*pat;

	if (obj->material.has_pattern == false
		|| (obj->material.has_pattern == true
			&& obj->material.pattern.type != CHECKER))
	{
		obj->material.has_pattern = true;
		obj->material.pattern = pattern(col[a], col[b], CHECKER);
		pat = &obj->material.pattern;
		set_pattern_transforms(pat);
		apply_pattern_transforms(pat);
		printf("pattern set to checkered\n");
	}
	else
	{
		obj->material.has_pattern = false;
		printf("pattern set to false\n");
	}
}

/**
 * @brief	hand key P key press case
 * changes selected object to patterned checker
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_p_press(t_minirt *rt)
{
	t_object	*obj;
	t_color		col[2];

	col[a] = color(0, 0, 0);
	col[b] = color(1, 1, 1);
	if (rt->is_active_object)
	{
		obj = &rt->w.objs[rt->active_object.index];
		set_material(col, obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}
}
