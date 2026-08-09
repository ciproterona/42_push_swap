/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 20:57:19 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/27 19:19:43 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_position;
	int		position;

	current = stack->head;
	min_value = current->value;
	min_position = 0;
	position = 0;
	while (position < stack->size)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_position = position;
		}
		current = current->next;
		position++;
	}
	return (min_position);
}

static void	rotate_to_top(t_stack *a, int position)
{
	int	size;

	size = a->size;
	if (position <= size / 2)
	{
		while (position > 0)
		{
			ra(a);
			position--;
		}
	}
	else
	{
		while (position < size)
		{
			rra(a);
			position++;
		}
	}
}

void	sort_simple(t_stack *a, t_stack *b)
{
	int	min_position;

	while (a->size > 0 && !stack_is_sorted(a))
	{
		min_position = find_min_position(a);
		rotate_to_top(a, min_position);
		if (!stack_is_sorted(a))
			pb(a, b);
	}
	while (b->size > 0)
		pa(a, b);
}
