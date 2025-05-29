/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:20:32 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/29 15:05:07 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
