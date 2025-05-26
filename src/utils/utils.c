/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:35:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 15:36:49 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	free_big_array(char ***arr, int i)
{
	int	j;

	while (i--)
	{
		j = -1;
		while (arr[i][++j])
			free(arr[i][j]);
		free(arr[i]);	
	}
	free(arr);
}
