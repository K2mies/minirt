/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ppm00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:41:20 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/19 16:21:17 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

static void	create_ppm_header(int *fd, t_canvas *canvas)
{
	char	*width;
	char	*height;

	width = ft_itoa(canvas->width);
	height = ft_itoa(canvas->height);
	ft_putendl_fd("P3", *fd);
	ft_putendl_fd("", *fd);
	ft_putstr_fd(width, *fd);
	ft_putstr_fd(" ", *fd);
	ft_putendl_fd(height, *fd);
	ft_putendl_fd("", *fd);
	ft_putendl_fd("255", *fd);
	ft_putendl_fd("", *fd);
	free(width);
	free(height);
}

/**
 * Helper function to fill a .ppm file
 * with pixel data read from a t_canvas type.
 * and written to the file descriptor for teh
 * .ppm file
 *
 * @param fd		file descriptor for the ,ppm to write into
 * @param canvas	pointer to the canvas to read from
 */
static void	create_ppm_pixels(int *fd, t_canvas *canvas)
{
	int		x;
	int		y;
	char	*num;

	y = -1;
	while (++y < canvas->height)
	{
		x = -1;
		while (++x < canvas->width)
		{
			num = ft_itoa(canvas->pixels[y][x].ch[R]);
			ft_putstr_fd(num, *fd);
			ft_putstr_fd(" ", *fd);
			free(num);
			num = ft_itoa(canvas->pixels[y][x].ch[G]);
			ft_putstr_fd(num, *fd);
			ft_putstr_fd(" ", *fd);
			free(num);
			num = ft_itoa(canvas->pixels[y][x].ch[B]);
			ft_putendl_fd(num, *fd);
			free(num);
		}
	}
    printf("w = %d h = %d\n", x, y);
}

/**
 * Function to create a .ppm file
 * and fill it with data from a
 * t_canvas type
 *
 * @param canvas	pointer to the canvase to export to ppm
 */
void	canvas_to_ppm(t_canvas *canvas)
{
	int		fd;

	fd = open("./export/test.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	create_ppm_header(&fd, canvas);
	create_ppm_pixels(&fd, canvas);
	close(fd);
}
