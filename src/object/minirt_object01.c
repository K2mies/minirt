/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_object01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 12:38:29 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/03 14:32:08 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

t_wall	wall(t_tuple origin, t_float width, t_float height)
{
	t_wall	w;

	w.origin = origin;
	w.width = width;
	w.height = height;
	return (w);
}
