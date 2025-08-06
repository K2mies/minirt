/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:59:10 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/04 12:01:29 by rhvidste         ###   ########.fr       */
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
		pat->transforms[translate][xyz] = translation(5, 0, 0);
		pat->transforms[scale][xyz] = scaling(2, 2, 2);
}

/**
 * @brief	helper function to set material based on type
 * changes the selected objects material to GRADIENT if flag is false
 * or if pattern is set to another type
 * @param	t_color		col[2] col[a] and col[b] to set gradient from
 * @param	t_object	*obj pointer to object to opperate on
 */
static void	set_material(t_color col[2], t_object *obj)
{
	t_pattern	*pat;

	if (obj->material.has_pattern == false
		|| (obj->material.has_pattern == true
		&& obj->material.pattern.type != GRADIENT))
	{
		pat = &obj->material.pattern;
		obj->material.has_pattern = true;
		obj->material.pattern = pattern(col[a], col[b], GRADIENT);
		set_pattern_transforms(pat);
		apply_pattern_transforms(pat);
		printf("pattern set to gradient\n");
	}
	else
	{
		obj->material.has_pattern = false;
		printf("pattern set to false\n ");
	}
}

/**
 * @brief	hand key G key press case
 * changes selected object to GRADIENT pattern
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_g_press(t_minirt *rt)
{
	t_object	*obj;
	t_color		col[2];

	col[a] = color(0.71, 0, 0.29);
	col[b] = color(1, 1, 1);

	if (rt->is_active_object)
	{
		obj = &rt->objs[rt->active_object.index];
		set_material(col, obj);
		mlx_render(rt, rt->w.camera, rt->w);
		printf("scene rendered\n");
	}
}
