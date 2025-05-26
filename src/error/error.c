/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:11:35 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 13:26:12 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	rt_error(t_minirt *rt, char *msg, int err)
{
	ft_dprintf(STDERR_FILENO, "Error\n%s\n", msg);
	close_rt(rt, err);
}
