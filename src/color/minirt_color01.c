/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:59:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/16 15:37:22 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to convert 0-1 rgba values to
 * a single rgba stored as an uint32_t
 *
 * @param r		red channel 0-1 value
 * @param g		green channel 0-1 value
 * @param b		blue channel 0-1 value
 * @param a		alpha channel 0-1 value
 *
 * @return		hex value for rgba stored as uint32_t
 */
uint32_t	convert_rgba_to_hex(float r, float g, float b, float a)
{
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;
	uint32_t	alpha;

	red = (uint32_t)roundf(fminf(fmaxf(r * 255.0f, 0.0f), 255.0f));
	green =(uint32_t)roundf(fminf(fmaxf(g * 255.0f, 0.0f), 255.0f));
	blue =(uint32_t)roundf(fminf(fmaxf(b * 255.0f, 0.0f), 255.0f));
	alpha =(uint32_t)roundf(fminf(fmaxf(a * 255.0f, 0.0f), 255.0f));

	return (uint32_t)((red << 24) | (green << 16) | (blue << 8) | alpha);
}

/**
 * Function to convert a hex value into single
 * channels stored as uint8_t 
 * (so they can be combined into uint32_t)
 *
 * @param col	point to the color struct
 */
void	convert_hex_into_channels(t_color *col)
{
	col->ch[R] = (col->rgba >> 24) & col->rgba;
	col->ch[G] = (col->rgba >> 16) & col->rgba;
	col->ch[B] = (col->rgba >> 8) & col->rgba;
	col->ch[A] = (col->rgba >> 0) & col->rgba;
}

//convert chanels to hex
//convert channels to rgb
//convert rgb to channels
//convert hex to rgb
