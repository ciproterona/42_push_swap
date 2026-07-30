/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:02:41 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/30 12:58:44 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	integer_sqrt(int number)
{
	int	i;

	if (number <= 0)
		return (0);
	i = 1;
	while (i <= number / i)
	{
		if (i == number / i && number % i == 0)
			return (i);
		i++;
	}
	return (i - 1);
}

static int	find_max_position(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_position;
	int		position;

	current = stack->head;
	max_index = current->index;
	max_position = 0;
	position = 0;
	while (position < stack->size)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_position = position;
		}
		current = current->next;
		position++;
	}
	return (max_position);
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	int	max_position;

	while (b->size > 0)
	{
		max_position = find_max_position(b);
		if (max_position <= b->size / 2)
		{
			while (max_position > 0)
			{
				rb(b);
				max_position--;
			}
		}
		else
		{
			while (max_position < b->size)
			{
				rrb(b);
				max_position++;
			}
		}
		pa(a, b);
	}
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	i;

	i = 0;
	while (a->size > 0)
	{
		if (a->head->index <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (a->head->index <= i + chunk)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int	chunk;

	if (!a || a->size <= 1 || stack_is_sorted(a))
		return ;
	if (a->size <= 100)
		chunk = integer_sqrt(a->size) * 15 / 10;
	else
		chunk = integer_sqrt(a->size) * 14 / 10;
	push_chunks(a, b, chunk);
	push_back_to_a(a, b);
}
