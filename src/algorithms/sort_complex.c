/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:05:13 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/30 07:26:03 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_index)
{
	int	max_bits;

	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;
	int	size;
	int	j;

	if (!a || a->size <= 1 || stack_is_sorted(a))
		return ;
	max_bits = get_max_bits(a->size - 1);
	bit = 0;
	while (bit < max_bits)
	{
		size = a->size;
		j = 0;
		while (j < size)
		{
			if (((a->head->index >> bit) & 1) == 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}
