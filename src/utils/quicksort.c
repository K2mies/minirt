/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:05:36 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/02 11:17:42 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

//static void	swap(int *a, int *b)
//{
//	int tmp;
//
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//static int	partition(int arr[], int low, int high)
//{
//	int pivote;
//	int	i;
//	int j;
//
//	pivote = arr[high];
//	i = (low - 1);
//	j = low;
//	while (j < high)
//	{
//		if (arr[j] <= pivote)
//		{
//			i++;
//			swap(&arr[i], &arr[j]);
//		}
//		j++;
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
//void	quicksort(int arr[], int low, int high)
//{
//	int pi;
//
//	if (low < high)
//	{
//		pi = partition(arr, low, high);
//		quicksort(arr, low, pi -1);
//		quicksort(arr, pi + 1, high);
//	}
//}

static void	swap(t_float *a, t_float *b)
{
	t_float tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int	partition(t_intersection arr[], int low, int high)
{
	t_float pivote;
	int	i;
	int j;

	pivote = arr[high].t;
	i = (low - 1);
	j = low;
	while (j < high)
	{
		if (arr[j].t <= pivote)
		{
			i++;
			swap(&arr[i].t, &arr[j].t);
		}
		j++;
	}
	swap(&arr[i + 1].t, &arr[high].t);
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
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort(arr, low, pi -1);
		quicksort(arr, pi + 1, high);
	}
}
