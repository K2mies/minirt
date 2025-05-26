/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:00:08 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 15:14:21 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

static int	valid_map_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i < 3)
		return (1);
	if (name[i - 1] == 't' && name[i - 2] == \
		'r' && name[i - 3] == '.')
		return (0);
	return (1);
}

static int open_rt(t_minirt *rt, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		if (errno == ENOENT)
			rt_error(rt, "Scene not found", 1);
		else
			rt_error(rt, "Problem opening file", 3);
	}
	return (fd);
}

static char **read_file_to_data(t_minirt *rt, int fd, char **data)
{
	char	**temp;
	char	*line;
	size_t	new;
	size_t old;

	new = 2;
	temp = NULL;
	line = get_next_line(fd);
	if (!line)
		rt_error(rt, "Failed to read file", 2);
	while (line)
	{
		old = new - 1;
		data = ft_realloc(temp, (sizeof(char *)) * old, (sizeof(char *) * (new++)));
		if (!data)
		{
			free_array(&temp);
			rt_error(rt, "Allocation failure", 2);
		}
		temp = data;
		data[new - 3] = line;
		line = get_next_line(fd);
	}
	data[new - 2] = NULL;
	return (data);
}

static void	split_data(t_minirt *rt, char **data)
{
}

void	open_file(t_minirt *rt, char **argv)
{
	int	fd;
	char	*path;
	char	**data;
	
	data = NULL;
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
	data = read_file_to_data(rt, fd, data);
	int i = -1;
	while (data[++i])
		printf("Line: %d | Data: %s\n", i + 1, data[i]);
}
