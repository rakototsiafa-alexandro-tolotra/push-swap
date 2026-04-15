/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:11 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/15 12:17:59 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **a, t_opts *opts)
{
	swap(a);
	ft_printf("sa\n");
	if (opts && opts->bench)
		opts->ops.sa++;
}

void	sb(t_node **b, t_opts *opts)
{
	swap(b);
	ft_printf("sb\n");
	if (opts && opts->bench)
		opts->ops.sb++;
}

void	ss(t_node **a, t_node **b, t_opts *opts)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
	if (opts && opts->bench)
		opts->ops.ss++;
}
