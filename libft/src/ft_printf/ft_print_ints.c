/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ints.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:59:29 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:17:47 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_count(long n, char *base, int base_len, int *counter)
{
	if (n < 0)
	{
		ft_putchar_count('-', counter);
		n = -n;
	}
	if (n >= base_len)
		ft_putnbr_base_count(n / base_len, base, base_len, counter);
	ft_putchar_count(base[n % base_len], counter);
}

void	ft_putnbr_base_unsigned(unsigned long n, char *base,
		unsigned int base_len, int *counter)
{
	if (n >= base_len)
		ft_putnbr_base_count(n / base_len, base, base_len, counter);
	ft_putchar_count(base[n % base_len], counter);
}

void	print_int(va_list args, int *counter)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr_base_count((long)n, "0123456789", 10, counter);
}

void	print_uint(va_list args, int *counter)
{
	unsigned int	n;

	n = va_arg(args, int);
	ft_putnbr_base_unsigned((long)n, "0123456789", 10, counter);
}
