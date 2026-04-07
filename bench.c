/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:20:19 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 23:10:16 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	total_ops(t_ops *ops)
{
	return (ops->sa + ops->sb + ops->ss + ops->pa + ops->pb
		+ ops->ra + ops->rb + ops->rr + ops->rra + ops->rrb + ops->rrr);
}

static void	write_op_line(char *label, int value)
{
	write(2, label, ft_strlen(label));
	write_int_stderr(value);
	write(2, "\t", 1);
}

static void	print_ops_detail(t_opts *opts)
{
	write(2, "[bench] ", 8);
	write_op_line("sa: ", opts->ops.sa);
	write_op_line("sb: ", opts->ops.sb);
	write_op_line("ss: ", opts->ops.ss);
	write_op_line("pa: ", opts->ops.pa);
	write_op_line("pb: ", opts->ops.pb);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
	write_op_line("ra: ", opts->ops.ra);
	write_op_line("rb: ", opts->ops.rb);
	write_op_line("rr: ", opts->ops.rr);
	write_op_line("rra: ", opts->ops.rra);
	write_op_line("rrb: ", opts->ops.rrb);
	write_op_line("rrr: ", opts->ops.rrr);
}

void	print_bench(t_opts *opts, double disorder)
{
	char	*name;
	char	*complexity;

	get_strategy_info(opts->strategy, &name, &complexity);
	print_disorder(disorder);
	write(2, "[bench] strategy: ", 18);
	write(2, name, ft_strlen(name));
	write(2, " ", 1);
	write(2, complexity, ft_strlen(complexity));
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	write_int_stderr(total_ops(&opts->ops));
	write(2, "\n", 1);
	print_ops_detail(opts);
	write(2, "\n", 1);
}
