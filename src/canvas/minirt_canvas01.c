/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/18 22:21:53 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void    write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color *col)
{
    (void)col;
    set_color(&canvas->pixels[y][x], 1, 0, 0);
//    canvas->pixels[y][x] = *col;
}
