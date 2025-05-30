/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:33:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/30 12:31:56 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_for_dups(t_minirt *rt, char ***full)
{
	int	i;
	int	amb;
	int	cam;
	int	lig;

	amb = 0;
	cam = 0;
	lig = 0;
	i = -1;
	while (full[++i])
	{
		if (!ft_strcmp(full[i][0], "A"))
			amb++;
		else if (!ft_strcmp(full[i][0], "C"))
			cam++;
		else if (!ft_strcmp(full[i][0], "L"))
			lig++;
		else if (!ft_strcmp(full[i][0], "sp") || !ft_strcmp(full[i][0], "cy") 
			|| !ft_strcmp(full[i][0], "pl"))
			rt->n_obj++;
	}
	if (file_entry_error(amb, cam, lig, rt->n_obj))
		rt_error(rt, NULL, 1);
	return (i);
}

static void	load_ambient(t_minirt *rt, char **data)
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

static void	load_light(t_minirt *rt, char **data)
{
	t_light	light;
	char	**origin;
	char	**rgb;

	if (!validate_size(data, 4))
		rt_error(rt, "Light data error", 3);
	origin = ft_split(data[1], ',');
	rgb = ft_split(data[3], ',');
	if (!origin || !rgb)
		object_error(rt, origin, NULL, rgb);
	if (!validate_array(origin) || !validate_array(rgb))
		object_error(rt, origin, NULL, rgb);
	light.origin = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	if (!ft_isfloat(data[2]))
		object_error(rt, origin, NULL, rgb);
	light.brightness = ft_atof(data[2]);
	if (!validate_rgb(rgb))
		object_error(rt, origin, NULL, rgb);
	light.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
			ft_atoi(rgb[2]));
	rt->light = light;
	object_free(origin, NULL, rgb);
}

static void	load_camera(t_minirt *rt, char **data)
{
	t_camera	camera;
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
	camera.origin = point(ft_atof(origin[0]), ft_atof(origin[1]),
			ft_atof(origin[2]));
	camera.vector = vector(ft_atof(vec[0]), ft_atof(vec[1]), ft_atof(vec[2]));
	if (!rt_isstrdigit(data[3]))
		object_error(rt, origin, vec, NULL);
	camera.fov = ft_atoi(data[3]);
	rt->camera = camera;
	object_free(origin, vec, NULL);
}

void	sort_data_types(t_minirt *rt, char ***full)
{
	int	i;
	int	index;

	i = -1;
	index = 0;
	rt->object = rt_malloc(rt, (sizeof(t_object *)
				* (check_for_dups(rt, full) - 2)));
	while (full[++i])
	{
		if (!ft_strcmp(full[i][0], "A"))
			load_ambient(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "C"))
			load_camera(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "L"))
			load_light(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "pl"))
			load_plane(rt, full[i], index++);
		else if (!ft_strcmp(full[i][0], "sp"))
			load_sphere(rt, full[i], index++);
		else if (!ft_strcmp(full[i][0], "cy"))
			load_cylinder(rt, full[i], index++);
		else
			rt_error(rt, "File contains invalid data type", 1);
	}
	rt->object[index] = NULL;
}
