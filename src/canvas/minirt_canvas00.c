/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:47:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/26 11:19:45 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Helper Function to initialise canvas pixels
 * to color(0,0,0) aka BLACK.
 *
 * @param canvas	pointer to canvas from which
 *                  to popullate pixels array
 */
static void	init_canvas_pixels(t_canvas *canvas)
{
	int	x;
	int	y;

	canvas->pixels = malloc(sizeof(t_color *) * canvas->height);
	y = -1;
	while (++y < canvas->height)
	{
		canvas->pixels[y] = malloc(sizeof(t_color) * canvas->width);
		if (!canvas->pixels[y])
		{
			while (y--)
				free(canvas->pixels[y]);
			printf("canvas pixels freed\n");
			return ;
		}
		x = -1;
		while (++x < canvas->width)
			set_color(&canvas->pixels[y][x], 0, 0, 0);
	}
}

/**
 * Function to create a canvas 
 * based on a width and height
 *
 * @param width		width of canvas
 * @param height	height of canvas
 *
 * @return		canvas type struct
 */
t_canvas	*canvas(int width, int height)
{
	t_canvas	*canvas;

	canvas = malloc(sizeof(t_canvas));
	canvas->width = width;
	canvas->height = height;
	init_canvas_pixels(canvas);
	return (canvas);
}
