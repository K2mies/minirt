/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpierce <mpierce@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 14:20:20 by mpierce           #+#    #+#             */
/*   Updated: 2025/05/29 14:28:59 by mpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *mem, size_t old_size, size_t new_size)
{
	size_t	copy_size;
	void	*temp;

	if (new_size == 0)
	{
		free(mem);
		return (NULL);
	}
	temp = ft_calloc(1, new_size);
	if (!temp)
		return (NULL);
	if (!mem)
		return (temp);
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;
	ft_memcpy(temp, mem, copy_size);
	free(mem);
	return (temp);
}
