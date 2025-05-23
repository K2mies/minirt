/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/23 14:11:58 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_matrix	matrix(void)
{
	t_matrix	mat;

//	mat = malloc(sizeof(t_matrix *));
	mat = (t_matrix)
	{{
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{0, 0, 0, 0}
	}};
	return (mat);
}

t_matrix	id_matrix(void)
{
	t_matrix	mat;

//	mat = malloc(sizeof(t_matrix));
	mat = (t_matrix)
	{{
	{1, 0, 0, 0},
	{0, 1, 0, 0},
	{0, 0, 1, 0},
	{0, 0, 0, 1}
	}};
	return (mat);
}
