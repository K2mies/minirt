/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:15:58 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/29 16:19:33 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	function to resize img and screen
 * @param	int32_t width
 * @param	int32_t height
 * #param	void * parameter to pass to funcion (in this case t_minirt *)
 */
void	resize_screen(int32_t width, int32_t height, void *param)
{
	t_minirt	*rt;
	rt = (t_minirt *)param;
	mlx_resize_image(rt->img, width, height);
}
