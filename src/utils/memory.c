/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:25:11 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/21 14:16:27 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief Frees all data in 3 2D arrays
 * 
 * @param arr1 First array to free
 * @param arr2 Second array to free
 * @param arr3 Third array to free
 * 
 */
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
/**
 * 
 * @brief Helper function to allocate memory, sets to 0, and NULL check
 * 
 * @param rt Main struct
 * @param size Size of the memory to be allocated
 * 
 */
void	*rt_malloc(t_minirt *rt, size_t size)
{
	void	*mem;

	mem = ft_calloc(1, size);
	if (!mem)
		rt_error(rt, "Allocation failure", 2);
	return (mem);
}
/**
 * 
 * @brief Function to clean up all memory in main struct
 * 
 * @param rt Main struct
 * 
 */
void	cleanup_rt(t_minirt *rt)
{
	if (rt->objs)
		free(rt->objs);
	if (rt->ts)
		free(rt->ts);
	if (rt->full_data)
		free_big_array(&rt->full_data);
}
