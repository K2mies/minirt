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
uint32_t	convert_rgba_to_hex(float r, float g, float b, float a);
void		convert_hex_into_channels(t_color *col);

#endif
