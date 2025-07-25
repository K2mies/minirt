/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:23:34 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/25 15:06:28 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void cylinder_check(t_minirt *rt, char **origin, char **vec, char **rgb)
{
	if (!origin || !vec || !rgb || !validate_array(origin)
		|| !validate_array(vec) || !validate_array(rgb) || !validate_rgb(rgb))
		object_error(rt, origin, vec, rgb);
}

void load_objects_to_data(t_minirt *rt, char ***full, int i)
{
	if (!ft_strcmp(full[i][0], "A"))
		load_ambient(rt, full[i]);
	else if (!ft_strcmp(full[i][0], "C"))
		load_camera(rt, full[i]);
	else if (!ft_strcmp(full[i][0], "L"))
		load_light(rt, full[i]);
	else if (!ft_strcmp(full[i][0], "pl"))
		load_plane(rt, full[i], rt->parsing_index++);
	else if (!ft_strcmp(full[i][0], "sp"))
		load_sphere(rt, full[i], rt->parsing_index++);
	else if (!ft_strcmp(full[i][0], "cy"))
		load_cylinder(rt, full[i], rt->parsing_index++);
	else if (!ft_strcmp(full[i][0], "cb"))
		load_cube(rt, full[i], rt->parsing_index++);
	// else if (!ft_strcmp(full[i][0], "con")) // object.c 143-166
	// 	load_cone(rt, full[i], index++);
	else
		rt_error(rt, "File contains invalid data type", 1);
}

/**
 * 
 * @brief Helper function to free arrays and exit in event of error
 * 
 * @param rt Main struct
 * @param a1 First array to free
 * @param a2 Second array to free
 * @param a3 Third array to free
 * 
 */
void	object_error(t_minirt *rt, char **a1, char **a2, char **a3)
{
	object_free(a1, a2, a3);
	rt_error(rt, "Data error", 3);
}
