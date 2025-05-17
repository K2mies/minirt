/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:59:33 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/16 15:37:22 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to convert rgba values into
 * a hexadecimal value stored inside
 * col->rgba value
 *
 * @param col		color struct to update
 */
void	convert_rgba_to_hex(t_color *col)
{
    convert_rgba_to_channels(col);
    convert_channels_to_hex(col);
}

/**
 * Function to convert a hex value into
 * r, g, b, a values stored in a col struct
 *
 * @param col		color struct to update
 */
void    convert_hex_to_rgba(t_color *col)
{
    convert_hex_to_channels(col);
    convert_channels_to_rgba(col);
}
