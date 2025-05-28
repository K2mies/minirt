/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object00.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:49:48 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/28 15:14:56 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	creates and returns a sphere object
 * creates a Sphere object/struct 
 * and returns the two as a struct of t_ray type with a positions
 * of 0, 0, 0 and a randomised radius between 1 and 20
 *
 * @return	t_object struct with type OBJ_SPHERE
 */
t_object	sphere(t_tuple location, t_float radius)
{
	t_object	sp;

	sp.type = SPHERE;
	sp.radius = radius;
//	sp.radius = rand() % 20 + 1;
	sp.diameter = sp.radius * 2;
	sp.origin = location;
	return (sp);
}
