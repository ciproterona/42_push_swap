/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:21:03 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/29 15:31:01 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack *stack, t_node *new_node)
{
	t_node	*tail;

	if (!stack || !new_node)
		return ;
	if (!stack->head)
	{
		stack->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = stack->head->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = stack->head;
		stack->head->prev = new_node;
	}
	stack->size++;
}

void	stack_add_front(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	stack_add_back(stack, new_node);
	stack->head = new_node;
}

t_node	*stack_pop_front(t_stack *stack)
{
	t_node	*top;
	t_node	*tail;

	if (!stack || !stack->head)
		return (NULL);
	top = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		tail = top->prev;
		stack->head = top->next;
		tail->next = stack->head;
		stack->head->prev = tail;
	}
	top->next = top;
	top->prev = top;
	stack->size--;
	return (top);
}
