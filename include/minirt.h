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
# include <stdint.h>
# include <stdbool.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

/* ================================ TYPEDEFS ================================ */

// Custom typedef for float (so can be switched to double later for testing)
typedef float	t_float;

// Typedef for Touple
typedef struct s_tuple
{
	t_float		x;
	t_float		y;
	t_float		z;
	t_float		w;
}	t_tuple;

// Typedef for Color
typedef struct s_color
{
	uint32_t	rgba;
	uint8_t		ch[4];
	t_float		r;
	t_float		g;
	t_float		b;
	t_float		a;
}	t_color;

// Typedef for Canvas
typedef struct	s_canvas
{
    int         width;
    int         height;
    t_color     **pixels;
}   t_canvas;

// Typedef for Matrix
typedef struct	s_matrix
{
	t_float	m[4][4];
}	t_matrix;

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
t_tuple		point(t_float x, t_float y, t_float z);
t_tuple		vector(t_float x, t_float y, t_float z);
/* -------------------------------------------------------- minirt_tuples01.c */
t_tuple		add_tuples(t_tuple *tupa, t_tuple *tupb);
t_tuple		sub_tuples(t_tuple *tupa, t_tuple *tupb);
t_tuple		negate_tuple(t_tuple *tup);
/* -------------------------------------------------------- minirt_tuples02.c */
t_tuple		multiply_tuple_by_scalar(t_tuple *tup, t_float scalar);
t_tuple		devide_tuple_by_scalar(t_tuple *tup, t_float scalar);
/* -------------------------------------------------------- minirt_tuples03.c */
t_float		get_magnitude(t_tuple *vec);
t_tuple		*normalize_vector(t_tuple *vec);
/* -------------------------------------------------------- minirt_tuples04.c */
bool		compare_tuples(t_tuple *tupa, t_tuple *tupb);
bool		is_tuple_vector(t_tuple *tup);
bool		is_tuple_point(t_tuple *tup);
/* -------------------------------------------------------- minirt_tuples05.c */
t_float		dot_product(t_tuple *a, t_tuple *b);
t_tuple		cross_product(t_tuple *a, t_tuple *b);
/* ---------------------------------------------------------- minirt_t_floats.c */
bool		compare_floats(t_float a, t_float b);

/* ================================ COLORS ================================== */

/* --------------------------------------------------------- minirt_color00.c */
t_color		*color(t_float r, t_float g, t_float b);
void		set_color(t_color *a, t_float r, t_float g, t_float b);
/* --------------------------------------------------------- minirt_color01.c */
void		convert_rgba_to_hex(t_color *col);
void		convert_hex_to_rgba(t_color *col);
/* --------------------------------------------------------- minirt_color02.c */
void		convert_channels_to_hex(t_color *col);
void		convert_hex_to_channels(t_color *col);
void		convert_channels_to_rgba(t_color *col);
void		convert_rgba_to_channels(t_color *col);
/* --------------------------------------------------------- minirt_color03.c */
t_color		*add_colors(t_color *cola, t_color *colb);
t_color		*sub_colors(t_color *cola, t_color *colb);
/* --------------------------------------------------------- minirt_color04.c */
t_color		*multiply_color_by_scalar(t_color *col, t_float scalar);
t_color		*multiply_color(t_color *cola, t_color *colb);

/* ================================ CANVAS ================================== */

/* -------------------------------------------------------- minirt_canvas00.c */
t_canvas	*canvas(int width, int height);
/* -------------------------------------------------------- minirt_canvas01.c */
void		write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color *col);

/* ===========================++===== PPM ==+================================ */

/* ----------------------------------------------------------- minirt_ppm00.c */
void		canvas_to_ppm(t_canvas *canvas);

/* ===========================++=== MATRIX ================================== */

/* -------------------------------------------------------- minirt_matrix00.c */
t_matrix	matrix(void);
t_matrix	id_matrix(void);

#endif
