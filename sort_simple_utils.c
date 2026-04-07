/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 06:20:31 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 23:15:12 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_node **a, t_opts *opts)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a, opts);
	else if (top > mid && mid > bot)
	{
		sa(a, opts);
		rra(a, opts);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a, opts);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a, opts);
		ra(a, opts);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a, opts);
}

void	sort_small(t_node **a, t_opts *opts, int size)
{
	if (size == 2 && (*a)->value > (*a)->next->value)
		sa(a, opts);
	else if (size == 3)
		sort_three(a, opts);
}

void	rotate_min_to_top(t_node **a, t_opts *opts, int size)
{
	int	min_pos;

	min_pos = get_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a, opts);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a, opts);
	}
}

static int	find_insert_pos(t_node *a, int val, int size_a)
{
	t_node	*tmp;
	int		pos;

	tmp = a;
	pos = 0;
	while (tmp)
	{
		if (tmp->value > val)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (size_a);
}

void	insert_from_b(t_node **a, t_node **b, t_opts *opts)
{
	int	best_pos;
	int	size_a;
	int	steps;

	while (*b)
	{
		size_a = get_stack_size(*a);
		best_pos = find_insert_pos(*a, (*b)->value, size_a);
		if (best_pos <= size_a / 2)
		{
			while (best_pos-- > 0)
				ra(a, opts);
		}
		else
		{
			steps = size_a - best_pos;
			while (steps-- > 0)
				rra(a, opts);
		}
		pa(b, a, opts);
	}
}
