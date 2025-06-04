/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color03.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:55:34 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/18 16:08:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to add Three colors together and return
 * a new color type as a result
 *
 * @param tupa	first color for addition
 * @param tupb	second color for addition
 * @param tupc	third color for addition
 *
 * @return		new color with the added values
 */
t_color	add_three_colors(t_color cola, t_color colb, t_color colc)
{
	t_color	res;

	res.r = cola.r + colb.r + colc.r;
	res.g = cola.g + colb.g + colc.g;
	res.b = cola.b + colb.b + colc.b;
	res.a = 1.0;
	convert_rgba_to_hex(&res);
	return (res);
}

/**
 * Function to add two colors together and return
 * a new color type as a result
 *
 * @param tupa	first color for addition
 * @param tupb	fsecond color for addition
 *
 * @return		new color with the added values
 */
t_color	add_colors(t_color cola, t_color colb)
{
	t_color	res;

	res.r = cola.r + colb.r;
	res.g = cola.g + colb.g;
	res.b = cola.b + colb.b;
	res.a = 1.0;
	convert_rgba_to_hex(&res);
	return (res);
}

/**
 * Function to subtract two colors from each other and return
 * a new color type as a result
 *
 * @param tupa	first color for subtraction
 * @param tupa	fsecond color for subtraction
 *
 * @return		new color with the subtracted values
 */
t_color	sub_colors(t_color cola, t_color colb)
{
	t_color	res;

	res.r = cola.r - colb.r;
	res.g = cola.g - colb.g;
	res.b = cola.b - colb.b;
	res.a = 1.0;
	convert_rgba_to_hex(&res);
	return (res);
}
