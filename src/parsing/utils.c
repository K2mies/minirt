/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:20:32 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/21 13:10:34 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief Checks the data array contains the corrent number of elements
 * 
 * @param data 2D array of the data to be checked
 * @param size Number of elements data should contain
 * 
 */
bool	validate_size(char **data, int size)
{
	int	i;

	i = -1;
	while (data[++i])
		;
	if (i != size)
		return (false);
	return (true);
}

void	data_null_check(t_minirt *rt, char **data, char **tmp, char *line)
{
	if (!data)
	{
		free_array(tmp);
		free(line);
		rt_error(rt, "Allocation failure", 2);
	}
}

bool	rt_isstrdigit(char *str)
{
	int		len;
	char	*temp;
	int		i;
	bool	res;

	i = -1;
	len = ft_strlen(str);
	temp = ft_strdup(str);
	if (!temp)
		return (false);
	if (temp[len - 1] == '\n')
		temp[len - 1] = 0;
	res = ft_isstrdigit(temp);
	free(temp);
	return (res);
}

void	light_validation(t_minirt *rt)
{
	int	i;

	i = -1;
	while (++i < rt->n_light)
	{
		if (!is_in_range(rt->light[i].brightness, 0, 1))
			rt_error(rt, "Light brightness error", 3);
		if (!is_in_range(rt->light[i].color.r, 0, 1) || !is_in_range(rt->light[i].color.g,
			0, 1) || !is_in_range(rt->light[i].color.b, 0, 1))
			rt_error(rt, "Light RGB error", 3);
	}
}
