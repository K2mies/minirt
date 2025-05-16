/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhvidste <rhvidste@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:36:32 by rhvidste          #+#    #+#             */
/*   Updated: 2025/05/15 15:44:32 by rhvidste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_puthex(unsigned int n)
{
	char	hex_digits[] = "0123456789abcdef";
	if (n >= 16)
		ft_puthex(n / 16);
	write (1, &hex_digits[n % 16], 1);
}
