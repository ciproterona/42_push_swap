/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:47:15 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:17:36 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(va_list args, int *counter)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_count(c, counter);
}

void	print_string(va_list args, int *counter)
{
	char	*str;

	str = va_arg(args, char *);
	ft_putstr_count(str, counter);
}
