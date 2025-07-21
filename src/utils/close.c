/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:04:59 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/21 13:12:23 by mpierce          ###   ########.fr       */
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
	cleanup_rt(rt);
	exit(ex);
}
