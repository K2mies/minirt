/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:26:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/27 12:47:29 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	load_plane(t_minirt *rt, char **data)
{
	t_object	plane;
	char		**coord;
	char		**vec;
	char		**rgb;

	if (!validate_size(data, 4))
		rt_error(rt, "Plane data error", 3);
	plane.type = OBJ_PLANE;
	coord = ft_split(data[1], ',');
	if (!coord)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(coord))
		rt_error(rt, "Plane coordinate error", 3);
	plane.coord = point(ft_atof(coord[0]), ft_atof(coord[1]), ft_atof(coord[2]));
	vec = ft_split(data[2], ',');
	if (!vec)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(vec))
		rt_error(rt, "Plane vector error", 3);
	plane.vector = vector(ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]));
	rgb = ft_split(data[3], ',');
	if (!rgb)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(rgb))
		rt_error(rt, "RGB data error", 3);
	plane.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]));
	return (plane);
}

t_object	load_sphere(t_minirt *rt, char **data)
{
	t_object	sphere;
	
}

t_object	load_cylinder(t_minirt *rt, char **data)
{
	t_object	cylinder;
}

void	load_object(t_minirt *rt, char **data)
{
	static t_object *objects;
	t_object		obj;
	static int		new;
	int				old;

	if (new == 0)
		new = 2;
	old = new - 1;
	objects = ft_realloc(objects, (sizeof(t_object) * old), (sizeof(t_object)
		* new++));
	if (!objects)
		rt_error(rt, "Allocation failure", 2);
	if (!ft_strcmp(data[0], "pl"))
		obj = load_plane(rt, data);
	else if (!ft_strcmp(data[0], "sp"))
		obj = load_sphere(rt, data);
	else if (!ft_strcmp(data[0], "cy"))
		obj = load_cylinder(rt, data);
	
}