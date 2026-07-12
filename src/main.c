/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:44:45 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/12 13:42:15 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_stacks(t_control *a, t_control *b)
{
	t_stack	*current;
	int		i;

	ft_printf("--- STATE OF STACK ---\nSTK A (Size %d): ", a->size);
	if (a->head)
	{
		current = a->head;
		i = 0;
		while (i++ < a->size)
		{
			ft_printf("%d ", current->value);
			current = current->next;
		}
	}
	ft_printf("\nSTK B (Size %d): ", b->size);
	if (b->head)
	{
		current = b->head;
		i = 0;
		while (i++ < b->size)
		{
			ft_printf("%d ", current->value);
			current = current->next;
		}
	}
	ft_printf("\n-------------------------\n\n");
}

int	main(void)
{
	t_control	stack_a;
	t_control	stack_b;

	stack_init_control(&stack_a);
	stack_init_control(&stack_b);

	stack_add_back(&stack_a, stack_new_node(30));
	stack_add_back(&stack_a, stack_new_node(10));
	stack_add_back(&stack_a, stack_new_node(20));

	ft_printf("Initial State (Before the pb):\n");
	print_stacks(&stack_a, &stack_b);

	pb(&stack_a, &stack_b);

	ft_printf("Final State (After the pb):\n");
	print_stacks(&stack_a, &stack_b);

	stack_clear(&stack_a);
	stack_clear(&stack_b);
	return (0);
}
