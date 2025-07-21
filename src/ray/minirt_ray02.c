/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_ray02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:54:27 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:10:56 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	helper function to add one intersection to w->ts[n] array
 * takes one intersection from xs and adds it to w->ts[n] array
 *
 * @param w			pointer to the world data struct
 * @param xs		the xs intersections to add to array
 * @param i			the object index of the intersections
 */
static	void	add_one(t_world *w, t_intersections xs, int i)
{
	w->ts[w->n_ts].t = xs.t[0];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
}

/**
 * @brief	helper function to add two intersections to w->ts[n] array
 * takes two intersections from xs and adds it to w->ts[n] array
 *
 * @param w			pointer to the world data struct
 * @param xs		the xs intersections to add to array
 * @param i			the object index of the intersections
 */
static	void	add_two(t_world *w, t_intersections xs, int i)
{
	w->ts[w->n_ts].t = xs.t[0];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[1];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
}

/**
 * @brief	helper function to add three intersections to w->ts[n] array
 * takes three intersections from xs and adds it to w->ts[n] array
 *
 * @param w			pointer to the world data struct
 * @param xs		the xs intersections to add to array
 * @param i			the object index of the intersections
 */
static	void	add_three(t_world *w, t_intersections xs, int i)
{
	w->ts[w->n_ts].t = xs.t[0];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[1];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[2];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
}

/**
 * @brief	helper function to add four intersections to w->ts[n] array
 * takes four intersections from xs and adds it to w->ts[n] array
 *
 * @param w			pointer to the world data struct
 * @param xs		the xs intersections to add to array
 * @param i			the object index of the intersections
 */
static	void	add_four(t_world *w, t_intersections xs, int i)
{
	w->ts[w->n_ts].t = xs.t[0];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[1];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[2];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
	w->ts[w->n_ts].t = xs.t[3];
	w->ts[w->n_ts].object = w->objs[i];
	w->ts[w->n_ts].obj_index = i;
	++w->n_ts;
}

/**
 * @brief	add xs intersections to a w->ts[n] array
 * takes the xs t hits and adds them to a w->ts[n] array
 * for the world intersect function
 *
 * @param w			pointer to the world data struct
 * @param xs		the xs intersections to add to array
 * @param i			the object index of the intersections
 */
void	add_intersections(t_world *w, t_intersections xs, int i)
{
	if (xs.count != 0 && xs.count == 1)
		add_one(w, xs, i);
	if (xs.count != 0 && xs.count == 2)
		add_two(w, xs, i);
	if (xs.count != 0 && xs.count == 3)
		add_three(w, xs, i);
	if (xs.count != 0 && xs.count == 4)
		add_four(w, xs, i);
}
