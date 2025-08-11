/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:11:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/08/11 15:26:51 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief General error function
 * 
 * @param rt Main struct
 * @param msg String to be printed to STDERR if not NULL
 * @param err Exit code
 * 
 */
void	rt_error(t_minirt *rt, char *msg, int err)
{
	if (msg)
		ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
	close_rt(rt, err);
}
