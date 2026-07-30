/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:33:18 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/02 13:46:38 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum e_operation
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operation;

typedef enum e_strategy
{
	STRATEGY_ADAPTIVE,
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX
}	t_strategy;

typedef struct s_stats
{
	int	counts[OP_COUNT];
	int	total;
	int	write_error;
}	t_stats;

typedef struct s_stack
{
	t_node		*head;
	int			size;
	t_stats		*stats;
}	t_stack;

typedef struct s_program
{
	t_stack		a;
	t_stack		b;
	t_stats		stats;
	t_strategy	strategy;
	int			bench;
	double		disorder;
}	t_program;

t_node	*stack_new_node(int value);
void	stack_init(t_stack *stack);
void	stack_clear(t_stack *stack);
void	stack_add_back(t_stack *stack, t_node *new_node);
void	stack_add_front(t_stack *stack, t_node *new_node);
t_node	*stack_pop_front(t_stack *stack);

double	compute_disorder(t_stack *a);
int		stack_is_sorted(t_stack *stack);
void	sort_small(t_stack *a);
void	sort_adaptive(t_stack *a, t_stack *b, double disorder);
void	sort_selected(t_stack *a, t_stack *b, t_strategy strategy,
			double disorder);
void	sort_simple(t_stack *a, t_stack *b);
void	sort_medium(t_stack *a, t_stack *b);
void	sort_complex(t_stack *a, t_stack *b);

void	emit_operation(t_stack *stack, t_operation operation);
void	print_benchmark(t_stats *stats, t_strategy strategy, double disorder);

void	program_init(t_program *program);
void	program_clear(t_program *program);
void	program_error(t_program *program);

int		parse_and_populate(char *arg, t_stack *a);
int		parse_integer(const char *text, int *value);
void	index_stack(t_stack *a);

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif
