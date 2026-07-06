/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 19:03:01 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:45:47 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	handle_specifier(char specifier, va_list args, int *counter)
{
	if (specifier == 'c')
		print_char(args, counter);
	else if (specifier == 's')
		print_string(args, counter);
	else if (specifier == 'd' || specifier == 'i')
		print_int(args, counter);
	else if (specifier == 'u')
		print_uint(args, counter);
	else if (specifier == 'x')
		print_hex_lower(args, counter);
	else if (specifier == 'X')
		print_hex_upper(args, counter);
	else if (specifier == 'p')
		print_pointer(args, counter);
	else if (specifier == '%')
		ft_putchar_count('%', counter);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			counter;

	counter = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
		{
			fmt++;
			handle_specifier(*fmt, args, &counter);
		}
		else
			ft_putchar_count(*fmt, &counter);
		fmt++;
	}
	va_end(args);
	return (counter);
}
