/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix007.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:23:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/01 12:31:55 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrix4(t_matrix4	mat)
{
	int	col;
	int	row;

	row = 0;
	while (row <= 4)
	{
		col = 0;
		while (col <= 4)
		{
			printf("%f	| ", mat.m[row][col]);
			if (col == 4)
				printf("\n");
			col++;
		}
		row++;
	}
	printf("\n\n");
}
