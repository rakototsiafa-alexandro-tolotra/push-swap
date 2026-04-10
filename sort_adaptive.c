/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:39 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/10 16:14:19 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *s, t_opts *opts)
{
	int	size;

	size = get_stack_size(*s->a);
	if (size <= 1)
		return ;
	if (size <= 20)
		sort_simple(s, opts);
	else if (size <= 200)
		sort_medium(s, opts);
	else
		sort_complex(s, opts);
}
