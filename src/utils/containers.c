/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:38:59 by rhvidste          #+#    #+#             */
/*   Updated: 2025/07/21 13:12:25 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * @brief	checks if obj is present, if not then it adds it to the array
 *
 * @param containter	pointer to the container to use
 * @param obj			pointer to the obj to check or update
 */
void	update_container(t_obj_container *container, t_object *obj)
{
	int	index;
	if (is_inside_container(container, obj, &index))
	{
		remove_from_container(container, index);
	}
	else
		add_to_container(container, obj);
}

/**
 * @brief	checks if obj is present inside the array at a certain index
 *
 * @param containter	pointer to the container to use
 * @param obj			pointer to the obj to check the presense
 * @param index			pointer to the obj to the index of the obj
 * @return				true if the object is present, false if not
 */
bool	is_inside_container(t_obj_container *container,
						 t_object *obj, int *index)
{
	int	i;

	i = 0;
	while (i < container->n_obj)
	{
		if (container->objs[i] == obj)
		{
			*index = i;
			return (true);
		}
		i++;
	}
	return (false);
}

/**
 * @brief	removes object from the container array and updates n_obj
 *
 * @param containter	pointer to the container to remove from
 * @param index			index of the object to remove
 */
void	remove_from_container(t_obj_container *container, int index)
{
	int	i;
	i = index;
	while (i < container->n_obj - 1)
	{
		container->objs[i] = container->objs[i + 1];
		i++;
	}
	if (container->n_obj > 0)
		container->n_obj--;
}

/**
 * @brief	adds object to container array and updates n_obj variable
 *
 * @param containter	pointer to the container to use
 * @param obj			pointer to the object to be added to array
 */
void	add_to_container(t_obj_container *container, t_object *obj)
{
	if (container->n_obj >= MAX_CONTAINERS)
		return ;
	container->objs[container->n_obj] = obj;
	container->n_obj++;
}

/**
 * @brief	gets the refractive index from last object in container
 * gets the refractive index from the last object in the container
 *
 * @param containter	pointer to the container to use
 * @return				returns refractive index for last object
 */
t_float	get_refractive_index(t_obj_container *container)
{
	int	count;

	count = container->n_obj - 1;
	if (count <= 0)
		return (1.0f);
	if (!container->objs[count])
		return (1.0f);
	else
		return (container->objs[count]->material.refractive_index);
}
