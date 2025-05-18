/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 13:32:26 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/13 17:04:58 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"
//static bool is_tuple_vector(t_tuple *tuple);

//static void	test_return_point(float x, float y, float z)
//{
//	t_tuple	*point;
//
//	point = point(x, y, z);
//	printf("x: %f\ny: %f\nz: %f\nw: %f\n\n", point->x, point->y, point->z, point->w);
//	free(point);
//}
//
//static void	test_return_vector(float x, float y, float z)
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
//static	void	test_is_tuple_a_vector_or_point(float x, float y, float z, float w)
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

//static void	test_if_two_floats_equivilant(float a, float b)
//{
//	if (compare_floats(a, b) == true)
//		printf("floats are equivilant\n");
//	else
//		printf("floats are not equivilant\n");
//}

//static void	test_if_two_tuples_are_equivilant()
//{
//	t_tuple	*tupa;
//	t_tuple	*tupb;
//
//	tupa = vector(10, 0.001, 10);
//	tupb = vector(10, 0.001, 10);
//
//	if (compare_tuples(tupa, tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");
//
//	tupa = vector(10, 0.0010, 10);
//	tupb = vector(10, 0.001, 10);
//
//	if (compare_tuples(tupa, tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");
//
//	tupa = vector(10, 10, 10);
//	tupb = point(10, 10, 10);
//
//	if (compare_tuples(tupa, tupb) == true)
//		printf("tuples are equivilant\n");
//	else
//		printf("tuples are not equivilant\n");	
//	free(tupa);
//	free(tupb);
//}

//void	test_add_two_tuples_together()
//{
//	t_tuple	*tupa;
//	t_tuple	*tupb;
//	t_tuple	*tupc;
//
//	tupa = point(3, -2, 5);
//	tupb = vector(-2, 3, 1);
//	tupc = add_tuples(tupa, tupb);
//
//	printf("tupc = x: %f y: %f z: %f w: %f", tupc->x, tupc->y, tupc->z, tupc->w);
//
//}

//void	test_sub_two_tuples()
//{
//	t_tuple	*tupa;
//	t_tuple	*tupb;
//	t_tuple	*tupc;
//
//	tupa = point(3, 2, 1);
//	tupb = vector(5, 6, 7);
//	tupc = sub_tuples(tupa, tupb);
//
//	printf("tupc = x: %f y: %f z: %f w: %f", tupc->x, tupc->y, tupc->z, tupc->w);
//
//}
//
//Void	test_negate_tuple()
//{
//	t_tuple	*tup;
//	t_tuple	*res;
//
//	tup = vector(1, -2, 3);
//	res = negate_tuple(tup);
//	printf("res = x: %f y: %f z: %f w: %f", res->x, res->y, res->z, res->w);
//	free(tup);
//	free(res);
//}
//
//void	test_multiply_tuple_by_scaler()
//{
//	t_tuple	*tup;
//	t_tuple	*res;
//
//	tup = point(1, -2, 3);
//	res = multiply_tuple_by_scaler(tup, 0.5);
//
//	printf("res = x: %f y: %f z: %f w: %f", res->x, res->y, res->z, res->w);
//	free(tup);
//	free(res);
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
//	float		res;
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
//	float		mag;
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
//		float		res;
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
//}i
//

//void    test_print_col(t_color *col)
//{
//	printf("rgba:                0x%08X\n\n", col->rgba);
//	printf("channel values:----------------\n");
//	printf("CH[R]:               %x\n", col->ch[R]);
//	printf("CH[G]:               %x\n", col->ch[G]);
//	printf("CH[B]:               %x\n", col->ch[B]);
//	printf("CH[A]:               %x\n", col->ch[A]);
//	printf("\n0-1 values:-------------------\n");
//	printf("r:                   %f\n", col->r);
//	printf("g:                   %f\n", col->g);
//	printf("b:                   %f\n", col->b);
//	printf("a:                   %f\n", col->a);
//	printf("\nreconstructed rgba = %08x\n", (uint32_t)((col->ch[R] << 24) | (col->ch[G] << 16) | (col->ch[B] << 8) | (col->ch[A] << 0)));
//    printf("------------------------------\n");
//    printf("\n\n");
//}
//void	test_create_color()
//{
//	t_color	*col;
//
//	col = color(1, 0, 0.796);
//    printf("initial values------------------\n");
//    test_print_col(col);
//
//    printf("convert channels to hex---------\n");
//    convert_channels_to_hex(col);
//    test_print_col(col);
//
//    printf("convert hex to rgba (they should be capped)\n");
//    convert_hex_to_rgba(col);
//    test_print_col(col);
//	free(col);
//}

//void    test_add_colors_together()
//{
//    t_color *a;
//    t_color *b;
//    t_color *res;
//
//    a = color(0.9, 0.6, 0.75);
//    b = color(0.7, 0.1, 0.25);
//
//    res = add_colors(a, b);
//    test_print_col(res);
//
//    free(a);
//    free(b);
//    free(res);
//}
//
//void    test_sub_colors()
//{
//    t_color *a;
//    t_color *b;
//    t_color *res;
//
//    a = color(0.9, 0.6, 0.75);
//    b = color(0.7, 0.1, 0.25);
//
//    res = sub_colors(a, b);
//    test_print_col(res);
//
//    free(a);
//    free(b);
//    free(res);
//}
//
//void    test_multiply_color_by_scalar()
//{
//
//    float   scalar;
//    t_color *col;
//    t_color *res;
//
//    scalar = 2;
//    col = color(0.2, 0.3, 0.4);
//
//    res = multiply_color_by_scalar(col, scalar);
//    test_print_col(res);
//
//    free(col);
//    free(res);
//}
//
//void    test_multiply_colors()
//{
//    t_color *a;
//    t_color *b;
//    t_color *res;
//
//    a = color(1, 0.2, 0.4);
//    b = color(0.9, 1, 0.1);
//    res = multiply_color(a, b);
//
//    test_print_col(res);
//
//    free(a);
//    free(b);
//    free(res);
//}

//void    test_init_canvas()
//{
////  t_minirt    *minirt;
//    t_canvas    *can;
//    int         i;
//    int         j;
//
//    can = malloc(sizeof(t_canvas));
//    can = canvas(5, 5);
//
//    i = -1;
//    while (++i < can->width)
//    {
//        j = -1;
//        while (++j < can->height)
//        {
//            printf("%08x ", can->pixels[i][j].rgba);
//        }
//        printf("\n");
//    }
//
//}

//void    test_init_minirt_data()
//{
//    t_minirt    *minirt;
//    int         i;
//    int         j;
//
//    minirt = malloc(sizeof(t_minirt));
//    minirt->canvas = canvas(6, 6);
//
//    i = -1;
//    while (++i < minirt->canvas->width)
//    {
//        j = -1;
//        while (++j < minirt->canvas->height)
//        {
//            printf("%08x ", minirt->canvas->pixels[i][j].rgba);
//        }
//        printf("\n");
//
//    }
//}

void    test_print_canvas(t_minirt *minirt)
{
    int     i;
    int     j;

    i = -1;
    while (++i < minirt->canvas->width)
    {
        j = -1;
        while (++j < minirt->canvas->height)
        {
            printf("%08x ", minirt->canvas->pixels[i][j].rgba);
        }
        printf("\n");
    }

}

void    test_color_canvas_pixel()
{
    t_minirt    *minirt;
    t_color     *col1;
    t_color     *col2;

    minirt = malloc(sizeof(t_minirt));
    minirt->canvas = canvas(4, 4);
    col1 = color(0.31, 0.57, 0.10);
    col2 = color(0.10, 0.31, 0.93);
    write_pixel_to_canvas(minirt->canvas, 0, 1, col1);
    write_pixel_to_canvas(minirt->canvas, 1, 2, col2);
    test_print_canvas(minirt);

    int i;

    i = -1;
    while (++i < minirt->canvas->width)
    {
            free(minirt->canvas->pixels[i]);
    }
//    int i;
//    int j;
//
//    i = -1;
//    while (++i < minirt->canvas->width)
//    {
//        j = -1;
//        while (++j < minirt->canvas->height)
//        {
//            free(minirt->canvas->pixels[i][j]);
//        }
//    }
//  free(minirt->canvas->pixels);
//  free(minirt->canvas);
    free(minirt);
    free(col1);
    free(col2);

}

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

    test_color_canvas_pixel();

//    test_init_minirt_data();
//    test_init_canvas();

//    test_add_colors_together();
//    test_sub_colors();
//    test_multiply_color_by_scalar();
//    test_multiply_colors();

//	test_create_color();
//	test_projectile();

//	unsigned int test;
//	test = ft_atoi_base("0xFFFFFF", 16);
//	test = ft_atoi_base("0x633D4A", 16);
//	printf("test= %u\n", test);
//	ft_puthex(test);
//	printf("hex value: %x\n", test);

//	test_get_cross_product();

//	test_get_dot_product();

//	test_normalise_vector();

//	test_get_magnitude_of_vector();

//	test_devide_tuple_by_scaler();
//	test_negate_tuple();

//	test_sub_two_tuples();
	
//	test_add_two_tuples_together();

//	test_if_two_tuples_are_equivilant();

//	test_if_two_floats_equivilant(0.231, 0.231);
//	test_if_two_floats_equivilant(0.231, 0.231);

	//test_is_tuple_a_vector_or_point(ft_atoi(argv[1]), ft_atoi(argv[2]), ft_atoi(argv[3]), ft_atoi(argv[4]));

//	test_is_tuple_a_vector_or_point(10.1, 5.0, -15.0, 0.0);
//	printf("test return vector:\n");
//	test_return_vector(10.1, 5.0, -15.0);
	
//	printf("test return point:\n");
//	test_return_point(10.1, 5.0, -15.0);
	return (0);
}
