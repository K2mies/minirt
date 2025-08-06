/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray20.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:47:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 14:14:56 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	Helper function to asign ambient color to the lighting model
 * 
 *
 * @param p			pointer to the param struct for lighting()
 * @param m			matterial to be used
 * @param light		light to be used for calculation
 */
static void	calculate_ambient_color(t_lighting_param *p, t_material m,
									t_light light)
{
	p->ambient[effective] = multiply_color(m.color, light.color);
	p->ambient[effective] = multiply_color(p->ambient[effective], light.color);
	p->ambient[env] = multiply_color(p->ambient[env], light.color);
	p->ambient[env] = multiply_color_by_scalar(p->ambient[env],  p->ratio);
	p->col[ambient] = multiply_color_by_scalar(p->ambient[effective], p->ratio);
	p->col[ambient] = add_colors(p->col[ambient], p->ambient[env]);
}

/**
 * @brief	Helper function to calculate color
 * calculates the col[diffuse] and col[specular]
 *
 * @param p			pointer to the param struct for lighting()
 * @param m			matterial to be used
 * @param light		light to be used for calculation
 * @param v			array of 3 vectors needed
 */
static void	calculate_color(t_lighting_param *p, t_material m, t_light light,
							t_tuple v[3])
{
	t_float	scal[2];

	scal[a] = m.diffuse * p->light_dot_normal;
	p->col[diffuse] = multiply_color_by_scalar(p->ambient[effective] ,scal[a]);
	p->reflectv = reflect(negate_tuple(p->lightv), v[normalv]);
	p->reflect_dot_eye = dot_product(p->reflectv, v[eyev]);
	if (p->reflect_dot_eye <= 0)
		p->col[specular] = color(0, 0, 0);
	else
	{
		p->factor = pow(p->reflect_dot_eye, m.shininess);
		scal[b] = m.specular * p->factor;
		p->col[specular] = multiply_color_by_scalar(light.color, scal[b]);
	}
}

/**
 * @brief	Helper function to asign and calculate the paramaters
 * asigns all params of *p
 *
 * @param p			pointer to the param struct for lighting()
 * @param m			matterial to be used
 * @param light		light to be used for calculation
 * @param v			array of 3 vectors needed
 */
static void	apply_lighting(t_lighting_param *p, t_material m, t_light light,
						   t_tuple v[3])
{
	calculate_ambient_color(p, m, light);
	p->lightv = normalize_vector(sub_tuples(light.origin, v[pos]));
	p->light_dot_normal = dot_product(p->lightv, v[normalv]);
	if (p->light_dot_normal < 0 || p->in_shadow == true)
	{
		p->col[diffuse] = color(0, 0, 0);
		p->col[specular] = color(0, 0, 0);
	}
	else
		calculate_color(p, m, light, v);
}

/**
 * @brief	applies lighting and returns a color
 * creates, asigns and returns a col based on phong lighting model
 * third paramater is for 3 vectors
 * v[pos]			t_tuple
 * v[eyev]			t_tuple
 * v[normalv]		t_tuple
 * @param m			material to be asigned
 * @param light		light to be used as source
 * @param v			array of 3 vectors needed
 * @return			t_color returned color;
 */
t_color	lighting(t_lighting_param p, t_material m, t_light light, t_tuple v[3])
{
	t_color				res;

	if (m.has_pattern == true)
		m.color	= pattern_at(m.pattern, p.obj, v[pos]);
	apply_lighting(&p, m, light, v);
	res = add_three_colors(p.col[ambient], p.col[diffuse], p.col[specular]);
	return (res);
}

/**
 * @brief	calculates wether point is in shadow or not
 * returns true if point is in shadow and false if not.
 * @param world		world object to use
 * @param point		point in space for calculation
 * @return			bool true if in shadow, false if not.
 */
bool	is_shadowed(t_world world, t_tuple point)
{
	t_intersection	h;
	t_tuple			v;
	t_tuple			direction;
	t_float			distance;
	t_ray			r;

	v = sub_tuples(world.light.origin, point);
	distance = get_magnitude(v);
	direction = normalize_vector(v);
	r = ray(point, direction);
	world_intersect(&world, r);
	h = hit(&world);
	if (h.t >= 0 && h.t < distance)
		return (true);
	return (false);
}

