/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:12:30 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/03 17:38:09 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_lower_values(t_stack *a, int value)
{
	t_node	*node;
	int		count;
	int		i;

	node = a->head;
	count = 0;
	i = 0;
	while (i < a->size)
	{
		if (node->value < value)
			count++;
		node = node->next;
		i++;
	}
	return (count);
}

void	index_stack(t_stack *a)
{
	t_node	*node;
	int		i;

	node = a->head;
	i = 0;
	while (i < a->size)
	{
		node->index = count_lower_values(a, node->value);
		node = node->next;
		i++;
	}
}
