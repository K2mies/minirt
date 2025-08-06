/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx04.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:24:09 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/29 16:33:46 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	function to get mouse pos x and y for mlx_cursor_hook
 * @param	double w width as a double
 * @param	double h height as a double
 * #param	void * parameter to pass to funcion (in this case t_minirt *)
 */
void	handle_mouse_move(double w, double h, void *param)
{
	t_minirt	*rt;
	int32_t		pos[2];

	rt = (t_minirt *)param;
	pos[x] = (uint32_t)w;
	pos[y] = (uint32_t)h;
	mlx_get_mouse_pos(rt->mlx, &pos[x], &pos[y]);
	rt->mouse_pos[x] = pos[x];
	rt->mouse_pos[y] = pos[y];
}
