/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:20:12 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/30 14:51:26 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*stack_new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_init(t_stack *stack)
{
	if (!stack)
		return ;
	stack->head = NULL;
	stack->size = 0;
	stack->stats = NULL;
}

void	stack_clear(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;
	int		i;

	if (!stack || !stack->head)
		return ;
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		i++;
	}
	stack->head = NULL;
	stack->size = 0;
}
