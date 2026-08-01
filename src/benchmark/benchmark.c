/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 11:12:30 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 14:19:57 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	int	percent;

	percent = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("Disorder: ", 2);
	ft_putnbr_fd(percent / 100, 2);
	ft_putchar_fd('.', 2);
	if (percent % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(percent % 100, 2);
	ft_putstr_fd("%\n", 2);
}

static void	print_strategy(t_strategy strategy, double disorder)
{
	ft_putstr_fd("Strategy: ", 2);
	if (strategy == STRATEGY_ADAPTIVE)
	{
		if (disorder < 0.2)
			ft_putstr_fd("Adaptive (Simple)\nComplexity: O(n^2)\n", 2);
		else if (disorder < 0.5)
			ft_putstr_fd("Adaptive (Medium)\nComplexity: O(n*sqrt(n))\n", 2);
		else
			ft_putstr_fd("Adaptive (Complex)\nComplexity: O(n log n)\n", 2);
	}
	else if (strategy == STRATEGY_SIMPLE)
		ft_putstr_fd("Simple\nComplexity: O(n^2)\n", 2);
	else if (strategy == STRATEGY_MEDIUM)
		ft_putstr_fd("Medium\nComplexity: O(n*sqrt(n))\n", 2);
	else
		ft_putstr_fd("Complex\nComplexity: O(n log n)\n", 2);
}

static void	print_count(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_operation_counts(t_stats *stats)
{
	print_count("sa", stats->counts[OP_SA]);
	print_count("sb", stats->counts[OP_SB]);
	print_count("ss", stats->counts[OP_SS]);
	print_count("pa", stats->counts[OP_PA]);
	print_count("pb", stats->counts[OP_PB]);
	print_count("ra", stats->counts[OP_RA]);
	print_count("rb", stats->counts[OP_RB]);
	print_count("rr", stats->counts[OP_RR]);
	print_count("rra", stats->counts[OP_RRA]);
	print_count("rrb", stats->counts[OP_RRB]);
	print_count("rrr", stats->counts[OP_RRR]);
}

void	print_benchmark(t_stats *stats, t_strategy strategy, double disorder)
{
	print_disorder(disorder);
	print_strategy(strategy, disorder);
	print_count("Operations", stats->total);
	print_operation_counts(stats);
}
