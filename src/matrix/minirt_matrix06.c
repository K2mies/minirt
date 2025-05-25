/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_matrix06.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.email.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:33:35 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/25 19:39:40 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minirt.h"

bool    is_matrix4_invertable(t_matrix4 m)
{
    if (determinent_of_matrix4(m) == 0)
        return (false);
    return (true);
}
