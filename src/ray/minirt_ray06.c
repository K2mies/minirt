/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray06.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:47:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/17 16:32:49 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	Helper function to asign and calculate the paramaters
 * asigns all params of *p in order to keep the
 * line count of lighting() below 25;
 *
 * @param p			pointer to the param struct for lighting()
 * @param m			matterial to be used
 * @param light		light to be used for calculation
 * @param v			array of 3 vectors needed
 */
static void	apply_lighting(t_lighting_param *p, t_material m, t_light light, t_tuple v[3])
{
	p->effective_color = multiply_color(m.color, light.color);
	p->lightv = normalize_vector(sub_tuples(light.origin, v[pos]));
	p->ambient = multiply_color_by_scalar(p->effective_color, m.ambient);
	p->light_dot_normal = dot_product(p->lightv, v[normalv]);
	if (p->light_dot_normal < 0 || p->in_shadow == true)
	{
		p->diffuse = color(0, 0, 0);
		p->specular = color(0, 0, 0);
	}
	else
	{
		p->diffuse = multiply_color_by_scalar(
			p->effective_color ,(m.diffuse * p->light_dot_normal));
		p->reflectv = reflect(negate_tuple(p->lightv), v[normalv]);
		p->reflect_dot_eye = dot_product(p->reflectv, v[eyev]);
		if (p->reflect_dot_eye <= 0)
			p->specular = color(0, 0, 0);
		else
		{
			p->factor = pow(p->reflect_dot_eye, m.shininess);
			p->specular = multiply_color_by_scalar(
				light.color, (m.specular * p->factor));
		}
	}
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
//	t_lighting_param	p;
	t_color				res;

	if (m.has_pattern == true)
		m.color	= pattern_at(m.pattern, p.obj, v[pos]);
//		m.color = stripe_at_object(m.pattern, p.obj, v[pos]);
	apply_lighting(&p, m, light, v);
	res = add_three_colors(p.ambient, p.diffuse, p.specular);
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

