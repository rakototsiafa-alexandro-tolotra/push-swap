/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:44 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/10 15:54:59 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_simple(t_stack *s, t_opts *opts)
{
	int	size;

	size = get_stack_size(*s->a);
	if (size <= 3)
	{
		sort_small(s->a, opts, size);
		return ;
	}
	while (size > 3)
	{
		rotate_min_to_top(s->a, opts, size);
		pb(s->a, s->b, opts);
		size--;
	}
	sort_three(s->a, opts);
	insert_from_b(s->a, s->b, opts);
}
