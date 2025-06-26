/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:11:13 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/16 11:51:31 by rhvidste         ###   ########.fr       */
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
# include <stdbool.h>
//# include <float.h>


/* ================================= MACROS ================================= */

# define M_PI 3.14159265358979323846
# define EPSILON		0.00001f
# define SHADOW_BIAS	0.01f
# define PATTERN_SHIFT	0.01f
# define BOUNCE_LIMIT	4
# define MAX_CONTAINERS 6

# define RED	0xFF0000FF
# define GREEN	0x00FF00FF
# define BLUE	0x0000FFFF
# define WHITE	0xFFFFFFFF
# define BLACK	0x000000FF

/* ================================ TYPEDEFS ================================ */

/* --------------------------------------------------------------------- refs */
typedef struct s_ray		t_ray;
typedef struct	s_pattern	t_pattern;
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

/* ---------------------------------------------------------------- matracies */
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

/* --------------------------------------------------------------------- rays */
// Typedef for ray
typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

/* -----------------------------------------------------------------materials */
// Typedef for pattern
typedef struct	s_pattern
{
	int			type;
	t_color		a;
	t_color		b;
	t_matrix4	transform;
}	t_pattern;

// Typedef for phong material
typedef struct	s_material
{
	t_color		color;
	bool		has_pattern;
	t_pattern	pattern;
	t_float		transparency;
	t_float		refractive_index;
	t_float		reflective;
	t_float		ambient;
	t_float		diffuse;
	t_float		specular;
	t_float		shininess;
}	t_material;

/* --------------------------------------------------------------- Scene Data */
// Typedef for ambient light
typedef struct s_ambient
{
	t_float	ratio;
	t_color	color;
}	t_ambient;

// Typedef for camera
typedef struct s_camera
{
	t_tuple		origin;
	t_tuple		vector;
	t_matrix4	transform;
	t_float		dim[2];
	t_float		fov;
	t_float		half_view;
	t_float		aspect;
	t_float		half[2];
	t_float		pixel_size;
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
	t_tuple		origin;
	t_tuple		vector;
	t_float		diameter;
	t_float		radius;
	t_float		height;
	t_color		color;
	t_material	material;
	t_matrix4	transform;
	t_ray		saved_ray;
}	t_object;

// Typedef for wall
typedef struct	s_wall
{
	t_tuple	origin;
	t_float	width;
	t_float	height;	
}	t_wall;

/* --------------------------------------------------------------- intersections */

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
	int			obj_index;
}	t_intersection;

/* -------------------------------------------------------------------- containers */
typedef struct	s_obj_container
{
	t_object	*objs[MAX_CONTAINERS];
	int			n_obj;
}				t_obj_container;
/* ------------------------------------------------------------- computations */
//Typedef fpr computations
//the v[3] array consists of
//v[pos]
//v[eyev]
//v[normalv]
//v[reflectv]
typedef struct	s_computations
{

	t_float		t;
	t_float		n[2];
	t_tuple		v[5];
	t_object	object;
	t_tuple		over_point;
	t_tuple		under_point;
	bool		inside;
}	t_computations;

/* -------------------------------------------------------------------- world */
// Typedef for world
typedef struct	s_world
{
	t_light			light;
	t_object		*objs;
	t_intersection	*ts;
	int				n_objs;
	int				n_ts;
	t_computations	*cs;
	int				hit_index;

}	t_world;

/* =========================== MAIN DATA STRUCT ============================= */
/* --------------------------------------------------------- main data struct */
// Typedef for Main data struct
typedef struct s_minirt
{
	char			***full_data;
	t_canvas		*canvas;
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;
	t_object		*objs;
	int				n_objs;
	int				n_ts;
	t_intersection	*ts;
	int				mlx_d[2];
	mlx_t			*mlx;
	mlx_image_t		*img;

}	t_minirt;

/* ============================== PARAMATERS ================================ */

typedef	struct	s_ray_for_pixel_param
{
	t_float	offset[2];
	t_float	world[2];
	t_tuple	pixel;
	t_tuple	origin;
	t_tuple	direction;

}	t_ray_for_pixel_param;

// Typedef for view transform paramaters
typedef struct	s_view_transform_param
{
	t_tuple		forward;
	t_tuple		upn;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix4	orientation;
}	t_view_transform_param;
// Typedef for lighting function paramaters
typedef struct	s_lighting_param
{
	t_object	obj;
	t_color		ambient;
	t_color		diffuse;
	t_color		specular;
	t_color		effective_color;
	t_tuple		reflectv;
	t_tuple		lightv;
	t_float		light_dot_normal;
	t_float		reflect_dot_eye;
	t_float		factor;
	bool		in_shadow;

}	t_lighting_param;

typedef struct	s_render_param
{
	t_canvas	*img;
	t_color		col;
	t_ray		ray;
	int			bounce_limit;

}	t_render_param;

/* ================================ ENUMS =================================== */

//Enum for img dimensions
typedef enum	e_dim
{
	h,
	w
}	t_dim;

//Enum for dimensions
typedef enum	e_dimensions
{
	width,
	height
}	t_dimensions;

//Enum for vectors
typedef enum	e_vectors
{
	pos,
	eyev,
	normalv,
	reflectv
}	t_vectors;

//Enum for phong material paramaters
typedef enum	e_phong
{
	ambient,
	diffuse,
	specular,
	shininess,
	reflective,
	transparency,
	refractive_index
}	t_phong;

//Enum for axis
typedef enum	e_axis
{
	x,
	y,
	z
}	t_axis;

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
	R
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

//Enum for object shape/object types
enum e_shape_types
{
	SPHERE,
	PLANE,
	CYLINDER
};

//Enum for pattern types
enum e_pattern_types
{
	STRIPE,
	GRADIENT,
	RING,
	CHECKER
};
typedef enum e_error
{
	ERROR_MLX,
	ERROR_IMG

}	t_error;
/* ================================ ERROR MSG ================================ */

# define MSG_ERROR_MLX		"ERROR: mlx init failed"
# define MSG_ERROR_MLX_IMG	"ERROR: mlx img failed"

/* =============================== DEFINITIONS =============================== */

/* ================================= TUPLE`S ================================= */

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
t_color		add_three_colors(t_color cola, t_color colb, t_color colc);
t_color		add_colors(t_color cola, t_color colb);
t_color		sub_colors(t_color cola, t_color colb);
/* --------------------------------------------------------- minirt_color04.c */
t_color		multiply_color_by_scalar(t_color col, t_float scalar);
t_color		multiply_color(t_color cola, t_color colb);
/* --------------------------------------------------------- minirt_color05.c */
void		set_pattern_transform(t_pattern *pat, t_matrix4 m);
t_pattern	pattern(t_color a, t_color b, int type);
t_color		pattern_at(t_pattern	pat, t_object obj, t_tuple world_point);
/* --------------------------------------------------------- minirt_color06.c */
t_color		stripe_at(t_pattern pat, t_tuple point);
t_color		stripe_at_object(t_pattern pattern, t_object obj, t_tuple world_point);
/* --------------------------------------------------------- minirt_color07.c */
t_color		gradient_at(t_pattern gradient, t_tuple point);
t_color		gradient_at_object(t_pattern pattern, t_object obj, t_tuple world_point);
/* --------------------------------------------------------- minirt_color08.c */
t_color		ring_at(t_pattern ring, t_tuple p);
t_color		ring_at_object(t_pattern pattern, t_object obj, t_tuple world_point);

/* --------------------------------------------------------- minirt_color09.c */
t_color		checker_at(t_pattern check, t_tuple p);
t_color		checker_at_object(t_pattern pattern, t_object obj, t_tuple world_point);

/* --------------------------------------------------------- minirt_color10.c */
t_color		reflected_color(t_world world, t_computations comps, int *remaining);

/* ================================ CANVAS ================================== */

/* -------------------------------------------------------- minirt_canvas00.c */
t_canvas	*canvas(int width, int height);
/* -------------------------------------------------------- minirt_canvas01.c */
void		write_pixel_to_canvas(t_canvas *canvas, int x, int y, t_color col);
/* -------------------------------------------------------- minirt_canvas02.c */
t_canvas	*render(t_camera cam, t_world world);
void		mlx_render(t_minirt *rt, t_camera cam, t_world world);

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
/* ----------------------------------------------------- minirt_transform04.c */
t_matrix4	view_transform(t_tuple from, t_tuple to, t_tuple up);

/* ============================ RAY CASTING ================================= */

/* ----------------------------------------------------------- minirt_ray00.c */
t_ray				ray(t_tuple origin, t_tuple direction);
t_tuple				position(t_ray ray, t_float t);
/* ----------------------------------------------------------- minirt_ray01.c */
t_intersection		intersection(t_float t, t_object obj);
t_intersections		object_intersection(t_object *obj, t_ray ray);
void				world_intersect(t_world *w, t_ray ray);
/* ----------------------------------------------------------- minirt_ray02.c */
t_intersections		sphere_intersection(t_object *sphere, t_ray ray);
t_intersections		plane_intersection(t_object *plane, t_ray ray);
/* ----------------------------------------------------------- minirt_ray03.c */
t_ray				transform(t_ray r, t_matrix4 m);
void				set_transform(t_object *s, t_matrix4 m);
/* ----------------------------------------------------------- minirt_ray04.c */
t_tuple				normal_at(t_object obj, t_tuple world_point);
t_tuple				normal_at_sphere(t_object obj, t_tuple world_point);
t_tuple				normal_at_plane(t_object obj);
/* ----------------------------------------------------------- minirt_ray05.c */
t_tuple				reflect(t_tuple in, t_tuple normal);
/* ----------------------------------------------------------- minirt_ray06.c */
t_color				lighting(t_lighting_param p, t_material m, t_light light, t_tuple v[3]);
bool				is_shadowed(t_world world, t_tuple point);
/* ----------------------------------------------------------- minirt_ray07.c */
t_computations		prepare_computations(t_world w, t_intersection i, t_ray r);
/* ----------------------------------------------------------- minirt_ray08.c */
void				prepare_refraction_calculations(t_world *w, t_computations *comps, t_intersection *target);
/* ----------------------------------------------------------- minirt_ray09.c */
t_intersection		hit(t_world *w);
t_color				shade_hit(t_world w, t_computations comps, t_object obj, int *remaining);
/* ----------------------------------------------------------- minirt_ray10.c */
t_color				color_at(t_world w, t_ray r, int *remaining);
/* ----------------------------------------------------------- minirt_ray11.c */
t_ray				ray_for_pixel(t_camera cam, t_float px, t_float py);
/* ============================== OBJECTS =================================== */

/* -------------------------------------------------------- minirt_object00.c */
t_object	sphere(t_tuple location, t_float diameter, t_color col);
t_object	glass_sphere(t_tuple location, t_float diameter, t_color col);
/* -------------------------------------------------------- minirt_object01.c */
t_object	plane(t_tuple origin, t_tuple normal, t_color col);
/* -------------------------------------------------------- minirt_object02.c */
t_wall		wall(t_tuple position, t_float width, t_float height);
/* -------------------------------------------------------- minirt_object03.c */
t_light		point_light(t_tuple origin, t_float brightness, t_color col);
/* -------------------------------------------------------- minirt_object04.c */
t_material	material(t_float param[7], t_color col);
/* -------------------------------------------------------- minirt_object05.c */
t_world		world(t_minirt *rt);
t_world		default_world(t_minirt *rt);
/* -------------------------------------------------------- minirt_object06.c */
t_camera	camera(int h_size, int w_size, t_float fov);
/* ================================ MLX ===================================== */

/* ----------------------------------------------------------- minirt_mlx00.c */
void		mlx_start(t_minirt *rt, int width, int height);
void		color_fill(t_minirt *rt);

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
/* -------------------------------------------------------- utils/quicksort.c */
void		quicksort(t_intersection arr[], int low, int high);
/* ------------------------------------------------------- utils/containers.c */

void		update_container(t_obj_container *container, t_object *obj);
bool		is_inside_container(t_obj_container *container, t_object *obj, int *index);
void		remove_from_container(t_obj_container *container, int index);
void		add_to_container(t_obj_container *container, t_object *obj);
t_float		get_refractive_index(t_obj_container *con);
/* ================================= PARSING ================================ */

/* ----------------------------------------------------- parsing/validation.c */
void		open_file(t_minirt *rt, char **argv);
/* ----------------------------------------------- parsing/validation_utils.c */
int			valid_map_name(char *name);
int			open_rt(t_minirt *rt, char *path);
bool		is_in_range(t_float f, int min, int max);
bool		validate_rgb(char **rgb);
bool		file_entry_error(int a, int c, int l, int obj);
/* ---------------------------------------------------------- parsing/utils.c */
bool		validate_size(char **data, int size);
void		data_null_check(t_minirt *rt, char **data, char **tmp, char *line);
bool		rt_isstrdigit(char *str);
/* --------------------------------------------------------- parsing/sorting.c */
void		sort_data_types(t_minirt *rt, char ***full);
/* ---------------------------------------------------------- parsing/object.c */
void		load_cylinder(t_minirt *rt, char **data, int index);
void		load_sphere(t_minirt *rt, char **data, int index);
void		load_plane(t_minirt *rt, char **data, int index);
void		object_error(t_minirt *rt, char **a1, char **a2, char **a3);

/////////////Remove these///////////////
void	print_3d_data_array(char ***arr);
void	print_stored_data(t_minirt *rt);

#endif
