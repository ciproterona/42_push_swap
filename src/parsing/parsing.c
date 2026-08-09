/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 21:56:09 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 15:21:19 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(t_stack *stack, int value)
{
	t_node	*current;
	int		i;

	if (!stack->head)
		return (0);
	current = stack->head;
	i = 0;
	while (i < stack->size)
	{
		if (current->value == value)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

static void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

static int	populate_stack(char **words, t_stack *stack)
{
	t_node	*node;
	int		value;
	int		i;

	i = 0;
	while (words[i])
	{
		if (!parse_integer(words[i], &value)
			|| has_duplicate(stack, value))
			return (0);
		node = stack_new_node(value);
		if (!node)
			return (0);
		stack_add_back(stack, node);
		i++;
	}
	return (1);
}

int	parse_and_populate(char *arg, t_stack *a)
{
	char	**words;
	int		success;

	words = ft_split(arg, ' ');
	if (!words || !words[0])
	{
		free_matrix(words);
		return (0);
	}
	success = populate_stack(words, a);
	free_matrix(words);
	return (success);
}
