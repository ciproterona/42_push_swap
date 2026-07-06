/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 15:02:43 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 12:17:47 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c, int *counter)
{
	ft_putchar_fd(c, 1);
	(*counter)++;
}

void	ft_putstr_count(char *str, int *counter)
{
	int	len;

	if (!str)
		str = "(null)";
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	*counter += len;
}
