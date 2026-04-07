/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:39 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/07 16:40:19 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_node **a, t_node **b, t_opts *opts)
{
	int	size;

	size = get_stack_size(*a);
	if (size <= 1)
		return ;
	if (size <= 20)
		sort_simple(a, b, opts);
	else if (size <= 200)
		sort_medium(a, b, opts);
	else
		sort_complex(a, b, opts);
}
