/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 06:24:39 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 23:22:16 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_val_pos(t_node *stack)
{
	int		max_val;
	int		max_pos;
	int		cur_pos;

	if (!stack)
		return (0);
	max_val = stack->value;
	max_pos = 0;
	cur_pos = 0;
	while (stack)
	{
		if (stack->value > max_val)
		{
			max_val = stack->value;
			max_pos = cur_pos;
		}
		cur_pos++;
		stack = stack->next;
	}
	return (max_pos);
}

static void	update_bounds(int *lower, int *upper, int chunk_size, int size)
{
	*lower = *upper + 1;
	*upper += chunk_size;
	if (*upper >= size)
		*upper = size - 1;
}

static void	push_with_rb(t_node **a, t_node **b,
				t_opts *o, int lower, int upper)
{
	int	mid;

	mid = lower + (upper - lower) / 2;
	pb(a, b, o);
	if ((*b)->index <= mid && (*b)->next)
		rb(b, o);
}

void	push_chunks_to_b(t_node **a, t_node **b,
			t_opts *o, int size, int chunk_size)
{
	int	pushed;
	int	lower;
	int	upper;

	pushed = 0;
	lower = 0;
	upper = chunk_size - 1;
	if (upper >= size)
		upper = size - 1;
	while (pushed < size)
	{
		while (((*a)->index < lower || (*a)->index > upper) && pushed < size)
			ra(a, o);
		if ((*a)->index >= lower && (*a)->index <= upper)
		{
			push_with_rb(a, b, o, lower, upper);
			pushed++;
			if (pushed % chunk_size == 0 || pushed >= size)
				update_bounds(&lower, &upper, chunk_size, size);
		}
	}
}

void	push_max_to_a(t_node **a, t_node **b, t_opts *o)
{
	int	max_pos;
	int	size;
	int	steps;

	while (*b)
	{
		max_pos = get_max_val_pos(*b);
		size = get_stack_size(*b);
		if (max_pos <= size / 2)
		{
			while (max_pos-- > 0)
				rb(b, o);
		}
		else
		{
			steps = size - max_pos;
			while (steps-- > 0)
				rrb(b, o);
		}
		pa(b, a, o);
	}
}
