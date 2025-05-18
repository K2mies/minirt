/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:11:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/12 12:58:25 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINIRT_H
# define MINIRT_H

/* =============================== HEADERS ================================== */

/* -------------------------------------------------------------------- libft */
# include "../lib/libft/libft.h"
/* -------------------------------------------------------------------- MLX42 */
# include "../lib/MLX42/include/MLX42/MLX42.h"
/* ----------------------------------------------- miniRT specific inclusions */
# include <stdio.h>
# include <stdbool.h>
# include <math.h>

/* ================================ TYPEDEFS ================================ */

// Typedef for Touple
typedef struct s_tuple
{
	float		x;
	float		y;
	float		z;
	float		w;
}	t_tuple;

// Typedef for Color
typedef struct s_color
{
	uint32_t	rgba;
	uint8_t		ch[4];
	float		r;
	float		g;
	float		b;
	float		a;
}	t_color;

// Typedef for Canvas
typedef struct s_canvas
{
    int         width;
    int         height;
    t_color     **pixels;
}   t_canvas;

// Typedef for Main data struct
typedef struct s_minirt
{
    t_canvas    *canvas;

}   t_minirt;

/* ================================ ENUMS =================================== */
//Enum for RGBA channels 
enum	channel_type
{
	A,
	B,
	G,
	R,
};

/* ================================ TOUPLES ================================= */

/* -------------------------------------------------------- minirt_tuples00.c */
t_tuple		*point(float x, float y, float z);
t_tuple		*vector(float x, float y, float z);
/* -------------------------------------------------------- minirt_tuples01.c */
t_tuple		*add_tuples(t_tuple *tupa, t_tuple *tupb);
t_tuple		*sub_tuples(t_tuple *tupa, t_tuple *tupb);
t_tuple		*negate_tuple(t_tuple *tup);
/* -------------------------------------------------------- minirt_tuples02.c */
t_tuple		*multiply_tuple_by_scalar(t_tuple *tup, float scalar);
t_tuple		*devide_tuple_by_scalar(t_tuple *tup, float scalar);
/* -------------------------------------------------------- minirt_tuples03.c */
float		get_magnitude(t_tuple *vec);
t_tuple		*normalize_vector(t_tuple *vec);
/* -------------------------------------------------------- minirt_tuples04.c */
bool		compare_tuples(t_tuple *tupa, t_tuple *tupb);
bool		is_tuple_vector(t_tuple *tup);
bool		is_tuple_point(t_tuple *tup);
/* -------------------------------------------------------- minirt_tuples05.c */
float		dot_product(t_tuple *a, t_tuple *b);
t_tuple		*cross_product(t_tuple *a, t_tuple *b);
/* ---------------------------------------------------------- minirt_floats.c */
bool		compare_floats(float a, float b);

/* ================================ COLORS ================================== */

/* --------------------------------------------------------- minirt_color00.c */
t_color		*color(float r, float g, float b);
/* --------------------------------------------------------- minirt_color01.c */
void	    convert_rgba_to_hex(t_color *col);
void        convert_hex_to_rgba(t_color *col);
/* --------------------------------------------------------- minirt_color02.c */
void        convert_channels_to_hex(t_color *col);
void		convert_hex_to_channels(t_color *col);
void        convert_channels_to_rgba(t_color *col);
void        convert_rgba_to_channels(t_color *col);
/* --------------------------------------------------------- minirt_color03.c */
t_color     *add_colors(t_color *cola, t_color *colb);
t_color     *sub_colors(t_color *cola, t_color *colb);
/* --------------------------------------------------------- minirt_color04.c */
t_color     *multiply_color_by_scalar(t_color *col, float scalar);
t_color     *multiply_color(t_color *cola, t_color *colb);

/* ================================ CANVAS ================================== */

/* -------------------------------------------------------- minirt_canvas00.c */
t_canvas    *canvas(int width, int height);
/* -------------------------------------------------------- minirt_canvas01.c */
void        write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color *col);
#endif
