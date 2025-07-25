/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:33:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/25 15:06:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief Checks the occurances of each data type
 * 
 * @param rt Main struct
 * @param full 3D array of file contents
 * 
 */
static void	check_for_dups(t_minirt *rt, char ***full)
{
	int	i;
	int	amb;
	int	cam;

	amb = 0;
	cam = 0;
	i = -1;
	while (full[++i])
	{
		if (!ft_strcmp(full[i][0], "A"))
			amb++;
		else if (!ft_strcmp(full[i][0], "C"))
			cam++;
		else if (!ft_strcmp(full[i][0], "L"))
			rt->n_light++;
		else if (!ft_strcmp(full[i][0], "sp") || !ft_strcmp(full[i][0], "cy")
			|| !ft_strcmp(full[i][0], "pl") || !ft_strcmp(full[i][0], "cb"))
			rt->n_objs++;
	}
	if (file_entry_error(amb, cam, rt->n_light, rt->n_objs))
		rt_error(rt, NULL, 1);
	rt->objs = rt_malloc(rt, (sizeof(t_object) * rt->n_objs));
}

/**
 * 
 * @brief Load Ambient data into struct
 * 
 * @param rt Main struct
 * @param data 2D array of Ambient data
 * 
 */
void	load_ambient(t_minirt *rt, char **data)
{
	t_ambient	ambient;
	char		**rgb;

	if (!validate_size(data, 3))
		rt_error(rt, "Ambient data error", 3);
	if (!ft_isfloat(data[1]))
		rt_error(rt, "Ambient data error", 3);
	ambient.ratio = ft_atof(data[1]);
	rgb = ft_split(data[2], ',');
	if (!rgb)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_array(rgb))
		object_error(rt, NULL, NULL, rgb);
	if (!validate_rgb(rgb))
		object_error(rt, NULL, NULL, rgb);
	ambient.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	rt->ambient = ambient;
	object_free(NULL, NULL, rgb);
}

/**
 * 
 * @brief Load Light data into struct
 * 
 * @param rt Main struct
 * @param data 2D array of Light data
 * 
 */
void	load_light(t_minirt *rt, char **data)
{
	char	**origin;
	char	**rgb;
	t_tuple	src;
	t_color	color;

	if (!validate_size(data, 4))
		rt_error(rt, "Light data error", 3);
	origin = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	if (!origin || !rgb)
		object_error(rt, origin, NULL, rgb);
	if (!validate_array(origin) || !validate_array(rgb))
		object_error(rt, origin, NULL, rgb);
	src = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	if (!ft_isfloat(data[2]))
		object_error(rt, origin, NULL, rgb);
	if (!validate_rgb(rgb))
		object_error(rt, origin, NULL, rgb);
	color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	rt->light = point_light(src, ft_atof(data[2]), color);
	object_free(origin, NULL, rgb);
}

/**
 * 
 * @brief Load Camera data into struct
 * 
 * @param rt Main struct
 * @param data 2D array of Camera data
 * 
 */
void	load_camera(t_minirt *rt, char **data)
{
	char		**origin;
	char		**vec;

	if (!validate_size(data, 4))
		rt_error(rt, "Camera data error", 3);
	origin = ft_split(data[1], ',');
	vec = ft_split(data[2], ',');
	if (!origin || !vec)
		object_error(rt, origin, vec, NULL);
	if (!validate_array(origin) || !validate_array(vec))
		object_error(rt, origin, vec, NULL);
	if (!rt_isstrdigit(data[3]))
		object_error(rt, origin, vec, NULL);
	rt->camera = camera(point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2])), vector(ft_atof(vec[0]), ft_atof(vec[1]),
			ft_atof(vec[2])), deg_to_rad(ft_atof(data[3])));
	object_free(origin, vec, NULL);
}

/**
 * 
 * @brief Reads the array and assigns file contents to data structs
 * 
 * @param rt Main struct
 * @param full 3D array containing all file data
 * 
 */
void	sort_data_types(t_minirt *rt, char ***full)
{
	int	i;

	i = -1;
	check_for_dups(rt, full);
	while (full[++i])
		load_objects_to_data(rt, full, i);
}
