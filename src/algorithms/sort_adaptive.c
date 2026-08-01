/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:49:03 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 13:37:48 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static double	count_mistakes(t_node *node, int remaining)
{
	double	mistakes;
	t_node	*next;

	mistakes = 0.0;
	next = node->next;
	while (remaining > 0)
	{
		if (node->value > next->value)
			mistakes += 1.0;
		next = next->next;
		remaining--;
	}
	return (mistakes);
}

double	compute_disorder(t_stack *a)
{
	t_node	*node;
	double	mistakes;
	int		i;

	if (!a || a->size <= 1)
		return (0.0);
	mistakes = 0.0;
	node = a->head;
	i = 0;
	while (i < a->size - 1)
	{
		mistakes += count_mistakes(node, a->size - i - 1);
		node = node->next;
		i++;
	}
	return (mistakes / ((double)a->size * (a->size - 1) / 2.0));
}

void	sort_adaptive(t_stack *a, t_stack *b, double disorder)
{
	if (disorder == 0.0)
		return ;
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}

void	sort_selected(t_stack *a, t_stack *b, t_strategy strategy,
		double disorder)
{
	if (a->size <= 3)
		sort_small(a);
	else if (strategy == STRATEGY_SIMPLE)
		sort_simple(a, b);
	else if (strategy == STRATEGY_MEDIUM)
		sort_medium(a, b);
	else if (strategy == STRATEGY_COMPLEX)
		sort_complex(a, b);
	else
		sort_adaptive(a, b, disorder);
}
