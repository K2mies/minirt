/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:05:36 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:34:17 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	swap(t_intersection *a, t_intersection *b)
{
	t_intersection	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_intersection arr[], int low, int high)
{
	t_float	pivote;
	int		i;
	int		j;

	pivote = arr[high].t;
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j].t <= pivote)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/**
 * @brief	quicksort function to sort intersection arrays
 * sorts an array of intersections 
 *
 * @param arr	array of t_intersection to be sorted
 * @param low	lowest value of the array
 * @param high	highest value of the array
 */
void	quicksort(t_intersection arr[], int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi -1);
		quicksort(arr, pi + 1, high);
	}
}
