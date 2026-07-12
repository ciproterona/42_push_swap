/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:33:18 by eroque-d          #+#    #+#             */
/*   Updated: 2026/07/12 13:40:54 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_control
{
	t_stack	*head;
	int		size;
}	t_control;

t_stack	*stack_new_node(int value);
void	stack_init_control(t_control *ctrl);
void	stack_clear(t_control *ctrl);

void	stack_add_back(t_control *ctrl, t_stack *new_node);
void	stack_add_front(t_control *ctrl, t_stack *new_node);
t_stack	*stack_pop_front(t_control *ctrl);

// void	sa(t_control *stack_a);
// void	sb(t_control *stack_b);
// void	ss(t_control *stack_a, t_control *stack_b);
// void	pa(t_control *stack_a, t_control *stack_b);
void	pb(t_control *stack_a, t_control *stack_b);
// void	ra(t_control *stack_a);
// void	rb(t_control *stack_b);
// void	rr(t_control *stack_a, t_control *stack_b);
// void	rra(t_control *stack_a);
// void	rrb(t_control *stack_b);
// void	rrr(t_control *stack_a, t_control *stack_b);

#endif
