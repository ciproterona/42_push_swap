/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:57 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/03 09:31:06 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse_sign(const char *text, int *i, long long *limit)
{
	int	sign;

	sign = 1;
	*i = 0;
	if (text[*i] == '-' || text[*i] == '+')
	{
		if (text[*i] == '-')
			sign = -1;
		(*i)++;
	}
	if (!text[*i])
		return (0);
	*limit = 2147483647LL;
	if (sign == -1)
		*limit = 2147483648LL;
	return (sign);
}

int	parse_integer(const char *text, int *value)
{
	long long	limit;
	long long	result;
	int			sign;
	int			i;
	int			digit;

	result = 0;
	sign = parse_sign(text, &i, &limit);
	if (sign == 0)
		return (0);
	while (text[i])
	{
		if (text[i] < '0' || text[i] > '9')
			return (0);
		digit = text[i] - '0';
		if (result > (limit - digit) / 10)
			return (0);
		result = result * 10 + digit;
		i++;
	}
	*value = (int)(result * sign);
	return (1);
}
