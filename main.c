/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:55:56 by arakotot          #+#    #+#             */
/*   Updated: 2026/03/23 19:00:00 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	is_empty_input(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argc == 2 && argv[1][0] == '\0')
		return (1);
	return (0);
}

static void	run_strategy(t_stack *s, t_opts *opts)
{
	if (opts->strategy == STRATEGY_SIMPLE)
		sort_simple(s, opts);
	else if (opts->strategy == STRATEGY_MEDIUM)
		sort_medium(s, opts);
	else if (opts->strategy == STRATEGY_COMPLEX)
		sort_complex(s, opts);
	else
		sort_adaptive(s, opts);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_opts	opts;
	t_stack	s;
	double	disorder;

	if (is_empty_input(argc, argv))
		return (0);
	ft_memset(&opts, 0, sizeof(t_opts));
	opts.strategy = STRATEGY_ADAPTIVE;
	stack_a = NULL;
	stack_b = NULL;
	parse_arguments(&stack_a, &argc, &argv, &opts);
	if (!stack_a)
		return (0);
	s.a = &stack_a;
	s.b = &stack_b;
	disorder = compute_disorder(stack_a);
	if (!is_sorted(stack_a))
		run_strategy(&s, &opts);
	if (opts.bench)
		print_bench(&opts, disorder);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
