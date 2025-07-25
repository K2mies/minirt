/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_canvas01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 21:39:42 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:09:11 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color col)
{
	set_color(&canvas->pixels[y][x], col.r, col.g, col.b);
}
