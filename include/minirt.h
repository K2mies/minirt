/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:11:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/30 14:03:12 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
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
# include <errno.h>


/* ================================= MACROS ================================= */

# define M_PI 3.14159265358979323846

/* ================================ TYPEDEFS ================================ */

/* ------------------------------------------------------------- custom types */
// Custom typedef for float (so can be switched to double later for testing)
typedef float	t_float;

/* ------------------------------------------------------------------- tuples */
// Typedef for Touple
typedef struct s_tuple
{
	t_float		x;
	t_float		y;
	t_float		z;
	t_float		w;
}	t_tuple;

/* ------------------------------------------------------------------- colors */
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

/* ------------------------------------------------------------------- canvas */
// Typedef for Canvas
typedef struct s_canvas
{
	int		width;
	int		height;
	t_color	**pixels;
}	t_canvas;

/* -------------------------------------------------------------- matracies */
// Typedef for 4X4 Matrix
typedef struct s_matrix4
{
	t_float	m[4][4];
}	t_matrix4;

// Typedef for 3X3 Matrix
typedef struct s_matrix3
{
	t_float	m[3][3];
}	t_matrix3;

// Typedef for 2X2 Matrix
typedef struct s_matrix2
{
	t_float	m[2][2];
}	t_matrix2;

/* -------------------------------------------------------------- Scene Data */
// Typedef for ambient light
typedef struct s_ambient
{
	t_float	ratio;
	t_color	color;
}	t_ambient;

// Typedef for camera
typedef struct s_camera
{
	t_tuple origin;
	t_tuple	vector;
	int		fov;
}	t_camera;

// Typedef for light source
typedef struct s_light
{
	t_tuple origin;
	t_float brightness;
	t_color	color;
}	t_light;

// Typedef for objects
typedef struct s_object
{
	int	type;
	t_tuple origin;
	t_tuple	vector;
	t_float diameter;
	t_float	radius;
	t_float	height;
	t_color	color;
}	t_object;

/* ------------------------------------------------------------------- rays.c */
// Typedef for ray
typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

// Typedef for ray intersections
typedef struct s_intersections
{
	t_float	t[2];
	int		count;

}	t_intersections;

// Typedef for object intersection
typedef struct s_intersection
{
	t_float		t;
	t_object	object;
}	t_intersection;

/* --------------------------------------------------------- main data struct */
// Typedef for Main data struct
typedef struct s_minirt
{
	t_canvas		*canvas;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_object		**object;
	int				n_obj;
	char			***full_data;
	t_intersection	*ts;
	int				n_ts;

}	t_minirt;

/* ================================ ENUMS =================================== */

//Enum for letters to use  with var arr ie: arr[a], arr[b] etc..
typedef enum	e_letters
{
	a,
	b,
	c
}	t_letters;

//Enum for RGBA channels 
enum	e_channel_type
{
	A,
	B,
	G,
	R,
};

//Enum for shearing proportions
typedef enum	e_proportions
{
	XY,
	XZ,
	YX,
	YZ,
	ZX,
	ZY
}	t_proportions;

//Enum for object types
enum e_types
{
	SPHERE,
	PLANE,
	CYLINDER
};

/* ============================== DEFINITIONS =============================== */

/* ================================= TUPLES ================================= */

/* -------------------------------------------------------- minirt_tuples00.c */
t_tuple		tuple(t_float x, t_float y, t_float z, t_float w);
t_tuple		point(t_float x, t_float y, t_float z);
t_tuple		vector(t_float x, t_float y, t_float z);
/* -------------------------------------------------------- minirt_tuples01.c */
t_tuple		add_tuples(t_tuple tupa, t_tuple tupb);
t_tuple		sub_tuples(t_tuple tupa, t_tuple tupb);
t_tuple		negate_tuple(t_tuple tup);
/* -------------------------------------------------------- minirt_tuples02.c */
t_tuple		multiply_tuple_by_scalar(t_tuple tup, t_float scalar);
t_tuple		devide_tuple_by_scalar(t_tuple tup, t_float scalar);
/* -------------------------------------------------------- minirt_tuples03.c */
t_float		get_magnitude(t_tuple vec);
t_tuple		normalize_vector(t_tuple vec);
/* -------------------------------------------------------- minirt_tuples04.c */
bool		compare_tuples(t_tuple tupa, t_tuple tupb);
bool		is_tuple_vector(t_tuple tup);
bool		is_tuple_point(t_tuple tup);
/* -------------------------------------------------------- minirt_tuples05.c */
t_float		dot_product(t_tuple a, t_tuple b);
t_tuple		cross_product(t_tuple a, t_tuple b);
/* -------------------------------------------------------- minirt_t_floats.c */
bool		compare_floats(t_float a, t_float b);

/* ================================ COLORS ================================== */

/* --------------------------------------------------------- minirt_color00.c */
t_color		color(t_float r, t_float g, t_float b);
void		set_color(t_color *a, t_float r, t_float g, t_float b);
t_color		color_from_channels(uint8_t r, uint8_t g, uint8_t b);
/* --------------------------------------------------------- minirt_color01.c */
void		convert_rgba_to_hex(t_color *col);
void		convert_hex_to_rgba(t_color *col);
/* --------------------------------------------------------- minirt_color02.c */
void		convert_channels_to_hex(t_color *col);
void		convert_hex_to_channels(t_color *col);
void		convert_channels_to_rgba(t_color *col);
void		convert_rgba_to_channels(t_color *col);
/* --------------------------------------------------------- minirt_color03.c */
t_color		add_colors(t_color cola, t_color colb);
t_color		sub_colors(t_color cola, t_color colb);
/* --------------------------------------------------------- minirt_color04.c */
t_color		multiply_color_by_scalar(t_color col, t_float scalar);
t_color		multiply_color(t_color cola, t_color colb);

/* ================================ CANVAS ================================== */

/* -------------------------------------------------------- minirt_canvas00.c */
t_canvas	*canvas(int width, int height);
/* -------------------------------------------------------- minirt_canvas01.c */
void		write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color *col);

/* ================================== PPM =================================== */

/* ----------------------------------------------------------- minirt_ppm00.c */
void		canvas_to_ppm(t_canvas *canvas);

/* ================================ MATRIX ================================== */

/* -------------------------------------------------------- minirt_matrix00.c */
t_matrix4	id_matrix4(void);
t_matrix4	matrix4(void);
t_matrix3	matrix3(void);
t_matrix2	matrix2(void);
/* -------------------------------------------------------- minirt_matrix01.c */
bool		compare_matrix4(t_matrix4 a, t_matrix4 b);
bool		compare_matrix3(t_matrix3 a, t_matrix3 b);
bool		compare_matrix2(t_matrix2 a, t_matrix2 b);
/* -------------------------------------------------------- minirt_matrix02.c */
t_matrix4	multiply_matrix4(t_matrix4 a, t_matrix4 b);
t_tuple		multiply_matrix4_tuple(t_matrix4 m, t_tuple t);
/* -------------------------------------------------------- minirt_matrix03.c */
t_matrix4	transpose_matrix4(t_matrix4 m);
t_float		determinent_of_matrix2(t_matrix2 m);
t_float		determinent_of_matrix3(t_matrix3 m);
t_float		determinent_of_matrix4(t_matrix4 m);
/* -------------------------------------------------------- minirt_matrix04.c */
t_matrix3	submatrix4(t_matrix4 m, int row, int col);
t_matrix2	submatrix3(t_matrix3 m, int row, int col);
/* -------------------------------------------------------- minirt_matrix05.c */
t_float		minor4(t_matrix4 m, int row, int col);
t_float		minor3(t_matrix3 m, int row, int col);
t_float		cofactor4(t_matrix4 m, int row, int col);
t_float		cofactor3(t_matrix3 m, int row, int col);
/* -------------------------------------------------------- minirt_matrix06.c */
bool		is_matrix4_invertable(t_matrix4 m);
t_matrix4	inverse_matrix4(t_matrix4 m);

/* ============================= TRANSFORMS ================================= */

/* ----------------------------------------------------- minirt_transform00.c */
t_matrix4	translation(t_float x, t_float y, t_float z);
/* ----------------------------------------------------- minirt_transform01.c */
t_matrix4	scaling(t_float x, t_float y, t_float z);
/* ----------------------------------------------------- minirt_transform02.c */
double		deg_to_rad(t_float degrees);
t_matrix4	rotation_x(t_float deg);
t_matrix4	rotation_y(t_float deg);
t_matrix4	rotation_z(t_float deg);
/* ----------------------------------------------------- minirt_transform03.c */
t_matrix4	shearing(t_float proportions[6]);

/* ============================ RAY CASTING ================================= */

/* ----------------------------------------------------------- minirt_ray00.c */
t_ray				ray(t_tuple origin, t_tuple direction);
t_tuple				position(t_ray ray, t_float t);
/* ----------------------------------------------------------- minirt_ray01.c */
t_intersection		intersection(t_float t, t_object obj);
t_intersections		sphere_intersection(t_object sphere, t_ray ray);

/* ============================== OBJECTS =================================== */

/* -------------------------------------------------------- minirt_object00.c */
t_object	sphere(t_tuple location, t_float radius);

/* =============================== ERROR ==================================== */

/* -------------------------------------------------------- error/arg_error.c */
void		rt_error(t_minirt *rt, char *msg, int err);
void		argc_error(int argc);

/* =============================== UTILS ==================================== */

/* ------------------------------------------------------------ utils/close.c */
void		close_rt(t_minirt *rt, int ex);
/* ------------------------------------------------------------ utils/utils.c */
void		free_big_array(char ****arr);
t_float		ft_atof(char *str);
bool		validate_array(char **arr);
bool		ft_isfloat(char *str);
/* ----------------------------------------------------------- utils/memory.c */
void		*rt_malloc(t_minirt *rt, size_t size);
void		object_free(char **arr1, char **arr2, char **arr3);
void		cleanup_rt(t_minirt *rt);

/* ================================= PARSING ================================= */

/* ------------------------------------------------------ parsing/validation.c */
void		open_file(t_minirt *rt, char **argv);
/* ------------------------------------------------------ parsing/validation_utils.c */
int			valid_map_name(char *name);
int			open_rt(t_minirt *rt, char *path);
bool		is_in_range(t_float f, int min, int max);
bool		validate_rgb(char **rgb);
bool		file_entry_error(int a, int c, int l, int obj);
/* ----------------------------------------------------------- parsing/utils.c */
bool		validate_size(char **data, int size);
void		data_null_check(t_minirt *rt, char **data, char **tmp, char *line);
bool		rt_isstrdigit(char *str);
/* --------------------------------------------------------- parsing/sorting.c */
void		sort_data_types(t_minirt *rt, char ***full);
/* ------------------------------------------------------==-- parsing/object.c */
void		load_cylinder(t_minirt *rt, char **data, int index);
void		load_sphere(t_minirt *rt, char **data, int index);
void		load_plane(t_minirt *rt, char **data, int index);
void		object_error(t_minirt *rt, char **a1, char **a2, char **a3);

/////////////Remove these///////////////
void	print_3d_data_array(char ***arr);
void	print_stored_data(t_minirt *rt);

#endif
