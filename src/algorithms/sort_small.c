/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:12:30 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/29 09:17:08 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	if (!stack || stack->size <= 1)
		return (1);
	current = stack->head;
	i = 0;
	while (i < stack->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->prev->value;
	if (first > second && second > third)
	{
		sa(a);
		rra(a);
		return ;
	}
	if (first > second && first < third)
		sa(a);
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first > third)
		rra(a);
	else if (first < second && second > third)
	{
		sa(a);
		ra(a);
	}
}

void	sort_small(t_stack *a)
{
	if (!a || a->size <= 1 || stack_is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a);
	else
		sort_three(a);
}
