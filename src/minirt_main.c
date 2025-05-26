/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:24:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/26 16:25:43 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_minirt rt;

	(void)rt;
	(void)argv;
	if (argc != 2)
		argc_error(argc);
	open_file(&rt, argv);
	return (0);
}
