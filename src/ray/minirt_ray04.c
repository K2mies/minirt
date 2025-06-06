/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:47:00 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/04 17:12:51 by rhvidste         ###   ########.fr       */
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
	if (p->light_dot_normal < 0)
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
 * @brief	creates and asigned a material object
 * creates, asigns and returns a material object
 * takes in third paramater an array of three tuples
 * v[pos]			t_tuple
 * v[eyev]			t_tuple
 * v[normalv]		t_tuple
 * @param m			material to be asigned
 * @param light		light to be used as source
 * @param v			array of 3 vectors needed
 * @return			t_color returned color;
 */
t_color	lighting(t_material m, t_light light, t_tuple v[3])
{
	t_lighting_param	p;
	t_color				res;
	
	apply_lighting(&p, m, light, v);
	res = add_three_colors(p.ambient, p.diffuse, p.specular);
	return (res);
}

