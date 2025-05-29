/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:25:11 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/29 14:27:19 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	object_free(char **arr1, char **arr2, char **arr3)
{
	int	i;

	i = -1;
	if (arr1)
	{
		while (arr1[++i])
			free(arr1[i]);
		free(arr1);
	}
	i = -1;
	if (arr2)
	{
		while (arr2[++i])
			free(arr2[i]);
		free(arr2);
	}
	i = -1;
	if (arr3)
	{
		while (arr3[++i])
			free(arr3[i]);
		free(arr3);
	}
}

void	*rt_malloc(t_minirt *rt, size_t size)
{
	void	*mem;

	mem = ft_calloc(1, size);
	if (!mem)
		rt_error(rt, "Allocation failure", 2);
	return (mem);
}

void	cleanup_rt(t_minirt *rt)
{
	int	i;

	i = -1;
	if (rt->object)
	{
		while (rt->object[++i])
			free(rt->object[i]);
		free(rt->object);
	}
	if (rt->full_data)
		free_big_array(rt->full_data);
}
