/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jobezerr <jobezerr@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 14:12:30 by jobezerr          #+#    #+#             */
/*   Updated: 2026/08/03 11:59:21 by jobezerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*operation_text(t_operation operation)
{
	if (operation == OP_SA)
		return ("sa\n");
	if (operation == OP_SB)
		return ("sb\n");
	if (operation == OP_SS)
		return ("ss\n");
	if (operation == OP_PA)
		return ("pa\n");
	if (operation == OP_PB)
		return ("pb\n");
	if (operation == OP_RA)
		return ("ra\n");
	if (operation == OP_RB)
		return ("rb\n");
	if (operation == OP_RR)
		return ("rr\n");
	if (operation == OP_RRA)
		return ("rra\n");
	if (operation == OP_RRB)
		return ("rrb\n");
	return ("rrr\n");
}

static size_t	operation_length(t_operation operation)
{
	if (operation == OP_RRA || operation == OP_RRB || operation == OP_RRR)
		return (4);
	return (3);
}

static int	write_operation(char *text, size_t length)
{
	ssize_t	written;
	size_t	offset;

	offset = 0;
	while (offset < length)
	{
		written = write(1, text + offset, length - offset);
		if (written <= 0)
			return (0);
		offset += written;
	}
	return (1);
}

void	emit_operation(t_stack *stack, t_operation operation)
{
	t_stats	*stats;

	stats = NULL;
	if (stack)
		stats = stack->stats;
	if (stats && stats->write_error)
		return ;
	if (stats)
	{
		stats->counts[operation]++;
		stats->total++;
	}
	if (!write_operation(operation_text(operation),
			operation_length(operation)) && stats)
		stats->write_error = 1;
}
