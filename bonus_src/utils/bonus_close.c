/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:59 by mpierce           #+#    #+#             */
/*   Updated: 2025/08/11 15:26:51 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/**
 * 
 * @brief Function to close miniRT in all cases
 * 
 * @param rt Main struct
 * @param ex Exit code
 * 
 */
void	close_rt(t_minirt *rt, int ex)
{
	cleanup_rt_pre(rt);
	exit(ex);
}
