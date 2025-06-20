/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:26:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/06/17 13:46:57 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
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

/**
 * 
 * @brief Load plane object data to struct
 * 
 * @param rt Main struct
 * @param data 2D array containing object data
 * @param index Index of the object array to be assigned
 * 
 */
void	load_plane(t_minirt *rt, char **data, int index)
{
	t_object	pl;
	char		**origin;
	char		**vec;
	char		**rgb;

	if (!validate_size(data, 4))
		rt_error(rt, "Plane data error", 3);
	origin = ft_split(data[1], ',');
	vec = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	if (!origin || !vec || !rgb)
		object_error(rt, origin, vec, rgb);
	if (!validate_array(origin) || !validate_array(vec) || !validate_array(rgb))
		object_error(rt, origin, vec, rgb);
	if (!validate_rgb(rgb))
		object_error(rt, origin, vec, rgb);
	pl = plane(point(ft_atof(origin[0]), ft_atof(origin[1]),
				ft_atof(origin[2])), vector(ft_atof(vec[0]), ft_atof(vec[1]),
				ft_atof(vec[2])), color_from_channels(ft_atoi(rgb[0]),
				ft_atoi(rgb[1]), ft_atoi(rgb[2])));
	rt->objs[index] = pl;
	object_free(origin, vec, rgb);
}

/**
 * 
 * @brief Load sphere object data to struct
 * 
 * @param rt Main struct
 * @param data 2D array containing object data
 * @param index Index of the object array to be assigned
 * 
 */
void	load_sphere(t_minirt *rt, char **data, int index)
{
	t_object	sp;
	char		**origin;
	char		**rgb;
	t_tuple		loc;
	t_float		diameter;

	if (!validate_size(data, 4))
		rt_error(rt, "Sphere data error", 3);
	origin = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	if (!origin || !rgb)
		object_error(rt, origin, NULL, rgb);
	if (!validate_array(origin) || !validate_array(rgb))
		object_error(rt, origin, NULL, rgb);
	loc = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	if (!ft_isfloat(data[2]))
		object_error(rt, origin, NULL, rgb);
	diameter = ft_atof(data[2]);
	if (!validate_rgb(rgb))
		object_error(rt, origin, NULL, rgb);
	sp = sphere(loc, diameter, color_from_channels(ft_atoi(rgb[0]),
				ft_atoi(rgb[1]), ft_atoi(rgb[2])));
	rt->objs[index] = sp;
	object_free(origin, rgb, NULL);
}

/**
 * 
 * @brief Load cylinder object data to struct
 * 
 * @param rt Main struct
 * @param data 2D array containing object data
 * @param index Index of the object array to be assigned
 * 
 */
void	load_cylinder(t_minirt *rt, char **data, int index)
{
	t_object	cyl;
	char		**origin;
	char		**vec;
	char		**rgb;

	if (!validate_size(data, 6))
		rt_error(rt, "Cylinder data error", 3);
	origin = ft_split(data[1], ',');
	vec = ft_split(data[2], ',');
	rgb = ft_split(data[5], ',');
	if (!origin || !vec || !rgb || !validate_array(origin)
		|| !validate_array(vec) || !validate_array(rgb) || !validate_rgb(rgb))
		object_error(rt, origin, vec, rgb);
	if (!ft_isfloat(data[3]) || !ft_isfloat(data[4]))
		object_error(rt, origin, vec, rgb);
	cyl = (t_object){.type = CYLINDER, .height = ft_atof(data[4]),
		.diameter = ft_atof(data[3])};
	cyl.origin = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	cyl.vector = vector(ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]));
	cyl.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	rt->objs[index] = cyl;
	object_free(origin, vec, rgb);
}
