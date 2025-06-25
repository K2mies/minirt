/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray08.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:14:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/25 14:15:11 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"


//void	prepare_refraction_calculations(t_world w, t_computations *comps, t_intersection *target)
//{
//	t_obj_container	container;
//	t_object		*obj;
//	int				i;
//
//	container.n_obj = 0;
//
//	i = -1;
//	while (++i < w.n_ts)
//	{
//		obj = &w.objs[w.ts[i].obj_index];
//		if (&w.ts[i] == target)
//		{
//			comps->n[0] = get_refractive_index(&container);
//			update_container(&container, obj);
//			comps->n[1] = get_refractive_index(&container);
//			return;
//		}
//		update_container(&container, obj);
//	}
//}

void	prepare_refraction_calculations(t_world w, t_computations *comps, t_intersection *target)
{
	t_obj_container	container;
	int		i;

	(void)target;
	container.n_obj = 0;
//	hit(&w);
	i = -1;
	while (++i < w.n_ts)
	{
		if (i == w.hit_index)
		{
			if (container.n_obj <= 0)
				comps->n[0] = 1.0;
		}
		else
			comps->n[0] = get_refractive_index(&container);
		update_container(&container, &w.ts[i].object);
		if (i == w.hit_index)
		{
			if (container.n_obj <= 0)
				comps->n[1] = 1.0;
			else
				comps->n[1] = get_refractive_index(&container);
		}
	}

}
