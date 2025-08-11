/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix08.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 12:55:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/06 14:59:10 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * @brief	apllys transforms in the correct order as stored
 * in the obj->transforms takes each transform from the obj->transforms
 * array and applys them in order of
 * obj->transforms[scale][xyz]
 * obj->transforms[rotate[[z]
 * obj->transforms[rotate[[y]
 * obj->transforms[rotate[[x]
 * obj->trasnforms[scale][xyz]
 * @param	t_object obj object to transform
 */
void	apply_transforms(t_object *obj)
{
	t_matrix4	res;

	res = obj->transforms[translate][xyz];
	res = multiply_matrix4(res, obj->transforms[rotate][z]);
	res = multiply_matrix4(res, obj->transforms[rotate][y]);
	res = multiply_matrix4(res, obj->transforms[rotate][x]);
	res = multiply_matrix4(res, obj->transforms[scale][xyz]);
//	print_matrix4(res);
	obj->transform = res;
}
