/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:17:45 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/30 12:24:54 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	valid_map_name(char *name)
{
	int	i;

	i = ft_strlen(name);
	if (i < 3)
		return (1);
	if (name[i - 1] == 't' && name[i - 2]
		== 'r' && name[i - 3] == '.')
		return (0);
	return (1);
}

int	open_rt(t_minirt *rt, char *path)
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

bool	is_in_range(t_float f, int min, int max)
{
	if (f > max || f < min)
		return (false);
	return (true);
}

bool	validate_rgb(char **rgb)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (false);
	return (true);
}

bool	file_entry_error(int a, int c, int l, int obj)
{
	if (a != 1 || c != 1 || l != 1 || obj == 0)
		ft_dprintf(STDERR_FILENO, "Error\n");
	if (a < 1)
		ft_dprintf(STDERR_FILENO, "Ambient data missing\n");
	else if (a > 1)
		ft_dprintf(STDERR_FILENO, "Ambient data max exceeded (1)\n");
	if (c < 1)
		ft_dprintf(STDERR_FILENO, "Camera data missing\n");
	else if (c > 1)
		ft_dprintf(STDERR_FILENO, "Camera data max exceeded (1)\n");
	if (l < 1)
		ft_dprintf(STDERR_FILENO, "Light data missing\n");
	else if (l > 1)
		ft_dprintf(STDERR_FILENO, "Light data max exceeded (1)\n");
	else if (obj == 0)
		ft_dprintf(STDERR_FILENO, "At least one object required\n");
	if (a != 1 || c != 1 || l != 1 || obj == 0)
		return (true);
	return (false);
}
