/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:20:32 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/27 12:21:52 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	validate_size(char **data, int size)
{
	int	i;

	i = -1;
	while (data[++i])
		;
	if (i != size)
		return (false);
	return (true);
}
