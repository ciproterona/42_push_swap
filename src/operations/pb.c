/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/12 13:23:47 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/12 13:35:15 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_control *stack_a, t_control *stack_b)
{
	t_stack	*node;

	node = stack_pop_front(stack_a);
	if (node)
		stack_add_front(stack_b, node);
	write(1, "pb\n", 3);
}
