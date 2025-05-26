/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:33:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 18:03:36 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_for_dups(t_minirt *rt, char ***full)
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
	}
	if (amb > 1)
		rt_error(rt, "Ambient light max exceeded (1)", 1);
	if (cam > 1)
		rt_error(rt, "Camera max exceeded (1)", 1);
	if (lig > 1)
		rt_error(rt, "Light source max exceeded (1)", 1);
}

static void	load_ambient(t_minirt *rt, char **data)
{
	t_ambient	ambient;
	char		**rgb;

	ambient.ratio = ft_atof(data[1]);
	rgb = ft_split(data[2], ',');
	if (!rgb)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(rgb))
		rt_error(rt, "Ambient RGB value error", 3);
	ambient.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	rt->ambient = ambient;
}

static void	load_light(t_minirt *rt, char **data)
{
	t_light	light;
	char	**coord;
	char	**rgb;

	coord = ft_split(data[1], ',');
	if (!coord)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(coord))
		rt_error(rt, "Light coordinate error", 3);
	light.coord = //make this a tuple
	if (!ft_isfloat(data[2]))
		rt_error(rt, "Light Ratio value error", 3);
	light.brightness = ft_atof(data[2]);
	rgb = ft_split(data[3], ',');
	if (!rgb)
		rt_error(rt, "Allocation failure", 2);
	if (!validate_integer(rgb))
		rt_error(rt, "Light RGB value error", 3);
	light.color = color_from_channels(ft_atoi(rgb[0]), ft_atoi(rgb[1]),
		ft_atoi(rgb[2]));
	rt->light = light;
}

void	sort_data_types(t_minirt *rt, char ***full)
{
	int	i;
	
	i = -1;
	check_for_dups(rt, full);
	while (full[++i])
	{
		if (!ft_strcmp(full[i][0], "A"))
			load_ambient(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "C"))
			load_camera(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "L"))
			load_light(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "pl"))
			load_plane(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "sp"))
			load_sphere(rt, full[i]);
		else if (!ft_strcmp(full[i][0], "cy"))
			load_cylinder(rt, full[i]);
		else
			rt_error(rt, "File contains invalid data type", 1);
	}
}
