/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 18:01:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/18 00:35:50 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to convert channels into 
 * a single hex uint32_t value
 * stored in col->rgba
 *
 * @param col	point to the color struct
 */
void	convert_channels_to_hex(t_color *col)
{
	col->rgba = (uint32_t)((col->ch[R] << 24)
			| (col->ch[G] << 16)
			| (col->ch[B] << 8)
			| (col->ch[A] << 0));
}

/**
 * Function to convert a hex value into single
 * channels stored as uint8_t 
 * (so they can be combined into uint32_t)
 *
 * @param col	point to the color struct
 */
void	convert_hex_to_channels(t_color *col)
{
	col->ch[R] = (col->rgba >> 24) & col->rgba;
	col->ch[G] = (col->rgba >> 16) & col->rgba;
	col->ch[B] = (col->rgba >> 8) & col->rgba;
	col->ch[A] = (col->rgba >> 0) & col->rgba;
}

/**
 * Function to convert channels into
 * rgba 0-1 values stored in the
 * color struct as r, g, b, a
 * (bare in mind this will clamp the rgba
 * values because they are clamped
 * when converted into channels).
 *
 * @param col	point to the color struct
 */
void	convert_channels_to_rgba(t_color *col)
{
	col->r = col->ch[R] / 255.0f;
	col->g = col->ch[G] / 255.0f;
	col->b = col->ch[B] / 255.0f;
	col->a = col->ch[A] / 255.0f;
}

/**
 * Function to convert rgba 0-1 values into
 * 255 channels stored as uint8_t
 * (can also be read as hexadecimal)
 *
 * @param col	point to the color struct
 */
void	convert_rgba_to_channels(t_color *col)
{
	col->ch[R] = (uint8_t)roundf(fminf(fmaxf(col->r * 255.0f, 0.0f), 255.0f));
	col->ch[G] = (uint8_t)roundf(fminf(fmaxf(col->g * 255.0f, 0.0f), 255.0f));
	col->ch[B] = (uint8_t)roundf(fminf(fmaxf(col->b * 255.0f, 0.0f), 255.0f));
	col->ch[A] = (uint8_t)roundf(fminf(fmaxf(col->a * 255.0f, 0.0f), 255.0f));
}
