/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_color00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:48:51 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/15 11:56:19 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

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
t_color	*color(float r, float g, float b)
{
	t_color	*col;

	col = malloc(sizeof(t_color));
	col->r = r;
	col->g = g;
	col->b = b;
	col->a = 1.0;
	col->rgba = convert_rgba_to_hex(r, g, b, col->a);
	convert_hex_into_channels(col);

	return (col);
}

