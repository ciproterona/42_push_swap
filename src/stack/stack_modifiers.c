/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:21:03 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/12 13:21:16 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_control *ctrl, t_stack *new_node)
{
	t_stack	*tail;

	if (!ctrl || !new_node)
		return ;
	if (!ctrl->head)
	{
		ctrl->head = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
	}
	else
	{
		tail = ctrl->head->prev;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = ctrl->head;
		ctrl->head->prev = new_node;
	}
	ctrl->size++;
}

void	stack_add_front(t_control *ctrl, t_stack *new_node)
{
	if (!ctrl || !new_node)
		return ;
	stack_add_back(ctrl, new_node);
	ctrl->size--;
	ctrl->head = new_node;
	ctrl->size++;
}

t_stack	*stack_pop_front(t_control *ctrl)
{
	t_stack	*top;
	t_stack	*tail;

	if (!ctrl || !ctrl->head)
		return (NULL);
	top = ctrl->head;
	if (ctrl->size == 1)
		ctrl->head = NULL;
	else
	{
		tail = top->prev;
		ctrl->head = top->next;
		tail->next = ctrl->head;
		ctrl->head->prev = tail;
	}
	top->next = top;
	top->prev = top;
	ctrl->size--;
	return (top);
}
