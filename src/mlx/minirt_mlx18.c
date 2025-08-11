/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx18.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:05:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:21:52 by mpierce          ###   ########.fr       */
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
 * @brief	helper functio to set material with pattern
 * changes the pattern transforms 
 * @param	t_color	col[2]	two color tuples for pattern
 * @param	t_object *obj	pointer to the obj to operate on
 * @param	bool			boolean for if cube is present or not
 */
static void	set_material(t_color col[2], t_object *obj, bool *cube_present)
{
	t_pattern	*pat;

	*cube_present = true;
	obj->material.has_pattern = true;
	obj->material.pattern = pattern(col[a], col[b], CHECKER);
	pat = &obj->material.pattern;
	set_pattern_transforms(pat);
	apply_pattern_transforms(pat);
	printf("pattern set to checkered\n");
}

/**
 * @brief	hand key C key press case
 * changes all CUBES in scene to a checkered pattern
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_c_press(t_minirt *rt)
{
	int		i;
	t_color	col[2];
	bool	cube_present;

	cube_present = false;
	col[a] = color(0, 0, 0);
	col[b] = color(1, 1, 1);
	i = -1;
	while (++i < rt->w.n_objs)
	{
		if (rt->w.objs[i].type == CUBE)
			set_material(col, &rt->w.objs[i], &cube_present);
	}
	if (cube_present == false)
		printf("no cubes found present in scene\n");
	else
		mlx_render(rt, rt->w.camera, rt->w);
}
