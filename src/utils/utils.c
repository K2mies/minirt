/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 15:35:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/21 13:13:01 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief Frees all memory in a 3D array and sets value to NULL
 * 
 * @param arr Pointer to 3D array
 * 
 */
void	free_big_array(char ****arr)
{
	int	i;
	int	j;

	i = -1;
	while ((*arr)[++i])
	{
		j = -1;
		while ((*arr)[i][++j])
			free((*arr)[i][j]);
		free((*arr)[i]);
	}
	free(*arr);
	*arr = NULL;
}
/**
 * 
 * @brief Converts decimal part of a string to float
 * 
 * @param str String to be converted
 * @param num Whole number part of the string converted
 * 
 */
t_float	ft_atof_dec(char *str, t_float num)
{
	t_float	dec;
	int		i;
	int		pos;

	i = 0;
	dec = 0.0f;
	pos = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		dec = dec * 10 + str[i] - 48;
		i++;
		pos++;
	}
	num += dec / pow(10, pos);
	return (num);
}
/**
 * 
 * @brief Convert string to float
 * 
 * @param str String to be converted
 * 
 */
t_float	ft_atof(char *str)
{
	t_float	num;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	num = 0.0f;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		num = ft_atof_dec(str + i, num);
	}
	num *= neg;
	return (num);
}

/**
 * 
 * @param str String to be checked
 * 
 * @return True if string represents a float
 */
bool	ft_isfloat(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] > '9' || str[i] < '0') && str[i] != '.')
			return (false);
		i++;
	}
	return (true);
}
/**
 * 
 * @brief Checks that the array contains only integers (accepts floats)
 * 
 * @param arr 2D array of data to validate
 * 
 */
bool	validate_array(char **arr)
{
	int	i;
	int	j;

	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
		{
			if (!ft_isdigit(arr[i][j]) && !(arr[i][j] == '.' || arr[i][j] ==
						'-' || arr[i][j] == '\n'))
				return (false);
		}
	}
	if (i != 3)
		return (false);
	return (true);
}
