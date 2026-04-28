/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/28 10:10:27 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_node *stack_a)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;

	if (!stack_a || !stack_a->next)
		return (0.0);
	mistakes = 0.0;
	total_pairs = 0.0;
	i = stack_a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0.0)
		return (0.0);
	return (mistakes / total_pairs * 100.0);
}

void	print_disorder(double disorder)
{
	char	buf[128];
	int		i;
	int		pct_int;
	int		pct_dec;

	i = 0;
	i += ft_strlcpy(buf + i, "[bench] disorder: ", 128 - i);
	pct_int = (int)disorder;
	if (pct_int >= 100)
		buf[i++] = '0' + pct_int / 100;
	if (pct_int >= 10)
		buf[i++] = '0' + (pct_int / 10) % 10;
	buf[i++] = '0' + pct_int % 10;
	pct_dec = (int)((disorder - (double)pct_int) * 100 + 0.5);
	buf[i++] = '.';
	buf[i++] = '0' + (pct_dec / 10);
	buf[i++] = '0' + (pct_dec % 10);
	buf[i++] = '%';
	buf[i++] = '\n';
	write(2, buf, i);
}
