/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_color05.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:25:18 by rhvidste          #+#    #+#             */
/*   Updated: 2025/06/17 15:59:15 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

/**
 * Function to create a stripe pattern object
 * based on two color values
 *
 * @param a		color a
 * @param b		color b
 * @return		t_pattern type struct
 */
t_pattern	stripe_pattern(t_color a, t_color b)
{
	t_pattern	pat;

	pat.a = a;
	pat.b = b;
	return (pat);
}

/**
 * Returns a color based on x pos on pattern
 *
 * @param pat	pointer to the pattern type
 * @param p		point to check
 * @return		t_color type struct
 */
t_color	stripe_at(t_pattern *pat, t_tuple point)
{
//	if((int)point.x % 2 == 0)
	if((int)floorf(point.x) % 2 == 0)
		return (pat->a);
	else
		return (pat->b);
}
