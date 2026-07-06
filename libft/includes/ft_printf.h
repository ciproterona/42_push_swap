/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/18 18:55:35 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/02 13:09:22 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *fmt, ...);

void	ft_putchar_count(char c, int *counter);
void	ft_putstr_count(char *str, int *counter);
void	ft_putnbr_base_count(long n, char *base, int base_len, int *counter);
void	ft_putnbr_base_unsigned(unsigned long n, char *base,
			unsigned int base_len, int *counter);

void	print_char(va_list args, int *counter);
void	print_string(va_list args, int *counter);
void	print_int(va_list args, int *counter);
void	print_uint(va_list args, int *counter);
void	print_hex_upper(va_list args, int *counter);
void	print_hex_lower(va_list args, int *counter);
void	print_pointer(va_list args, int *counter);

#endif // FT_PRINTF_H
