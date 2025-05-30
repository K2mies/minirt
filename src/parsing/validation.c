/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:00:08 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/30 17:42:31 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/**
 * 
 * @brief Checks values of object data are in range
 * 
 * @param rt Main struct
 * @param object Specific object to be checked
 * 
 */
static void	check_object_values(t_minirt *rt, t_object *object)
{
	if (!is_in_range(object->color.r, 0, 1)
		|| !is_in_range(object->color.g, 0, 1)
		|| !is_in_range(object->color.b, 0, 1))
		rt_error(rt, "Object RGB error", 3);
	if (object->type != PLANE)
	{
		if (!is_in_range(object->vector.x, -1, 1)
			|| !is_in_range(object->vector.y, -1, 1)
			|| !is_in_range(object->vector.z, -1, 1))
			rt_error(rt, "Object vector error", 3);
	}
}
/**
 * 
 * @brief Validates data in the struct is within value ranges
 * 
 * @param rt Main struct
 * 
 */
static void	check_data_values(t_minirt *rt)
{
	int	i;

	i = -1;
	if (!is_in_range(rt->ambient.ratio, 0, 1))
		rt_error(rt, "Ambient ratio error", 3);
	if (!is_in_range(rt->ambient.color.r, 0, 1)
		|| !is_in_range(rt->ambient.color.g, 0, 1)
		|| !is_in_range(rt->ambient.color.b, 0, 1))
		rt_error(rt, "Ambient RGB error", 3);
	if (!is_in_range(rt->camera.vector.x, -1, 1)
		|| !is_in_range(rt->camera.vector.y, -1, 1)
		|| !is_in_range(rt->camera.vector.z, -1, 1))
		rt_error(rt, "Camera vector error", 3);
	if (!is_in_range(rt->camera.fov, 0, 180))
		rt_error(rt, "Camera FOV error", 3);
	if (!is_in_range(rt->light.brightness, 0, 1))
		rt_error(rt, "Light brightness error", 3);
	if (!is_in_range(rt->light.color.r, 0, 1) || !is_in_range(rt->light.color.g,
			0, 1) || !is_in_range(rt->light.color.b, 0, 1))
		rt_error(rt, "Light RGB error", 3);
	while (rt->object[++i])
		check_object_values(rt, rt->object[i]);
}
/**
 * 
 * @brief Reads the contents of the file to a 2D array.
 * 		If line contains only newline it is skipped.
 * 
 * @param rt Main struct
 * @param fd File descriptor for the open file
 * @param data 2D array to hold the data, passed as NULL
 * @param temp 2D array used to store the data before reallocating memory
 * 
 */
static char	**read_file_to_data(t_minirt *rt, int fd, char **data, char **temp)
{
	char	*line;
	size_t	new;
	size_t	old;

	new = 2;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			old = new - 1;
			data = ft_realloc(temp, (sizeof(char *)) * old, (sizeof(char *)
						* (new++)));
			data_null_check(rt, data, temp, line);
			temp = data;
			data[new - 3] = line;
		}
		else
			free(line);
		line = get_next_line(fd);
	}
	if (!data)
		return (NULL);
	data[new - 2] = NULL;
	return (data);
}
/**
 * 
 * @brief Splits the contents of each line of the file into separate elements
 * 
 * @param rt Main struct
 * @param data 2D array containing each line of the file
 * 
 */
static void	split_data(t_minirt *rt, char **data)
{
	int		i;

	i = -1;
	while (data[++i])
		;
	rt->full_data = rt_malloc(rt, sizeof(char **) * (i + 1));
	i = -1;
	while (data[++i])
	{
		rt->full_data[i] = ft_split(data[i], ' ');
		if (!rt->full_data[i])
		{
			free_big_array(&rt->full_data);
			rt_error(rt, "Allocation failure", 2);
		}
	}
	free_array(data);
	rt->full_data[i] = NULL;
	sort_data_types(rt, rt->full_data);
	check_data_values(rt);
}
/**
 * 
 * @brief Opens the specified file at the given path.
 * 		If no path is specified then default to scenes directory.
 * @param rt Main struct
 * @param argv Command line argument containing file
 * 
 */
void	open_file(t_minirt *rt, char **argv)
{
	int		fd;
	char	*path;
	char	**data;
	int		i;

	data = NULL;
	i = -1;
	if (valid_map_name(argv[1]))
		rt_error(rt, "Invalid file type", 1);
	if (ft_strchr(argv[1], '/'))
		path = ft_strdup(argv[1]);
	else
	{
		path = ft_strjoin("scenes/", argv[1]);
		if (!path)
			rt_error(rt, "ft_strjoin failure", 2);
	}
	fd = open_rt(rt, path);
	free(path);
	data = read_file_to_data(rt, fd, data, NULL);
	close(fd);
	if (!data)
		rt_error(rt, "No file data found", 3);
	split_data(rt, data);
	print_stored_data(rt);
	free_big_array(&rt->full_data);
}
