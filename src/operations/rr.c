/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:53:22 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 16:34:02 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (0);
	stack->head = stack->head->prev;
	return (1);
}

void	rra(t_stack *a)
{
	if (reverse_rotate(a))
		emit_operation(a, OP_RRA);
}

void	rrb(t_stack *b)
{
	if (reverse_rotate(b))
		emit_operation(b, OP_RRB);
}

void	rrr(t_stack *a, t_stack *b)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = reverse_rotate(a);
	b_rotated = reverse_rotate(b);
	if (a_rotated || b_rotated)
		emit_operation(a, OP_RRR);
}
