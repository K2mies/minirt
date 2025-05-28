/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 12:51:03 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 16:53:57 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	argc_error(int argc)
{
	if (argc < 2)
		ft_dprintf(STDERR_FILENO, "Error\nPlease specify file to load...\n");
	else if (argc > 2)
		ft_dprintf(STDERR_FILENO, "Error\nToo many arguments (max 1)\n");
	exit(1);
}
