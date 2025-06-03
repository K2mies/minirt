/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:39:44 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/02 17:04:33 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_ray transform(t_ray r, t_matrix4 m)
{
	t_ray	res;

	res.origin = multiply_matrix4_tuple(m, r.origin);
	res.direction = multiply_matrix4_tuple(m, r.direction);
	return (res);
}

//void	set_transform(t_object s, t_matrix4 m)
//{
//	s.transform = id_matrix4();
//}
