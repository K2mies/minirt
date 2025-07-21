/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray22.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:14:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:11:41 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	prepares refraction calculations using a container for objs
 *
 * @param w				pointer to world struct
 * @param comps			pointer to computations struct
 * @param target		target or (hit) intersection
 */
//void	prepare_refraction_calculations(t_world *w, t_computations *comps, t_intersection *target)
//{
//	t_obj_container	container;
//	int		i;
//
//	container.n_obj = 0;
//	comps->n[0] = 1.0f;
//	comps->n[1] = 1.0f;
//	i = -1;
//	while (++i < w->n_ts)
//	{
//		if (&w->ts[i] == target)
//		{
//			if (container.n_obj <= 0)
//				comps->n[0] = 1.0f;
//			else
//				comps->n[0] = get_refractive_index(&container);
//		}
//		update_container(&container, &w->objs[w->ts[i].obj_index]);
//		if (&w->ts[i] == target)
//		{
//			if (container.n_obj <= 0)
//				comps->n[1] = 1.0f;
//			else
//				comps->n[1] = get_refractive_index(&container);
//		}
//		printf("container count = %d\n", container.n_obj);
//	}
//}

void	prepare_refraction_calculations(t_world *w, t_computations *comps, t_intersection *target)
{
	t_obj_container	container;
	t_object		*object;
	int				i;

	container.n_obj = 0;
	comps->n[0] = 1.0f;
	comps->n[1] = 1.0f;
	i = 0;
	while (i < w->n_ts)
	{
			object = &w->objs[w->ts[i].obj_index];
//			if (&w->ts[i] == target)
			if (w->ts[i].t == target->t)
			{
				comps->n[0] = get_refractive_index(&container);
				update_container(&container, object);
				comps->n[1] = get_refractive_index(&container);
				return;
			}
			update_container(&container, object);
//			printf("container count = %d\n", container.n_obj);
			i++;
	}
}
