/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:20:12 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/12 13:20:27 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	stack_init_control(t_control *ctrl)
{
	if (!ctrl)
		return ;
	ctrl->head = NULL;
	ctrl->size = 0;
}

void	stack_clear(t_control *ctrl)
{
	t_stack	*current;
	t_stack	*next_node;
	int		i;

	if (!ctrl || !ctrl->head)
		return ;
	current = ctrl->head;
	i = 0;
	while (i < ctrl->size)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		i++;
	}
	ctrl->head = NULL;
	ctrl->size = 0;
}
