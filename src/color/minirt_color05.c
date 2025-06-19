/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/17 15:59:15 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to set pattern transformation matrix
 *
 * @param pat	pointer to pattern struct
 * @param m		matrix to set
 */
void	set_pattern_transform(t_pattern *pat, t_matrix4 m)
{
	pat->transform = m;
}

/**
 * Function to create a stripe pattern object
 * based on two color values
 *
 * @param a		color a
 * @param b		color b
 * @return		t_pattern type struct
 */
t_pattern	pattern(t_color a, t_color b, int type)
{
	t_pattern	pat;

	pat.type = type;
	pat.a = a;
	pat.b = b;
	pat.transform = id_matrix4();
	return (pat);
}

/**
 * determints which pattern at object fucntion will be called
 *
 * @param pattern			the pattern to operate on
 * @param obj				the object to operate on
 * @param world_point		the world point to be converted to pattern point
 * @return					t_color type struct
 */
t_color	pattern_at(t_pattern pat, t_object obj, t_tuple world_point)
{
	t_color	res;
	if (obj.material.pattern.type == STRIPE)
		res = stripe_at_object(pat, obj, world_point);
	if (obj.material.pattern.type == GRADIENT)
		res = gradient_at_object(pat, obj, world_point);
	if (obj.material.pattern.type == RING)
		res = ring_at_object(pat, obj, world_point);
	if (obj.material.pattern.type == CHECKER)
		res = checker_at_object(pat, obj, world_point);
	return (res);
}
