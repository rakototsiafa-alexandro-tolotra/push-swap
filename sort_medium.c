/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:09:18 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 16:35:38 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_medium(t_node **a, t_node **b, t_opts *opts)
{
	int	size;
	int	chunk_size;

	index_stack(*a);
	size = get_stack_size(*a);
	chunk_size = ft_sqrt(size) * 2;
	if (chunk_size < 3)
		chunk_size = 3;
	push_chunks_to_b(a, b, opts, size, chunk_size);
	push_max_to_a(a, b, opts);
}
