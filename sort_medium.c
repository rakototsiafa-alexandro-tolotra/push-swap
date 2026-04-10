/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:09:18 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/10 15:49:20 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_stack *s, t_opts *opts)
{
	int	size;
	int	chunk_size;

	index_stack(*s->a);
	size = get_stack_size(*s->a);
	chunk_size = ft_sqrt(size) * 2;
	if (chunk_size < 3)
		chunk_size = 3;
	push_chunks_to_b(s, opts, size, chunk_size);
	push_max_to_a(s->a, s->b, opts);
}
