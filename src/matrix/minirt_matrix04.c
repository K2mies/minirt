/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix04.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:56:55 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/25 18:00:28 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to return a 3x3 Submatrix from a 4x4 Matrix
 * by iliminating a specified row and a specified column
 *
 * @param m		a pointer to a 4x4 matrix to calculate the submatrix from
 * @param row	index of the row to be eliminated max = 3
 * @param col	index of the column to be eliminated max = 3
 *
 * @return		the resulting 3x3 Submatrix
 */
t_matrix3   submatrix4(t_matrix4 m, int row, int col)
{
    int         new_row;
    int         new_col;
    int         r;
    int         c;
    t_matrix3   res;

    new_row = 0;
    r = -1;

    while (++r < 4)
    {
        if (r == row)
            continue ;
        new_col = 0;
        c = -1;
        while (++c < 4)
        {
            if (c == col)
                continue;
            res.m[new_row][new_col] = m.m[r][c];
            new_col++;
        }
        new_row++;
    }
    return (res);
}

/**
 * Function to return a 2x2 Submatrix from a 3x3 Matrix
 * by iliminating a specified row and a specified column
 *
 * @param m		a pointer to a 3x3 Matrix to calculate the submatrix from
 * @param row	index of the row to be eliminated max = 2
 * @param col	index of the column to be eliminated max = 2
 *
 * @return		the resulting 2x2 Submatrix
 */
t_matrix2   submatrix3(t_matrix3 m, int row, int col)
{
    int         new_row;
    int         new_col;
    int         r;
    int         c;
    t_matrix2   res;

    new_row = 0;
    r = -1;

    while (++r < 3)
    {
        if (r == row)
            continue ;
        new_col = 0;
        c = -1;
        while (++c < 3)
        {
            if (c == col)
                continue;
            res.m[new_row][new_col] = m.m[r][c];
            new_col++;
        }
        new_row++;
    }
    return (res);
    
}
