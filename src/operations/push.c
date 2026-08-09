/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobezerr <jobezerr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 15:24:06 by jobezerr          #+#    #+#             */
/*   Updated: 2026/08/01 11:41:24 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop_front(b);
	if (node)
	{
		stack_add_front(a, node);
		emit_operation(a, OP_PA);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	node = stack_pop_front(a);
	if (node)
	{
		stack_add_front(b, node);
		emit_operation(a, OP_PB);
	}
}
