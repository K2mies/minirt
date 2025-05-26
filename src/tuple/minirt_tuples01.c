/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_tuples01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:37:07 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/14 11:46:34 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to add two tuples together and return
 * a new tuple as a result
 *
 * @param tupa	first tuple for addition
 * @param tupa	fsecond tuple for addition
 *
 * @return		new tuple with the added values
 */
t_tuple	add_tuples(t_tuple tupa, t_tuple tupb)
{
	t_tuple	res;

	res.x = tupa.x + tupb.x;
	res.y = tupa.y + tupb.y;
	res.z = tupa.z + tupb.z;
	res.w = tupa.w + tupb.w;
	if (res.w > 1)
	{
		printf("cannot add two points together\n");
	}
	return (res);
}

/**
 * Function to subtract two tuples together and return
 * a new tuple as a result
 *
 * @param tupa	first tuple for subtraction
 * @param tupa	fsecond tuple for subtraction
 *
 * @return		new tuple with the subtracted values
 */
t_tuple	sub_tuples(t_tuple tupa, t_tuple tupb)
{
	t_tuple	res;

	res.x = tupa.x - tupb.x;
	res.y = tupa.y - tupb.y;
	res.z = tupa.z - tupb.z;
	res.w = tupa.w - tupb.w;
	return (res);
}

/**
 * Function to return a negated tuplle
 *
 * @param tup	tuple to negate
 *
 * @return		negated tuple
 */
t_tuple	negate_tuple(t_tuple tup)
{
	t_tuple	res;
	t_tuple	zero;

	zero = vector(0, 0, 0);
	res = sub_tuples(zero, tup);
	return (res);
}
