/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:00:42 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:17:47 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex_upper(va_list args, int *counter)
{
	unsigned int	n;

	n = va_arg(args, int);
	ft_putnbr_base_unsigned((long)n, "0123456789ABCDEF", 16, counter);
}

void	print_hex_lower(va_list args, int *counter)
{
	unsigned int	n;

	n = va_arg(args, int);
	ft_putnbr_base_unsigned((long)n, "0123456789abcdef", 16, counter);
}

void	print_pointer(va_list args, int *counter)
{
	unsigned long	n;

	n = (unsigned long)va_arg(args, void *);
	if (n == 0)
	{
		ft_putstr_count("(nil)", counter);
		return ;
	}
	ft_putstr_count("0x", counter);
	ft_putnbr_base_unsigned(n, "0123456789abcdef", 16, counter);
}
