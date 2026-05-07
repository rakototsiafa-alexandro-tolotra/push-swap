/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:39 by herasoan          #+#    #+#             */
/*   Updated: 2026/05/06 12:35:10 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_adaptive(t_stack *s, t_opts *opts)
{
	int		size;
	double	disorder;


	size = get_stack_size(*s->a);
	disorder = compute_disorder(*s->a);
	if (size <= 1)
		return ;
	if (size < 20 || disorder < 0.2)
		sort_simple(s, opts);
	else if (size <= 999 || disorder < 0.5)
		sort_medium(s, opts);
	else
		sort_complex(s, opts);
}
