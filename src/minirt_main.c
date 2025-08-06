/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:24:50 by mpierce           #+#    #+#             */
/*   Updated: 2025/07/25 15:05:03 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "minirt.h"

int	main(int argc, char **argv)
{
//	(void)argc;
//	(void)argv;

	t_minirt rt;

	if (argc != 2)
		argc_error(argc);
	rt.objs = NULL;
	rt.full_data = NULL;
	rt.n_objs = 0;
	rt.n_light = 0;
	rt.parsing_index = 0;
	rt.ts = NULL;
	open_file(&rt, argv);
	run_mlx(&rt);
	cleanup_rt(&rt);
	return (0);
}
