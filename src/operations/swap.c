/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobezerr <jobezerr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 21:52:42 by jobezerr          #+#    #+#             */
/*   Updated: 2026/03/02 10:14:47 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return (0);
	first = stack_pop_front(stack);
	second = stack_pop_front(stack);
	stack_add_front(stack, first);
	stack_add_front(stack, second);
	return (1);
}

void	sa(t_stack *a)
{
	if (swap(a))
		emit_operation(a, OP_SA);
}

void	sb(t_stack *b)
{
	if (swap(b))
		emit_operation(b, OP_SB);
}

void	ss(t_stack *a, t_stack *b)
{
	int	a_swapped;
	int	b_swapped;

	a_swapped = swap(a);
	b_swapped = swap(b);
	if (a_swapped || b_swapped)
		emit_operation(a, OP_SS);
}
