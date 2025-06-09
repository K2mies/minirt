/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:24:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/30 17:18:27 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//static void	test_return_point(t_float x, t_float y, t_float z)
//{
//	t_tuple	*point;
//
//	point = point(x, y, z);
//	printf("x: %f\ny: %f\nz: %f\nw: %f\n\n", point->x, point->y, point->z, point->w);
//	free(point);
//}
//
//static void	test_return_vector(t_float x, t_float y, t_float z)
//{
//	t_tuple	*vec;
//
//	vec = vector(x, y, z);
//	printf("x: %f\ny: %f\nz: %f\nw: %f\n\n", vec->x, vec->y, vec->z, vec->w);
//	free(vec);
//}

//static bool is_tuple_vector(t_tuple *tuple)
//{
//	if (tuple->w == 0)
//		return (true);
//	return (false);
//}
//
//static	void	test_is_tuple_a_vector_or_point(t_float x, t_float y, t_float z, t_float w)
//{
//	t_tuple	*tup;
//
//	if (w == 1.0)
//		tup = point(x, y, z);
//	else
//		tup = vector(x, y, z);
//	if (is_tuple_vector(tup) == true)
//		printf("Tuple is a vector\n");
//	else
//		printf("Tuple is a point\n");
//	free(tup);
//}

//static void	test_if_two_t_floats_equivilant(t_float a, t_float b)
//{
//	if (compare_t_floats(a, b) == true)
//		printf("t_floats are equivilant\n");
//	else
//		printf("t_floats are not equivilant\n");
//}

//static void	test_if_two_tuples_are_equivilant()
//{
//	t_tuple	tupa;
//	t_tuple	tupb;
//
//	tupa = vector(10, 0.001, 10);
//	tupb = vector(10, 0.001, 10);
//
//	if (compare_tuples(&tupa, &tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");
//
//	tupa = vector(10, 0.0010, 10);
//	tupb = vector(10, 0.001, 10);
//
//	if (compare_tuples(&tupa, &tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");
//
//	tupa = vector(10, 10, 10);
//	tupb = point(10, 10, 10);
//
//	if (compare_tuples(&tupa, &tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");	
////	free(tupa);
////	free(tupb);
//}

//void	test_add_two_tuples_together()
//{
//	t_tuple	tupa;
//	t_tuple	tupb;
//	t_tuple	tupc;
//
//	tupa = point(3, -2, 5);
//	tupb = vector(-2, 3, 1);
//	tupc = add_tuples(&tupa, &tupb);
//
//	printf("tupc = x: %f y: %f z: %f w: %f", tupc.x, tupc.y, tupc.z, tupc.w);
//
//}
//
//void	test_sub_two_tuples()
//{
//	t_tuple	tupa;
//	t_tuple	tupb;
//	t_tuple	tupc;
//
//	tupa = point(3, 2, 1);
//	tupb = vector(5, 6, 7);
//	tupc = sub_tuples(&tupa, &tupb);
//
//	printf("tupc = x: %f y: %f z: %f w: %f", tupc.x, tupc.y, tupc.z, tupc.w);
//}
//
//void	test_negate_tuple()
//{
//	t_tuple	tup;
//	t_tuple	res;
//
//	tup = vector(1, -2, 3);
//	res = negate_tuple(&tup);
//	printf("res = x: %f y: %f z: %f w: %f", res.x, res.y, res.z, res.w);
//	free(tup);
//	free(res);
//}

//void	test_multiply_tuple_by_scaler()
//{
//	t_tuple	tup;
//	t_tuple	res;
//
//	tup = point(1, -2, 3);
//	res = multiply_tuple_by_scalar(&tup, 0.5);
//
//	printf("res = x: %f y: %f z: %f w: %f", res.x, res.y, res.z, res.w);
//}

//void	test_devide_tuple_by_scaler()
//{
//	t_tuple	*tup;
//	t_tuple	*res;
//
//	tup = point(1, -2, 3);
//	res = devide_tuple_by_scaler(tup, 2);
//
//	printf("res = x: %f y: %f z: %f w: %f", res->x, res->y, res->z, res->w);
//	free(tup);
//	free(res);
//}
//
//void	test_get_magnitude_of_vector()
//{
//	t_tuple	*vec;
//	t_float		res;
//
//	vec = vector(-1, -2 ,-3);
//	res = get_magnitude_of_vector(vec);
//	printf("magnitude of vector is: %f\n", res);
//	free(vec);
//}

//void	test_normalise_vector()
//{
//	t_tuple	*vec;
//	t_tuple	*norm;
//	t_float		mag;
//
//	vec = vector(1, 2 ,3);
//	norm = normalize_vector(vec);
//	mag = get_magnitude(norm);
//
//	printf("vec = x: %f y: %f z: %f w: %f\n", norm->x, norm->y, norm->z, vec->w);
//	printf("magnitude: %f\n", mag);
//
//	free(vec);
//	free(norm);
//}

//void	test_get_dot_product()
//{
//		t_tuple	*vec_a;
//		t_tuple	*vec_b;
//		t_float		res;
//
//		vec_a = vector(1, 2, 3);
//		vec_b = vector(2, 3, 4);
//		res = dot_product(vec_a, vec_b);
//		printf("dot product of vec_a and vec_b is %f\n", res);
//		free(vec_a);
//		free(vec_b);
//
//}
//
//void	test_get_cross_product()
//{
//		t_tuple	*x;
//		t_tuple	*y;
//		t_tuple	*cross;
//
//		x = vector(1, 0, 0);
//		y = vector(0, 1, 0);
//		cross = cross_product(x, y);
//
//		printf("Cross Product = x: %f y: %f z: %f w: %f\n", cross->x, cross->y, cross->z, cross->w);
//		free(x);
//		free(y);
//		free(cross);		
//}

//typedef struct	s_projectile
//{
//	t_tuple	*position;
//	t_tuple	*velocity;
//}	t_projectile;
//
//typedef struct	s_environment
//{
//	t_tuple	*gravity;
//	t_tuple	*wind;
//}	t_environment;
//
//t_projectile *tick(t_environment *env, t_projectile *proj)
//{
//	t_projectile	*res;
//	t_tuple		*position;
//	t_tuple		*velocity;
//
//	res = malloc(sizeof(t_projectile));
//	position = add_tuples(proj->position, proj->velocity);
//	velocity = add_tuples(proj->velocity, add_tuples(env->gravity, env->wind));
//	res->position = position;
//	res->velocity = velocity;
//	return (res);
//}
//
//void	test_projectile()
//{
//	t_projectile	*res;
//	t_projectile	*proj;
//	t_environment	*env;
//	int				count;
//
//	res = malloc(sizeof(t_projectile));
//	proj = malloc(sizeof(t_projectile));
//	env = malloc(sizeof(t_environment));
//
//	proj->position = point(0, 1, 0);
//	proj->velocity = normalize_vector(vector(1, 1, 0));
//	env->gravity = vector(0, -0.1, 0);
//	env->wind = vector(-0.01, 0, 0);
//
//	count = 0;
//	res = tick(env, proj);
//	count++;
//	printf("res position = x: %f, y: %f, z: %f w: %f\n", res->position->x, res->position->y, res->position->z, res->position->w);
//	while (res->position->y >= 0)
//	{
//		count++;
//		res = tick(env, res);
//		printf("res position = x: %f, y: %f, z: %f w: %f\n", res->position->x, res->position->y, res->position->z, res->position->w);
//	}
//	printf("ticks: %d\n", count);
//}
//

//void  test_print_col(t_color *col)
//{
//	printf("rgba:			0x%08X\n\n", col->rgba);
//	printf("channel values:----------------\n");
//	printf("CH[R]:		 %x\n", col->ch[R]);
//	printf("CH[G]:		 %x\n", col->ch[G]);
//	printf("CH[B]:		 %x\n", col->ch[B]);
//	printf("CH[A]:		 %x\n", col->ch[A]);
//	printf("\n0-1 values:-------------------\n");
//	printf("r:		   %f\n", col->r);
//	printf("g:		   %f\n", col->g);
//	printf("b:		   %f\n", col->b);
//	printf("a:		   %f\n", col->a);
//	printf("\nreconstructed rgba = %08x\n", (uint32_t)((col->ch[R] << 24) | (col->ch[G] << 16) | (col->ch[B] << 8) | (col->ch[A] << 0)));
//  printf("------------------------------\n");
//  printf("\n\n");
//}
//void	test_create_color()
//{
//	t_color	*col;
//
//	col = color(1, 0, 0.796);
//  printf("initial values------------------\n");
//  test_print_col(col);
//
//  printf("convert channels to hex---------\n");
//  convert_channels_to_hex(col);
//  test_print_col(col);
//
//  printf("convert hex to rgba (they should be capped)\n");
//  convert_hex_to_rgba(col);
//  test_print_col(col);
//	free(col);
//}

//void  test_add_colors_together()
//{
//  t_color *a;
//  t_color *b;
//  t_color *res;
//
//  a = color(0.9, 0.6, 0.75);
//  b = color(0.7, 0.1, 0.25);
//
//  res = add_colors(a, b);
//  test_print_col(res);
//
//  free(a);
//  free(b);
//  free(res);
//}
//
//void  test_sub_colors()
//{
//  t_color *a;
//  t_color *b;
//  t_color *res;
//
//  a = color(0.9, 0.6, 0.75);
//  b = color(0.7, 0.1, 0.25);
//
//  res = sub_colors(a, b);
//  test_print_col(res);
//
//  free(a);
//  free(b);
//  free(res);
//}
//
//void  test_multiply_color_by_scalar()
//{
//
//  t_float   scalar;
//  t_color *col;
//  t_color *res;
//
//  scalar = 2;
//  col = color(0.2, 0.3, 0.4);
//
//  res = multiply_color_by_scalar(col, scalar);
//  test_print_col(res);
//
//  free(col);
//  free(res);
//}
//
//void  test_multiply_colors()
//{
//  t_color *a;
//  t_color *b;
//  t_color *res;
//
//  a = color(1, 0.2, 0.4);
//  b = color(0.9, 1, 0.1);
//  res = multiply_color(a, b);
//
//  test_print_col(res);
//
//  free(a);
//  free(b);
//  free(res);
//}

//void  test_init_canvas()
//{
////  t_minirt  *minirt;
//  t_canvas  *can;
//  int	   i;
//  int	   j;
//
//  can = malloc(sizeof(t_canvas));
//  can = canvas(5, 5);
//
//  i = -1;
//  while (++i < can->width)
//  {
//	j = -1;
//	while (++j < can->height)
//	{
//	  printf("%08x ", can->pixels[i][j].rgba);
//	}
//	printf("\n");
//  }
//
//}

//void  test_init_minirt_data()
//{
//  t_minirt  *minirt;
//  int	   i;
//  int	   j;
//
//  minirt = malloc(sizeof(t_minirt));
//  minirt->canvas = canvas(6, 6);
//
//  i = -1;
//  while (++i < minirt->canvas->width)
//  {
//	j = -1;
//	while (++j < minirt->canvas->height)
//	{
//	  printf("%08x ", minirt->canvas->pixels[i][j].rgba);
//	}
//	printf("\n");
//
//  }
//}

//void  test_print_canvas(t_minirt *minirt)
//{
//  int	i;
//  int	j;
//
//  i = -1;
//  while (++i < minirt->canvas->width)
//  {
//	j = -1;
//	while (++j < minirt->canvas->height)
//	{
//	  printf("%08x ", minirt->canvas->pixels[i][j].rgba);
//	}
//	printf("\n");
//  }
//
//}

//void  test_color_canvas_pixel()
//{
//  t_minirt  *minirt;
//  t_color	*col1;
//  t_color	*col2;
//
//  minirt = malloc(sizeof(t_minirt));
//  minirt->canvas = canvas(4, 4);
//  col1 = color(0.31, 0.57, 0.10);
//  col2 = color(0.10, 0.31, 0.93);
//  write_pixel_to_canvas(minirt->canvas, 0, 1, col1);
//  write_pixel_to_canvas(minirt->canvas, 1, 2, col2);
//  test_print_canvas(minirt);
//
//  int i;
//
//  i = -1;
//  while (++i < minirt->canvas->width)
//  {
//	  free(minirt->canvas->pixels[i]);
//  }
////	int i;
////	int j;
////
////	i = -1;
////	while (++i < minirt->canvas->width)
////	{
////		j = -1;
////		while (++j < minirt->canvas->height)
////		{
////			free(minirt->canvas->pixels[i][j]);
////		}
////	}
////  free(minirt->canvas->pixels);
////  free(minirt->canvas);
//  free(minirt);
//  free(col1);
//  free(col2);
//
//}
//

//void  test_write_to_ppm()
//{
//  t_canvas  *can;
//  t_color	*col;
//  int i;
//  int j;
//
//  can = canvas(640, 480);
//  col = color(1, 1, 0);
//  i = -1;
//  while (++i < can->width)
//  {
//	j = -1;
//	while (++j < can->height)
//	{
//	  write_pixel_to_canvas(can, i, j,col);
//	}
//  }
//  canvas_to_ppm(can);
//}
//



/* ================================ PROJECTILE SIMULATION =================================== */
//typedef struct	s_projectile
//{
//	t_tuple	position;
//	t_tuple	velocity;
//}	t_projectile;
//
//typedef struct	s_environment
//{
//	t_tuple	gravity;
//	t_tuple	wind;
//}	t_environment;
//
////void	free_projectile(t_projectile *p)
////{
////	free(p->position);
////	free(p->velocity);
////	free(p);
////
////}
//
//bool  is_valid_canvas_pixel(t_projectile *proj, t_canvas *can)
//{
//  if ((int)roundf(proj->position.y) > 0
//	&& (int)roundf(proj->position.y) < can->height
//	&& (int)roundf(proj->position.x) < can->width
//	&& (int)roundf(proj->position.x) > 0)
//	return (true);
//  return (false);
//}
//
//t_tuple	add_three_tuples(t_tuple *a, t_tuple *b, t_tuple *c)
//{
//	t_tuple	res;
//
//	res.x = a->x + b->x + c->x;
//	res.y = a->y + b->y + c->y;
//	res.z = a->z + b->z + c->z;
//	res.w = 0;
//	return (res);
//}
//
//t_projectile tick(t_environment *env, t_projectile *proj)
//{
//	t_projectile	res;
//	t_tuple		position;
//	t_tuple		velocity;
//
////	res = malloc(sizeof(t_projectile));
//	position = add_tuples(&proj->position, &proj->velocity);
//	velocity = add_three_tuples(&proj->velocity, &env->gravity, &env->wind);
//	res.position = position;
//	res.velocity = velocity;
////	free_projectile(proj);
//	return (res);
//}
//
//void  print_canvas(t_canvas *can)
//{
//  int x;
//  int y;
//
//  y = -1;
//  while (++y < can->height)
//  {
//	x = -1;
//	while (++x < can->width)
//	{
//	  if (can->pixels[y][x].ch[R])
//	  {
//		printf("1");
//	  }
//	  else
//		printf("0");
//	}
//	printf("\n");
//
//  }
//
//}
//
//void	test_projectile()
//{
//	t_canvas		*can;
//	t_projectile	res;
//	t_projectile	proj;
//	t_environment	env;
//	int				count;
//
//	can = canvas(900, 550);
////	res = malloc(sizeof(t_projectile));
////	proj = malloc(sizeof(t_projectile));
////	env = malloc(sizeof(t_environment));
//
//	proj.position = point(0, 1, 0);
//	t_tuple	vec = vector(1, 1.8, 0);
//	t_tuple	norm_vec = normalize_vector(&vec);
//	proj.velocity = multiply_tuple_by_scalar(&norm_vec, 11.25);
////	proj.velocity = multiply_tuple_by_scalar(normalize_vector(vector(1, 1.8, 0)), 11.25);
//	env.gravity = vector(0, -0.1, 0);
//	env.wind = vector(-0.01, 0, 0);
//	count = 0;
//	res = tick(&env, &proj);
//	t_color col = color(1, 0, 0);
//	if (is_valid_canvas_pixel(&res, can) == true)
//		write_pixel_to_canvas(can, (int)roundf(res.position.x), can->height - (int)roundf(res.position.y), &col);
//	count++;
//	printf("res position = x: %d, y: %d, z: %d w: %d\n", (int)roundf(res.position.x), (int)roundf(res.position.y), (int)roundf(res.position.z), (int)roundf(res.position.w));
////	 printf("color: %008x\n", can->pixels[(int)roundf(res->position->y)][(int)roundf(res->position->x)].rgba);
//	while ((int)roundf(res.position.y) > 0)
//	{
//		count++;
//		res = tick(&env, &res);
//	if (is_valid_canvas_pixel(&res, can) == true)
//		{
//			write_pixel_to_canvas(can, (int)roundf(res.position.x), can->height - (int)roundf(res.position.y), &col);
//			printf("res position = x: %d, y: %d, z: %d w: %d\n", (int)roundf(res.position.x), (int)roundf(res.position.y), (int)roundf(res.position.z), (int)roundf(res.position.w));
////			printf("color: %008x\n", can->pixels[(int)roundf(res->position->y)][(int)roundf(res->position->x)].rgba);
//		}
//	}
////	print_canvas(can);
//	canvas_to_ppm(can);
////	free_projectile(res);
////	free(col);
//	printf("ticks: %d\n", count);
////	return (res);
//}

//void	test_rectangle_to_ppm()
//{
//	t_canvas	*can;
//
//	can = canvas(20, 20);
//	int i = 1;
//	int	j = 1;
//	while (i < 10 )
//	{
//		j = 1;
//		while (j < 10)
//		{
//			write_pixel_to_canvas(can, j, i, color(1, 0, 0));
//			j++;
//		}
//		i++;
//	}
//	canvas_to_ppm(can);
//
//}

/* ================================ MATRIX =================================== */

void	test_print_matrix(t_matrix4 m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			printf("%.5f ", m.m[y][x]);
		}
		printf("\n");
	}
}

void	test_print_matrix3(t_matrix3 m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 3)
	{
		x = -1;
		while (++x < 3)
		{
			printf("%.1f ", m.m[y][x]);
		}
		printf("\n");
	}
}

void	test_print_matrix2(t_matrix2 m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < 2)
	{
		x = -1;
		while (++x < 2)
		{
			printf("%.1f ", m.m[y][x]);
		}
		printf("\n");
	}
}
//void	test_matrix_creation_and_indexing()
//{
//	t_matrix4	m;
//
//	m = matrix4();
//	m.m[0][0] = 1;
//	m.m[0][1] = 2;
//	m.m[0][2] = 3;
//	m.m[0][3] = 4;
//	m.m[1][0] = 5.5;
//	m.m[1][1] = 6.5;
//	m.m[1][2] = 7.5;
//	m.m[1][3] = 8.5;
//	m.m[2][0] = 9;
//	m.m[2][1] = 10;
//	m.m[2][2] = 11;
//	m.m[2][3] = 12;
//	m.m[3][0] = 13.5;
//	m.m[3][1] = 14.5;
//	m.m[3][2] = 15.5;
//	m.m[3][3] = 16.5;
//	test_print_matrix(m);
//}

//void	test_matrix4_comparison_equal()
//{
//	t_matrix4	a;
//	t_matrix4	b;
//
//	a.m[0][0] = 1;
//	a.m[0][1] = 2;
//	a.m[0][2] = 3;
//	a.m[0][3] = 4;
//	a.m[1][0] = 5;
//	a.m[1][1] = 6;
//	a.m[1][2] = 7;
//	a.m[1][3] = 8;
//	a.m[2][0] = 9;
//	a.m[2][1] = 8;
//	a.m[2][2] = 7;
//	a.m[2][3] = 6;
//	a.m[3][0] = 5;
//	a.m[3][1] = 4;
//	a.m[3][2] = 3;
//	a.m[3][3] = 2;
//
//	b.m[0][0] = 1;
//	b.m[0][1] = 2;
//	b.m[0][2] = 3;
//	b.m[0][3] = 4;
//	b.m[1][0] = 5;
//	b.m[1][1] = 6;
//	b.m[1][2] = 7;
//	b.m[1][3] = 8;
//	b.m[2][0] = 9;
//	b.m[2][1] = 8;
//	b.m[2][2] = 7;
//	b.m[2][3] = 6;
//	b.m[3][0] = 5;
//	b.m[3][1] = 4;
//	b.m[3][2] = 3;
//	b.m[3][3] = 2;
//
//	if (compare_matrix4(&a, &b))
//		printf("the matrices are equal\n");
//	else
//		printf("the matrices are unequal\n");
//}
//

//void	test_multiply_two_matrix4()
//{
//	t_matrix4	a;
//	t_matrix4	b;
//	t_matrix4	res;
//
//	a.m[0][0] = 1;
//	a.m[0][1] = 2;
//	a.m[0][2] = 3;
//	a.m[0][3] = 4;
//	a.m[1][0] = 5;
//	a.m[1][1] = 6;
//	a.m[1][2] = 7;
//	a.m[1][3] = 8;
//	a.m[2][0] = 9;
//	a.m[2][1] = 8;
//	a.m[2][2] = 7;
//	a.m[2][3] = 6;
//	a.m[3][0] = 5;
//	a.m[3][1] = 4;
//	a.m[3][2] = 3;
//	a.m[3][3] = 2;
//	
//	b.m[0][0] = -2;
//	b.m[0][1] = 1;
//	b.m[0][2] = 2;
//	b.m[0][3] = 3;
//	b.m[1][0] = 3;
//	b.m[1][1] = 2;
//	b.m[1][2] = 1;
//	b.m[1][3] = -1;
//	b.m[2][0] = 4;
//	b.m[2][1] = 3;
//	b.m[2][2] = 6;
//	b.m[2][3] = 5;
//	b.m[3][0] = 1;
//	b.m[3][1] = 2;
//	b.m[3][2] = 7;
//	b.m[3][3] = 8;
//
//	res = matrix4_multiply(&a, &b);
//	test_print_matrix(res);
//
//}
//

void	test_print_tuple(t_tuple t)
{
	printf("x: %f y: %f z: %f w: %f\n", t.x, t.y, t.z, t.w);
}

//void  test_multiply_tuple_by_matrix()
//{
//  t_matrix4   m;
//  t_tuple	t;
//  t_tuple	res;
//
//  t = point(1, 2, 3);
//  m = matrix4();
//
//  m.m[0][0] = 1;
//  m.m[0][1] = 2;
//  m.m[0][2] = 3;
//  m.m[0][3] = 4;
//  m.m[1][0] = 2;
//  m.m[1][1] = 4;
//  m.m[1][2] = 4;
//  m.m[1][3] = 2;
//  m.m[2][0] = 8;
//  m.m[2][1] = 6;
//  m.m[2][2] = 4;
//  m.m[2][3] = 1;
//  m.m[3][0] = 0;
//  m.m[3][1] = 0;
//  m.m[3][2] = 0;
//  m.m[3][3] = 1;
//
//  res = matrix4_multiply_tuple(&m, &t);
//  test_print_tuple(res);
//}

//void  test_identity_matrix()
//{
//  t_matrix4   m;
//  t_matrix4   id;
//  t_matrix4   reset;
//  t_tuple	t;
//  t_tuple	res;
//
//  m = matrix4();
//
//  m.m[0][0] = 0;
//  m.m[0][1] = 1;
//  m.m[0][2] = 2;
//  m.m[0][3] = 4;
//  m.m[1][0] = 1;
//  m.m[1][1] = 2;
//  m.m[1][2] = 4;
//  m.m[1][3] = 8;
//  m.m[2][0] = 2;
//  m.m[2][1] = 4;
//  m.m[2][2] = 8;
//  m.m[2][3] = 16;
//  m.m[3][0] = 4;
//  m.m[3][1] = 8;
//  m.m[3][2] = 16;
//  m.m[3][3] = 32;
//
//  id = id_matrix4();
//  reset = matrix4_multiply(&m, &id);
//  test_print_matrix(reset);
//
////	t = tuple(1, 2, 3, 4);
//  t = point(1, 2, 3);
//  printf("w: %f\n", t.w);
//  res = matrix4_multiply_tuple(&id, &t);
//
//  test_print_tuple(res);
//
//  printf("w: %f\n", res.w);
//}

//void  test_transpose_matrix()
//{
//  t_matrix4   m;
//  t_matrix4   res;
//
//  m.m[0][0] = 0;
//  m.m[0][1] = 9;
//  m.m[0][2] = 3;
//  m.m[0][3] = 0;
//  m.m[1][0] = 9;
//  m.m[1][1] = 8;
//  m.m[1][2] = 0;
//  m.m[1][3] = 8;
//  m.m[2][0] = 1;
//  m.m[2][1] = 8;
//  m.m[2][2] = 5;
//  m.m[2][3] = 3;
//  m.m[3][0] = 0;
//  m.m[3][1] = 0;
//  m.m[3][2] = 5;
//  m.m[3][3] = 8;
//
//  printf("before transpose\n");
//  test_print_matrix(m);
//
//  res = transpose_matrix4(m);
//  printf("afrter transpose\n");
//  test_print_matrix(res);
//
//}
//
//void  test_transpose_identity_matrix()
//{
//  t_matrix4   id;
//  t_matrix4 res;
//
//  id = id_matrix4();
//
//  printf("before transpose\n");
//  test_print_matrix(id);
//
//  res = transpose_matrix4(id);
//  printf("after transpose\n");
//  test_print_matrix(res);
//
//}

//void  test_determinent_of_2x2_matrix()
//{
//  t_matrix2   m;
//  t_float	res;
//
//  m.m[0][0] = 1;
//  m.m[0][1] = 5;
//  m.m[1][0] = -3;
//  m.m[1][1] = 2;
//
//  res = determinent_of_matrix2(&m);
//  test_print_matrix2(m);
//  printf("determinent: %f\n", res);
//}
//
//void  test_submatrix4()
//{
//  t_matrix4   m4;
//  t_matrix3   res;
//
//  m4 = matrix4();
//
//  m4.m[0][0] = -6;
//  m4.m[0][1] = 1;
//  m4.m[0][2] = 1;
//  m4.m[0][3] = 6;
//  m4.m[1][0] = -8;
//  m4.m[1][1] = 5;
//  m4.m[1][2] = 8;
//  m4.m[1][3] = 6;
//  m4.m[2][0] = -1;
//  m4.m[2][1] = 0;
//  m4.m[2][2] = 8;
//  m4.m[2][3] = 2;
//  m4.m[3][0] = -7;
//  m4.m[3][1] = 1;
//  m4.m[3][2] = -1;
//  m4.m[3][3] = 1;
//
//  printf("matrix origin:\n");
//  test_print_matrix(m4);
//  res = submatrix4(m4, 2, 1);
//  printf("submatrix:\n");
//  test_print_matrix3(res);
//}

//void  test_submatrix3()
//{
//  t_matrix3   m3;
//  t_matrix2   res;
//
//  m3 = matrix3();
//
//  m3.m[0][0] = 1;
//  m3.m[0][1] = 5;
//  m3.m[0][2] = 0;
//
//  m3.m[1][0] = -3;
//  m3.m[1][1] = 2;
//  m3.m[1][2] = 7;
//
//  m3.m[2][0] = 0;
//  m3.m[2][1] = 6;
//  m3.m[2][2] = -3;
//  printf("matrix origin:\n");
//  test_print_matrix3(m3);
//  res = submatrix3(m3 , 0, 2);
//  printf("submatrix:\n");
//  test_print_matrix2(res);
//}
//

//void  test_minor()
//{
//  t_matrix3   m;
//  t_float	res;
//
//  m = matrix3();
//
//  m.m[0][0] = 3;
//  m.m[0][1] = 5;
//  m.m[0][2] = 0;
//
//  m.m[1][0] = 2;
//  m.m[1][1] = -1;
//  m.m[1][2] = -7;
//
//  m.m[2][0] = 6;
//  m.m[2][1] = -1;
//  m.m[2][2] = 5;
//
//  test_print_matrix3(m);
//
//  res = minor(m, 1, 0);
//  printf("minor: %f\n", res);
//}

//void    test_cofactor()
//{
//    t_matrix3   m;
//    t_float     res;
//
//    m.m[0][0] = 3;
//    m.m[0][1] = 5;
//    m.m[0][2] = 0;
//
//    m.m[1][0] = 2;
//    m.m[1][1] = -1;
//    m.m[1][2] = -7;
//
//    m.m[2][0] = 6;
//    m.m[2][1] = -1;
//    m.m[2][2] = 5;
//
//    res = cofactor3(m, 0, 0);
//    printf("cofactor 0, 0 res: %f\n", res);
//    res = cofactor3(m, 1, 0);
//    printf("cofactor 1, 0 res: %f\n", res);
//    res = cofactor3(m, 2, 0);
//    printf("cofactor 2, 0 res: %f\n", res);
//
//}
//void    test_determinent()
//{
//    t_matrix3   m;
//    t_float     res;
//
//    m.m[0][0] = 1;
//    m.m[0][1] = 2;
//    m.m[0][2] = 6;
//
//    m.m[1][0] = -5;
//    m.m[1][1] = 8;
//    m.m[1][2] = -4;
//
//    m.m[2][0] = 2;
//    m.m[2][1] = 6;
//    m.m[2][2] = 4;
//
//    res = cofactor3(m, 0, 0);
//    printf("cofactor 0, 0 res: %f\n", res);
//    res = cofactor3(m, 0, 1);
//    printf("cofactor 0, 1 res: %f\n", res);
//    res = cofactor3(m, 0, 2);
//    printf("cofactor 0, 2 res: %f\n", res);
//    res = determinent_of_matrix3(m);
//    printf("determinent of 3x3 matrix is %f\n", res);
//}
//
//void    test_determinent_of_4x4_matrix()
//{
//    t_matrix4   m;
//    t_float     res;
//
//    m.m[0][0] = -2;
//    m.m[0][1] = -8;
//    m.m[0][2] = 3;
//    m.m[0][3] = 5;
//
//    m.m[1][0] = -3;
//    m.m[1][1] = 1;
//    m.m[1][2] = 7;
//    m.m[1][3] = 3;
//
//    m.m[2][0] = 1;
//    m.m[2][1] = 2;
//    m.m[2][2] = -9;
//    m.m[2][3] = 6;
//
//    m.m[3][0] = -6;
//    m.m[3][1] = 7;
//    m.m[3][2] = 7;
//    m.m[3][3] = -9;
//
//    res = determinent_of_matrix4(m);
//    printf("determinent of matrix4 is %f\n", res);
//
//}
//void	test_is_matrix_invertable()
//{
//	t_matrix4	a;
//	t_matrix4	b;
//
//	a.m[0][0] = 6;
//	a.m[0][1] = 4;
//	a.m[0][2] = 4;
//	a.m[0][3] = 4;
//	a.m[1][0] = 5;
//	a.m[1][1] = 5;
//	a.m[1][2] = 7;
//	a.m[1][3] = 6;
//	a.m[2][0] = 4;
//	a.m[2][1] = -9;
//	a.m[2][2] = 3;
//	a.m[2][3] = -7;
//	a.m[3][0] = 9;
//	a.m[3][1] = 1;
//	a.m[3][2] = 7;
//	a.m[3][3] = -6;
//
//
//	b.m[0][0] = -4;
//	b.m[0][1] = 2;
//	b.m[0][2] = -2;
//	b.m[0][3] = -3;
//	b.m[1][0] = 9;
//	b.m[1][1] = 6;
//	b.m[1][2] = 2;
//	b.m[1][3] = 6;
//	b.m[2][0] = 0;
//	b.m[2][1] = -5;
//	b.m[2][2] = 1;
//	b.m[2][3] = -5;
//	b.m[3][0] = 0;
//	b.m[3][1] = 0;
//	b.m[3][2] = 0;
//	b.m[3][3] = 0;
//
//	if (is_matrix4_invertable(a))
//		printf("matrix a is mutable\n");
//	else
//		printf("matrix a is not mutable\n");
//
//	if (is_matrix4_invertable(b))
//		printf("matrix b is mutable\n");
//	else
//		printf("matrix b is not mutable\n");
//}

//void	test_inverse_matrix4()
//{
//	t_matrix4	a;
//	t_matrix4	b;
//	t_matrix4	res1;
//	t_matrix4	res2;
//	t_matrix4	res3;
//
//	a.m[0][0] = 3;
//	a.m[0][1] = -9;
//	a.m[0][2] = 7;
//	a.m[0][3] = 3;
//
//	a.m[1][0] = 3;
//	a.m[1][1] = -8;
//	a.m[1][2] = 2;
//	a.m[1][3] = -9;
//
//	a.m[2][0] = -4;
//	a.m[2][1] = 4;
//	a.m[2][2] = 4;
//	a.m[2][3] = 1;
//
//	a.m[3][0] = -6;
//	a.m[3][1] = 5;
//	a.m[3][2] = -1;
//	a.m[3][3] = 1;
//
//
//	b.m[0][0] = 8;
//	b.m[0][1] = 2;
//	b.m[0][2] = 2;
//	b.m[0][3] = 2;
//
//	b.m[1][0] = 3;
//	b.m[1][1] = -1;
//	b.m[1][2] = 7;
//	b.m[1][3] = 0;
//
//	b.m[2][0] = 7;
//	b.m[2][1] = 0;
//	b.m[2][2] = 5;
//	b.m[2][3] = 4;
//
//	b.m[3][0] = 6;
//	b.m[3][1] = -2;
//	b.m[3][2] = 0;
//	b.m[3][3] = 5;
//
//	test_print_matrix(a);
//	printf("\n");
//	res1 = multiply_matrix4(&a, &b);
//	res2 = inverse_matrix4(b);
//	res3 = multiply_matrix4(&res1, &res2);
//	test_print_matrix(res3);
//}
//void	test_create_color_from_channels()
//{
//	t_color	test;
//
//	test = color_from_channels(255, 255, 155);
//	printf("r: %f g: %f b: %f a: %f\n", test.r, test.g, test.b, test.a);
//}
//void	test_translate()
//{
//	t_matrix4	transform;
//	t_tuple		p;
//
//	transform = translation(5, -3, 2);
//	transform = inverse_matrix4(transform);
//	p = point(-3, 4, 5);
//	p = multiply_matrix4_tuple(transform, p);
//	test_print_tuple(p);
//}
//

//void	test_scaling()
//{
//	t_matrix4	scale;
//	t_tuple		p;
//
//	scale = scaling(-1, 1, 1);
////	scale = inverse_matrix4(scale);
//	p = point(2, 3, 4);
//	p = multiply_matrix4_tuple(scale, p);
//	test_print_tuple(p);
//}

//void	test_rotations()
//{
//	t_matrix4	half_quater = rotation_z(45);
//	t_matrix4	full_quater = rotation_z(90);
//	t_tuple p = point(0, 1, 0);
////	half_quater = inverse_matrix4(half_quater);
//	t_tuple	res = multiply_matrix4_tuple(half_quater, p);
//	test_print_tuple(res);
//	res = multiply_matrix4_tuple(full_quater, p);
//	test_print_tuple(res);
//}

//void	test_shearing()
//{
//	t_matrix4	transform;
//	t_tuple		p;
//	t_float		proportions[] = {0, 0, 0, 0, 0, 1};
//	transform = shearing(proportions);
//	p = point(2, 3, 4);
//	t_tuple	res = multiply_matrix4_tuple(transform, p);
//	test_print_tuple(res);
//}

//void	test_chained_transformations()
//{
//	t_matrix4	rotx = rotation_x(90);
//	t_matrix4	scale = scaling(5,5,5);
//	t_matrix4	trans = translation(10, 5, 7);
//	t_matrix4	transform;
//	t_tuple		res;
//
//	transform = id_matrix4();
//	res = point(1, 0, 1);
//	transform = multiply_matrix4(trans, scale);
//	transform = multiply_matrix4(transform, rotx);
//	res = multiply_matrix4_tuple(transform, res);
//	test_print_tuple(res);	
//}

//void	test_clock_face()
//{
////	t_float		rot_deg;
//	t_canvas	*can;
//	t_tuple		p;
//	t_tuple		cp;
////	t_tuple		offset_centre;
//
//	can = canvas(900 / 4, 550 / 4);
////i	rot_deg = 360 / 12;
//
////	offset_centre = point(canvas->width / 2, canvas->height / 2, 0);
//
//	t_matrix4	centre_offset_matrix = translation(0, can->width / 2, can->height / 2);
//	p = point(0, 50, 0);
//	cp = multiply_matrix4_tuple(centre_offset_matrix, p);
//
//	t_color	red;
//	red = color(1, 0, 0);
//	write_pixel_to_canvas(can, (int)roundf(cp.y), (int)roundf(cp.z), &red);
//	printf("point before rotation:\n x: %f y: %f z: %f\n", p.x, p.y, p.z);
//	t_matrix4	rot_x = rotation_x(360 / 12);
////	p = multiply_matrix4_tuple(rot_x, p);
////	printf("point after rotation:\n x: %f y: %f z: %f\n", p.x, p.y, p.z);
////	cp = multiply_matrix4_tuple(centre_offset_matrix,  p);
////	write_pixel_to_canvas(can, (int)roundf(cp.y), (int)roundf(cp.z), &red);
//	int	i = -1;
//	while (++i < 11)
//	{
//		p = multiply_matrix4_tuple(rot_x, p);
//		printf("point after rotation:\n x: %f y: %f z: %f\n", p.x, p.y, p.z);
//		cp = multiply_matrix4_tuple(centre_offset_matrix,  p);
//		write_pixel_to_canvas(can, (int)roundf(cp.y), (int)roundf(cp.z), &red);
//	}
//	canvas_to_ppm(can);
//}

//void	test_create_ray()
//{
//	t_ray r;
//
//	r = ray(point(0, 1, 0), vector(1, 10, 3));
//
//	printf("ray origin x: %f y: %f z: %f\n", r.origin.x, r.origin.y, r.origin.z);
//	printf("ray direction x: %f y: %f z: %f\n", r.direction.x, r.direction.y, r.direction.z);
//}

//void	test_compute_a_point_from_a_distance()
//{
//	t_ray	r;
//	t_tuple	res;
//
//	r = ray(point(2, 3, 4), vector(1, 0, 0));
//	res = position(r, 0);
//	test_print_tuple(res);
//	res = position(r, 1);
//	test_print_tuple(res);
//	res = position(r, -1);
//	test_print_tuple(res);
//	res = position(r, 2.5);
//	test_print_tuple(res);
//
//}

//void	test_create_sphere()
//{
//	t_object	sp;
//
//	sp = sphere();
//	printf("sphere coord: %f, %f, %f,\n sphere radius: %f\n", sp.coord.x, sp.coord.y, sp.coord.z, sp.radius);
//
//
//	sp = sphere();
//	printf("sphere coord: %f, %f, %f,\n sphere radius: %f\n", sp.coord.x, sp.coord.y, sp.coord.z, sp.radius);
//}
//

//void	test_sphere_intersection_discriminant(t_minirt *rt)
//{
//	(void)rt;
//	t_intersections	res;
////	t_float	discriminant;
//	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
//
//
////	t_object	sp = sphere(point(0, 0, 0), 1);
//	// t_object sp = *(rt->object[0]);
//	res = sphere_intersection(*rt->object[0], r);
//
//	printf("t1 = %f t2 = %f count: %d\n", res.t[0], res.t[1], res.count);
//
//}
//

//void	test_ray_intersections(t_minirt *rt)
//{
//	t_object	sp;
//
//	sp = sphere(vector(0, 0, 0), 1.0);
//	t_intersection	i1 = intersection(1, sp);
//	t_intersection	i2 = intersection(2, sp);
//
//	rt->n_objs = 2;
//	rt->ts = rt_malloc(rt ,sizeof(t_intersection) * (rt->n_objs * 2));
//	rt->ts[0] = i1;
//	rt->ts[1] = i2;
//
//	printf("ts[0].t = %f ts[1].t = %f\n", rt->ts[0].t, rt->ts[1].t);
//}
//


//void	test_world_intersect(t_minirt *rt)
//{
//
//	rt->ts = rt_malloc(rt ,sizeof(t_intersection) * (rt->n_objs * 2));
//	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
//	world_intersect(rt, &r);
//	int	i;
//	i = 0;
//	while (i < rt->n_ts)
//	{
//		printf("xs: %f\n", rt->ts[i].t);
//		i++;
//	}
//}

//void	test_hit(t_minirt *rt)
//{
//	t_float	res;
//
//	res = hit(rt);
//	printf("hit is: %f\n", res);
//}

//void	test_sphere_intersection()
//{
//	t_object	s = sphere(point(0, 0, 0), 1);
//	t_ray		r = ray(point(0, 1, -5), vector(0, 0, 1));
//
//	t_intersections ts = sphere_intersection(s, r);
//	printf("t1: %f t2: %f\n", ts.t[0], ts.t[1]);
//}
//
//void	test_ray_trasformation()
//{
//	t_ray	r = ray(point(1, 2, 3), vector(0, 1, 0));
//	t_matrix4	m = translation(3, 4, 5);
//	t_ray	r2 = transform(r, m);
//	printf("r2.origin: x: %f y: %f z: %f\n", r2.origin.x, r2.origin.y, r2.origin.z);
//	printf("r2.direction: x: %f y: %f z: %f\n", r2.direction.x, r2.direction.y, r2.direction.z);
//
//	m = scaling(2, 3, 4);
//	r2 = transform(r, m);
//	printf("r2.origin: x: %f y: %f z: %f\n", r2.origin.x, r2.origin.y, r2.origin.z);
//	printf("r2.direction: x: %f y: %f z: %f\n", r2.direction.x, r2.direction.y, r2.direction.z);
//}
//void	test_set_transform()
//{
//	t_ray	r = ray(point(0, 0, -5), vector(0, 0, 1));
//	t_object	s = sphere(point(0, 0, 0), 2, color(1, 0, 0));
//	set_transform(&s, translation(5, 0, 0));
//	test_print_matrix(s.transform);
//	t_intersections res = sphere_intersection(s, r);
//	printf("res.count = %d res[0].t = %f res[1].t = %f\n",res.count, res.t[0], res.t[1]);
//}

//void	test_trace_sphere(t_minirt *rt)
//{
////	rt->objs[0].transform = scaling(1, 0.5, 1);
//	int			canvas_pixels = 100;
//	t_float		wall_size = 7.0;
//	t_wall		w = wall(point(0, 0, 10), wall_size, wall_size);
//	t_float		wall_z = w.origin.z;
//	t_canvas	can = *canvas(canvas_pixels, canvas_pixels);
//	t_float		pixel_size = wall_size / canvas_pixels;
//	t_float		half = wall_size / 2;
//	t_color		col = color(1, 0, 0);
////	t_object	shape = sphere(point(0, 0, 0), 2.0, color(1, 0, 0));
////	t_object	shape;
//	t_tuple		ray_origin = point(0, 0, -5);
//	t_tuple		position;
//	t_ray		r;
//
//	t_float	world_y;
//	t_float	world_x;
//
////	shape = rt->objs[0];
//	rt->ts =	rt_malloc(rt ,sizeof(t_intersection) * (rt->n_objs * 2));
//	int		x;
//	int		y;
//
//	y = 0;
//	while (y < canvas_pixels - 1)
//	{
//		world_y = half - pixel_size * y;
//		x = 0;
//		while (x < canvas_pixels - 1)
//		{
//			world_x = -half + pixel_size * x;
//			position = point(world_x, world_y, wall_z);
//			r = ray(ray_origin, normalize_vector(sub_tuples(position, ray_origin)));
//			world_intersect(rt, &r);
//			if (hit(rt) >= 0.f)
//			{
//				printf("hit!\n");
//				write_pixel_to_canvas(&can, x, y, &col);
//			}
//			else
//			{
//				printf("no hit\n");
//			}
//			x++;
//		}
//		y++;
//	}
//
//	canvas_to_ppm(&can);
//}

//void	test_normal_at()
//{
//	t_object	sp = sphere(point(0, 0, 0), 2.0, color(1, 0, 0));
//	set_transform(&sp, translation(0, 1, 0));
//	t_tuple res = normal_at(sp, point(0, 1.70711, -0.70711));
//
//	printf("test1\n");
//	printf("sphere normal: x: %.5f, y: %.5f z: %.5f w: %f\n", res.x, res.y, res.z, res.w);
//
//	t_matrix4	m = multiply_matrix4(scaling(1, 0.5, 1), rotation_z(36));
//	set_transform(&sp, m);
//	res = normal_at(sp, point(0, sqrt(2 / 2), -sqrt(2 / 2)));
//
//	printf("test2\n");
//	printf("sphere normal: x: %.5f, y: %.5f z: %.5f w: %f\n", res.x, res.y, res.z, res.w);
//}

//void	test_reflect_vector()
//{
//	t_tuple	v = vector(1, -1, 0);
//	t_tuple n = vector(0, 1, 0);
//	t_tuple r = reflect(v, n);
//	printf("test1\n");
//	printf("reflected vector is: x: %f y: %f z: %f w: %f\n", r.x, r.y, r.z, r.w);
//
//	v = vector(0, -1, 0);
//	n = vector(sqrt(2) / 2, sqrt(2) / 2, 0);
//	r = reflect(v, n);
//	printf("test2\n");
//	printf("reflected vector is: x: %f y: %f z: %f w: %f\n", r.x, r.y, r.z, r.w);
//}

//void	test_light_and_material()
//{
//	t_light	light = point_light(point(0, 0, 0), 1.0, color(1, 1, 1));
//	printf("light: x: %f y: %f z: %f\n", light.origin.x, light.origin.y, light.origin.z);
//	printf("color: r: %f g: %f b: %f a: %f\n", light.color.r, light.color.g, light.color.b, light.color.a);
//	t_float	p[4];
//	p[ambient] = 0.1;
//	p[diffuse] = 0.9;
//	p[specular] = 0.9;
//	p[shininess] = 200.0;
//	t_material m = material(p, color(1, 1, 1));
//	
//	printf("ambient: %f diffuse: %f specular: %f shininess %f\n", m.ambient, m.diffuse, m.specular, m.shininess);
//	printf("color: r: %f g: %f b: %f a: %f\n", m.color.r, m.color.g, m.color.b, m.color.a);
//
//	t_object	sp = sphere(point(0, 0, 0), 2.0, color(1, 0, 0));
//}

//void	test_lighting01()
//{
//	t_float	p[4];
//	p[ambient] = 0.1;
//	p[diffuse] = 0.9;
//	p[specular] = 0.9;
//	p[shininess] = 200.0;
//	t_material m = material(p, color(1, 1, 1));
//	t_tuple	v[3];
//	v[pos] = point(0, 0, 0);
//	v[eyev] = vector(0, 0, -1);
//	v[normalv] = vector(0, 0, -1);
//	t_light light = point_light(point(0, 0, -10), 1.0, color(1, 1, 1));
//
//	t_color	res = lighting(m, light, v);
//	printf("res:\n r: %f g: %f b: %f a: %f\n", res.r, res.g, res.b, res.a);
//}

//void	test_lighting02()
//{
//	t_float	p[4];
//	p[ambient] = 0.1;
//	p[diffuse] = 0.9;
//	p[specular] = 0.9;
//	p[shininess] = 200.0;
//	t_material m = material(p, color(1, 1, 1));
//	t_tuple	v[3];
//	v[pos] = point(0, 0, 0);
//	v[eyev] = vector(0, sqrt(2 / 2), sqrt(2 / 2));
//	v[normalv] = vector(0, 0, -1);
//	t_light light = point_light(point(0, 0, -10), 1.0, color(1, 1, 1));
//
//	t_color	res = lighting(m, light, v);
//	printf("res:\n r: %f g: %f b: %f a: %f\n", res.r, res.g, res.b, res.a);
//}

//void	test_lighting03()
//{
//	t_float	p[4];
//	p[ambient] = 0.1;
//	p[diffuse] = 0.9;
//	p[specular] = 0.9;
//	p[shininess] = 200.0;
//	t_material m = material(p, color(1, 1, 1));
//	t_tuple	v[3];
//	v[pos] = point(0, 0, 0);
//	v[eyev] = vector(0, 0, -1);
//	v[normalv] = vector(0, 0, -1);
//	t_light light = point_light(point(0, 0, 10), 1.0, color(1, 1, 1));
//
//	t_color	res = lighting(m, light, v);
//	printf("res:\n r: %.4f g: %.4f b: %.4f a: %.4f\n", res.r, res.g, res.b, res.a);
//}

//void	test_trace_sphere(t_minirt *rt)
//{
////	rt->objs[0].transform = scaling(1, 0.5, 1);
//	t_float		scalar = 10.0;
//	int			canvas_pixels = 100 * scalar;
//	t_float		wall_size = 7.0 * scalar;
//	t_wall		w = wall(point(0, 0, 10 * scalar), wall_size, wall_size);
//	t_float		wall_z = w.origin.z;
//	t_canvas	can = *canvas(canvas_pixels, canvas_pixels);
//	t_float		pixel_size = wall_size / canvas_pixels;
//	t_float		half = wall_size / 2;
//	t_color		col = color(1, 0, 0);
//	t_tuple		ray_origin = point(0, 0, -5 * scalar);
////	t_tuple		position;
//	t_tuple		v[3];
//	t_ray		r;
//
//	t_float		hit_point;
//
//	t_float	world_y;
//	t_float	world_x;
//
//	int		x;
//	int		y;
//
////	rt->light = point_light(point(-10 * mul, 10 * mul, -10 * mul), 1.0,  color(1, 1, 1));
//	rt->objs[0] = sphere(point(0, 0, 0), 2.0 * scalar , color(1, 0, 0));
////	rt->objs[0].transform = scaling(mul, mul, mul);
//	rt->ts =	rt_malloc(rt ,sizeof(t_intersection) * (rt->n_objs * 2));
//
//	//MATERIAL SETTINGS----------------------------------------------------------------- /*
////	rt->objs[0].material.ambient = 0.1;
//	rt->objs[0].material.ambient = 0.1;
////	rt->objs[0].material.duffuse = 0.9;
//	rt->objs[0].material.diffuse = 0.9;
////	rt->objs[0].material.specular = 0.9;
//	rt->objs[0].material.specular = 0.9;
////	rt->objs[0].material.specular = 200.0;
//	rt->objs[0].material.shininess = 200.0;	
//	//CHANGE THE COLOR OF THE OBJECT AND MATERIAL
//	t_color change_color = color(1, 0, 0.784);
//	rt->objs[0].color = change_color;
//	rt->objs[0].material.color  = change_color;
//	//LIGHT SETTINGS---------------------------------------------------------------------- /*
//	rt->light.origin = point(-10 * scalar, 10 * scalar, -10 * scalar);
//	rt->light.color = color(1, 1, 1);
//	rt->light.brightness = 1.0;
//	rt->light.color = multiply_color_by_scalar(rt->light.color, rt->light.brightness);
//
//	y = 0;
//	while (y < canvas_pixels - 1)
//	{
//		world_y = half - pixel_size * y;
//		x = 0;
//		while (x < canvas_pixels - 1)
//		{
//			world_x = -half + pixel_size * x;
//			v[pos] = point(world_x, world_y, wall_z);
//			r = ray(ray_origin, normalize_vector(sub_tuples(v[pos], ray_origin)));
//			world_intersect(rt, &r);
//			hit_point = hit(rt);
//			if (hit_point >= 0.f)
//			{
//				v[pos] = position(r,  hit_point);
//				v[normalv] = normal_at(rt->objs[0], v[pos]);
//				v[eyev] = negate_tuple(r.direction);
//				col = lighting(rt->objs[0].material, rt->light, v);
////				printf("hit!\n");
//				write_pixel_to_canvas(&can, x, y, &col);
//			}
////			else
////			{
////				printf("no hit\n");
////			}
//			x++;
//		}
//		y++;
//	}
//
//	canvas_to_ppm(&can);
//}

//void	test_trace_sphere_mlx(t_minirt *rt)
//{
////	rt->objs[0].transform = scaling(1, 0.5, 1);
//	t_float		scalar = 5.0;
//	int			canvas_pixels = 100 * scalar;
//	t_float		wall_size = 7.0 * scalar;
//	t_wall		w = wall(point(0, 0, 10 * scalar), wall_size, wall_size);
//	t_float		wall_z = w.origin.z;
////	t_canvas	can = *canvas(canvas_pixels, canvas_pixels);
//	t_float		pixel_size = wall_size / canvas_pixels;
//	t_float		half = wall_size / 2;
//	t_color		col = color(1, 0, 0);
//	t_tuple		ray_origin = point(0, 0, -5 * scalar);
////	t_tuple		position;
//	t_tuple		v[3];
//	t_ray		r;
//
//	t_float		hit_point;
//
//	t_float	world_y;
//	t_float	world_x;
//
//	int		x;
//	int		y;
//
//	mlx_start(rt, canvas_pixels, canvas_pixels);
//	color_fill(rt);
//
//	rt->objs[0] = sphere(point(0, 0, 0), 2.0 * scalar , color(1, 0, 0));
//	rt->ts =	rt_malloc(rt ,sizeof(t_intersection) * (rt->n_objs * 2));
//
//	//MATERIAL SETTINGS----------------------------------------------------------------- /*
////	rt->objs[0].material.ambient = 0.1;
//	rt->objs[0].material.ambient = 0.1;
////	rt->objs[0].material.duffuse = 0.9;
//	rt->objs[0].material.diffuse = 0.9;
////	rt->objs[0].material.specular = 0.9;
//	rt->objs[0].material.specular = 0.9;
////	rt->objs[0].material.specular = 200.0;
//	rt->objs[0].material.shininess = 200.0;	
//	//CHANGE THE COLOR OF THE OBJECT AND MATERIAL
//	t_color change_color = color(1, 0, 0.784);
//	rt->objs[0].color = change_color;
//	rt->objs[0].material.color  = change_color;
//	//LIGHT SETTINGS---------------------------------------------------------------------- /*
//	rt->light.origin = point(-10 * scalar, 10 * scalar, -10 * scalar);
//	rt->light.color = color(1, 1, 1);
//	rt->light.brightness = 1.0;
//	rt->light.color = multiply_color_by_scalar(rt->light.color, rt->light.brightness);
//
//	y = 0;
//	while (y < canvas_pixels - 1)
//	{
//		world_y = half - pixel_size * y;
//		x = 0;
//		while (x < canvas_pixels - 1)
//		{
//			world_x = -half + pixel_size * x;
//			v[pos] = point(world_x, world_y, wall_z);
//			r = ray(ray_origin, normalize_vector(sub_tuples(v[pos], ray_origin)));
//			world_intersect(rt, &r);
//			hit_point = hit(rt);
//			if (hit_point >= 0.f)
//			{
//				v[pos] = position(r,  hit_point);
//				v[normalv] = normal_at(rt->objs[0], v[pos]);
//				v[eyev] = negate_tuple(r.direction);
//				col = lighting(rt->objs[0].material, rt->light, v);
////				printf("hit!\n");
////				write_pixel_to_canvas(&can, x, y, &col);
//				mlx_put_pixel(rt->img, x, y, col.rgba);
//			}
////			else
////			{
////				printf("no hit\n");
////			}
//			x++;
//		}
//		y++;
//	}
//	mlx_loop(rt->mlx);
//	mlx_delete_image(rt->mlx, rt->img);
//	mlx_terminate(rt->mlx);
////	canvas_to_ppm(&can);
//}

//void	test_world(t_minirt *rt)
//{
//	t_world	w;
//
//	w = world(rt);
//	w.objs[0].material.ambient = 1;
//	w.objs[0].material.color = color(0.8, 1.0, 0.6);
//	w.objs[0].material.diffuse = 0.7;
//	w.objs[0].material.specular = 0.2;
//
//	w.objs[1].transform = scaling(0.5, 0.5, 0.5);
//	w.objs[1].material.ambient = 1;
//	t_color	new = color(1, 1, 1);
//	w.objs[1].color = new;
//	w.objs[1].material.color = new;
//
//	t_ray	r = ray(point(0, 0, 0.75), vector(0, 0, -1));
//	t_color	res = color_at(w, r);
//	printf("res color: r: %f g: %f b: %f\n", res.r, res.g, res.b);
//	t_color	c = w.objs[0].material.color;
//	printf("outer color: r: %f g: %f b: %f\n", c.r, c.g, c.b);
//	c = w.objs[1].material.color;
//	printf("inner color: r: %f g: %f b: %f\n", c.r, c.g, c.b);
//}

//void	test_view_transform()
//{
//	t_tuple	from = point(1, 3, 2);
//	t_tuple	to = point(4, -2, 8);
//	t_tuple	up = vector(1, 1, 0);
//
//	t_matrix4	t;
//	t = view_transform(from, to ,up);
//	test_print_matrix(t);
//}

//void	test_camera_creation()
//{
//	t_camera	cam;
//
//	cam = camera(125, 200, M_PI / 2);
//	printf("cam.h_size: %f\n", cam.dim[h]);
//	printf("cam.w_size: %f\n", cam.dim[w]);
//	printf("can.fov: %f\n", cam.fov);
//	test_print_matrix(cam.transform);
//	printf("cam pixel size: %f\n", cam.pixel_size);
//}
void	test_ray_for_pixel()
{
	t_camera	c = camera(201, 101, M_PI / 2);
	t_ray		r = ray_for_pixel(c, 100, 50);

	printf("r.origin = x: %f y: %f z: %f\n", r.origin.x, r.origin.y, r.origin.z);
	printf("r.direction = x: %f y: %f z: %f\n", r.direction.x, r.direction.y, r.direction.z);
}
int	main(int argc, char **argv)
{
//	(void)argc;
//	(void)argv;

	t_minirt rt;

	if (argc != 2)
		argc_error(argc);
	rt.objs = NULL;
	rt.full_data = NULL;
	rt.n_objs = 0;
	rt.ts = NULL;
	open_file(&rt, argv);
	test_ray_for_pixel();
	cleanup_rt(&rt);
	return (0);
}
