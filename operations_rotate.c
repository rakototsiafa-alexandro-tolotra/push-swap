/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:04 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/15 12:18:29 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a, t_opts *opts)
{
	rotate(a);
	ft_printf("ra\n");
	if (opts && opts->bench)
		opts->ops.ra++;
}

void	rb(t_node **b, t_opts *opts)
{
	rotate(b);
	ft_printf("rb\n");
	if (opts && opts->bench)
		opts->ops.rb++;
}

void	rr(t_node **a, t_node **b, t_opts *opts)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
	if (opts && opts->bench)
		opts->ops.rr++;
}
