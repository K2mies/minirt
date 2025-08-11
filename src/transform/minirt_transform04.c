/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_transform04.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:46:59 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:44:54 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to asign new position matrix
 *
 * @param p		pointer to transformation paramaters
 * @return		t_matrix4 transformation matrix
 */
static t_matrix4	assign_transform_matrix(t_view_transform_param *p)
{
	t_matrix4	m;

	m = id_matrix4();
	m.m[0][0] = p->left.x;
	m.m[0][1] = p->left.y;
	m.m[0][2] = p->left.z;
	m.m[1][0] = p->true_up.x;
	m.m[1][1] = p->true_up.y;
	m.m[1][2] = p->true_up.z;
	m.m[2][0] = p->forward.x * -1;
	m.m[2][1] = p->forward.y * -1;
	m.m[2][2] = p->forward.z * -1;
	return (m);
}

/**
 * @brief	transforms camera into a new position
 *
 * @param obj	object being intersected
 * @param ray	ray to intersect
 * @return		t_intersection	result of intersection
 */
t_matrix4	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_view_transform_param	p;
	t_matrix4				orientation;
	t_matrix4				res;

	p.forward = normalize_vector(sub_tuples(to, from));
	p.upn = normalize_vector(up);
	p.left = cross_product(p.forward, p.upn);
	p.true_up = cross_product(p.left, p.forward);
	orientation = assign_transform_matrix(&p);
	res = translation(-from.x, -from.y, -from.z);
	res = multiply_matrix4(orientation, res);
	return (res);
}
