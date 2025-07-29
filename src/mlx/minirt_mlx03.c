/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_mlx03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:21:16 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/29 16:23:39 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	function to handle mouse click by shooting a ray to get the selected
 * object
 * @param	mouse_key_t button (mouse click) in this case
 * @param	acion_t action	action taken
 * @param	modifier_key_t mods	modifier
 * #param	void * parameter to pass to funcion (in this case t_minirt *)
 */
void	handle_mouse_click(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{

	t_minirt		*rt;
	t_ray			ray;
	t_intersection	hit_point;

	rt = (t_minirt *)param;
	(void)action;
	(void)mods;
	if (mlx_is_mouse_down(rt->mlx, button))
	{
		ray = ray_for_pixel(rt->w.camera, rt->mouse_pos[x], rt->mouse_pos[y]);
		world_intersect(&rt->w, ray);
		hit_point = hit(&rt->w);
		if (hit_point.t >= 0)
		{
			rt->is_active_object = true;
			rt->active_object = hit_point.object;
			rt->active_object.index = hit_point.obj_index;
			if (rt->active_object.type == SPHERE)
				printf("active object is a sphere\n");
			if (rt->active_object.type == CUBE)
				printf("active object is a cube\n");
			if (rt->active_object.type == PLANE)
				printf("active object is a plane\n");
			if (rt->active_object.type == CYLINDER)
				printf("active object is a cylinder\n");
			printf("object index is: %d\n", rt->active_object.index);
		}
		else
		{
			rt->is_active_object = false;
			printf("no object hit\n");
		}
	}
}
