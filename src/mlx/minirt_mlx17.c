/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx17.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 12:03:05 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/07 12:20:36 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	hand key ESC key press case
 * terminates mlx, does clean up and exits program
 * @param	t_minirt *rt pointer to the main data struct
 */
void	handle_esc_press(t_minirt *rt)
{
	mlx_close_window(rt->mlx);
}
