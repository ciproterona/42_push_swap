/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 11:58:14 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 13:32:45 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	program_init(t_program *program)
{
	int	i;

	stack_init(&program->a);
	stack_init(&program->b);
	i = 0;
	while (i < OP_COUNT)
	{
		program->stats.counts[i] = 0;
		i++;
	}
	program->stats.total = 0;
	program->stats.write_error = 0;
	program->a.stats = &program->stats;
	program->b.stats = &program->stats;
	program->strategy = STRATEGY_ADAPTIVE;
	program->bench = 0;
	program->disorder = 0.0;
}

void	program_clear(t_program *program)
{
	stack_clear(&program->a);
	stack_clear(&program->b);
}

void	program_error(t_program *program)
{
	program_clear(program);
	write(2, "Error\n", 6);
	exit(1);
}
