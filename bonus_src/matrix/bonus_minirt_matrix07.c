/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix07.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:23:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/07 16:37:06 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrix4(t_matrix4	mat)
{
	int	col;
	int	row;

	row = 0;
	while (row <= 3)
	{
		col = 0;
		while (col <= 3)
		{
			printf("%f	| ", mat.m[row][col]);
			if (col == 3)
				printf("\n");
			col++;
		}
		row++;
	}
	printf("\n\n");
}
