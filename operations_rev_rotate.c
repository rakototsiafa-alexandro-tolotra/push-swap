/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:01 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/07 16:17:02 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a, t_opts *opts)
{
	rev_rotate(a);
	ft_printf("rra\n");
	if (opts && opts->bench)
		opts->ops.rra++;
}

void	rrb(t_node **b, t_opts *opts)
{
	rev_rotate(b);
	ft_printf("rrb\n");
	if (opts && opts->bench)
		opts->ops.rrb++;
}

void	rrr(t_node **a, t_node **b, t_opts *opts)
{
	rev_rotate(a);
	rev_rotate(b);
	ft_printf("rrr\n");
	if (opts && opts->bench)
		opts->ops.rrr++;
}
