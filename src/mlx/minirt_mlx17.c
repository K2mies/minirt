/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx17.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 14:32:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/08 15:36:47 by rhvidste         ###   ########.fr       */
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

static void	set_material(t_color col[2], t_object *obj, bool *planes_present)
{
	t_pattern	*pat;
	*planes_present = true;
	obj->material.has_pattern = true;
	obj->material.pattern = pattern(col[a], col[b], CHECKER);
	pat = &obj->material.pattern;
	set_pattern_transforms(pat);
	apply_pattern_transforms(pat);
	printf("pattern set to checkered\n");
}

/**
 * @brief	hand key T key press case
 * changes all planes in scene to a checkered pattern
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_t_press(t_minirt *rt)
{
	int			i;
	t_color		col[2];
	bool		planes_present;

	planes_present = false;
	col[a] = color(0, 0, 0);
	col[b] = color(1, 1, 1);
	i = -1;
	while (++i < rt->w.n_objs)
	{
		if (rt->w.objs[i].type == PLANE)
			set_material(col, &rt->w.objs[i], &planes_present);
	}
	if (planes_present == false)
		printf("no planes found present in scene\n");
	else
		mlx_render(rt, rt->w.camera, rt->w);
}
