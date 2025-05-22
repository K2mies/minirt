/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:47:45 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/18 21:39:13 by rhvidste         ###   ########.fr       */
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
static void    init_canvas_pixels(t_canvas *canvas)
{
    int i;
    int j;
    
    canvas->pixels = malloc(sizeof(t_color *) * canvas->width);
    i = -1;
    while (++i < canvas->width)
    {
        canvas->pixels[i] = malloc(sizeof(t_color *) * canvas->height);
        if (!canvas->pixels[i])
        {
            while (i--)
                free(canvas->pixels[i]);
            printf("canvas pixels freed\n");
            return ;
        }
        j = -1;
        while (++j < canvas->height)
            canvas->pixels[i][j] = *color(0, 0, 0);
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
t_canvas    *canvas(int width, int height)
{
    t_canvas    *canvas;

    canvas = malloc(sizeof(t_canvas));
    canvas->width = width;
    canvas->height = height;
    init_canvas_pixels(canvas);
    return (canvas);
}
