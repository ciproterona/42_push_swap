/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eroque-d <eroque-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 14:44:45 by eroque-d          #+#    #+#             */
/*   Updated: 2026/08/01 18:57:12 by eroque-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_strategy(char *arg, t_program *program)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		program->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		program->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		program->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		program->strategy = STRATEGY_ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	handle_flag(char *arg, t_program *program)
{
	if (set_strategy(arg, program))
		return (1);
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		program->bench = 1;
		return (1);
	}
	if (arg[0] == '-' && (arg[1] < '0' || arg[1] > '9'))
		return (-1);
	return (0);
}

static int	parse_arguments(t_program *program, int argc, char **argv)
{
	int	i;
	int	flag;

	i = 1;
	while (i < argc)
	{
		flag = handle_flag(argv[i], program);
		if (flag == -1 || (flag == 0
				&& !parse_and_populate(argv[i], &program->a)))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_program	program;

	if (argc < 2)
		return (0);
	program_init(&program);
	if (!parse_arguments(&program, argc, argv))
		program_error(&program);
	if (program.a.size == 0)
	{
		program_clear(&program);
		return (0);
	}
	index_stack(&program.a);
	program.disorder = compute_disorder(&program.a);
	sort_selected(&program.a, &program.b, program.strategy, program.disorder);
	if (program.stats.write_error)
		program_error(&program);
	if (program.bench)
		print_benchmark(&program.stats, program.strategy, program.disorder);
	program_clear(&program);
	return (0);
}
