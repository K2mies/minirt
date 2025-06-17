/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/26 11:20:57 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

void	write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color col)
{
	set_color(&canvas->pixels[y][x], col.r, col.g, col.b);
}
