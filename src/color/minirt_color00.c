/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:48:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:09:19 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * Function to set existing color struct
 * based on 0-1 rgba values
 *
 * @param a		pointer to the color struct you want changed
 * @param r		red channel 0-1 value
 * @param g		green channel 0-1 value
 * @param b		blue channel 0-1 value
 */
void	set_color(t_color *a, t_float r, t_float g, t_float b)
{
	a->r = r;
	a->g = g;
	a->b = b;
	a->a = 1.0;
	convert_rgba_to_hex(a);
}

/**
 * Function to create a color struct
 * based on 0-1 rgba values
 *
 * @param r		red channel 0-1 value
 * @param g		green channel 0-1 value
 * @param b		blue channel 0-1 value
 * @param a		alpha channel 0-1 value
 *
 * @return		color type struct
 */
t_color	color(t_float r, t_float g, t_float b)
{
	t_color	col;

	col.r = r;
	col.g = g;
	col.b = b;
	col.a = 1.0;
	convert_rgba_to_hex(&col);
	return (col);
}

t_color	color_from_channels(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	col;

	col.ch[R] = r;
	col.ch[G] = g;
	col.ch[B] = b;
	col.ch[A] = 255;
	convert_channels_to_hex(&col);
	convert_channels_to_rgba(&col);
	return (col);
}
