/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:55 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/07 16:10:45 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_node **src, t_node **dest)
{
	t_node	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_node **b, t_node **a, t_opts *opts)
{
	push(b, a);
	ft_printf("pa\n");
	if (opts && opts->bench)
		opts->ops.pa++;
}

void	pb(t_node **a, t_node **b, t_opts *opts)
{
	push(a, b);
	ft_printf("pb\n");
	if (opts && opts->bench)
		opts->ops.pb++;
}
