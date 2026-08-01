/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:53:01 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/02 13:49:19 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return (0);
	stack->head = stack->head->next;
	return (1);
}

void	ra(t_stack *a)
{
	if (rotate(a))
		emit_operation(a, OP_RA);
}

void	rb(t_stack *b)
{
	if (rotate(b))
		emit_operation(b, OP_RB);
}

void	rr(t_stack *a, t_stack *b)
{
	int	a_rotated;
	int	b_rotated;

	a_rotated = rotate(a);
	b_rotated = rotate(b);
	if (a_rotated || b_rotated)
		emit_operation(a, OP_RR);
}
