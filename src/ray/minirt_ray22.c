/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray22.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:14:53 by rhvidste          #+#    #+#             */
/*   Updated: 2025/08/11 13:45:52 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	prepare computations for refraction
 *
 * @param t_world			*w pointer to the world struct to calculate for
 * @param t_computations	*comps pointer to computation struct
 * @param t_intersection	*target pointer to target intersEction
 */
void	prepare_refraction_calculations(t_world *w, t_computations *comps,
									t_intersection *target)
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
		if (w->ts[i].t == target->t)
		{
			comps->n[0] = get_refractive_index(&container);
			update_container(&container, object);
			comps->n[1] = get_refractive_index(&container);
			return ;
		}
		update_container(&container, object);
		i++;
	}
}
