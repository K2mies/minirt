/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:26:37 by mpierce           #+#    #+#             */
/*   Updated: 2025/08/11 14:03:47 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	t_p_cy		temp;
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
	temp = (t_p_cy){.diameter = ft_atof(data[3]), .height = ft_atof(data[4])};
	temp.origin = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	temp.direction = vector(ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]));
	temp.col = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	cyl = cylinder(temp);
	rt->objs[index] = cyl;
	object_free(origin, vec, rgb);
}

void	load_cube(t_minirt *rt, char **data, int index)
{
	t_object	cb;
	char		**origin;
	char		**vec;
	char		**rgb;

	if (!validate_size(data, 5))
		rt_error(rt, "Cube data error", 3);
	origin = ft_split(data[1], ',');
	vec = ft_split(data[2], ',');
	rgb = ft_split(data[3], ',');
	if (!origin || !vec || !rgb)
		object_error(rt, origin, vec, rgb);
	if (!validate_array(origin) || !validate_array(vec) || !validate_array(rgb))
		object_error(rt, origin, vec, rgb);
	if (!ft_isfloat(data[4]))
		object_error(rt, origin, vec, rgb);
	cb = cube(point(ft_atof(origin[0]), ft_atof(origin[1]),
				ft_atof(origin[2])), vector(ft_atof(vec[0]), ft_atof(vec[1]),
				ft_atof(vec[2])), color_from_channels(ft_atoi(rgb[0]),
				ft_atoi(rgb[1]), ft_atoi(rgb[2])), ft_atof(data[4]));
	rt->objs[index] = cb;
	object_free(origin, vec, rgb);
}
