/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color04.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 16:08:50 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/18 16:20:43 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to multply a color by a scalar
 *
 * @param tup		color to be multiplied
 * @param scalar	scaler to multiply color by
 *
 * @return		color multiplied by scalar
 */
t_color *multiply_color_by_scalar(t_color *col, float scalar)
{
    t_color *res;
    
    res = malloc(sizeof(t_color));
    res->r = col->r * scalar;
    res->g = col->g * scalar;
    res->b = col->b * scalar;
    res->a = 1.0;
    convert_rgba_to_hex(res);
    return(res);
}

/**
 * Function to multiply two colors together and return
 * a new color type as a result
 *
 * @param tupa	first color for multiplacation
 * @param tupa	fsecond color for multiplacation
 *
 * @return		new color with the multiplied values
 */
t_color *multiply_color(t_color *cola, t_color *colb)
{
    t_color *res;

    res = malloc(sizeof(t_color));
    res->r = cola->r * colb->r;
    res->g = cola->g * colb->g;
    res->b = cola->b * colb->b;
    res->a = 1.0;;
    convert_rgba_to_hex(res);
    return(res);
}
