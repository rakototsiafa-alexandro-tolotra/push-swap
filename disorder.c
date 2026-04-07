/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:30 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/07 23:11:20 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_percent(double disorder, char *buf, int *i)
{
	int		pct_int;
	int		pct_dec;

	pct_int = (int)disorder;
	pct_dec = (int)((disorder - pct_int) * 100);
	if (pct_int >= 10)
		buf[(*i)++] = '0' + (pct_int / 10);
	buf[(*i)++] = '0' + (pct_int % 10);
	buf[(*i)++] = '.';
	buf[(*i)++] = '0' + (pct_dec / 10);
	buf[(*i)++] = '0' + (pct_dec % 10);
	buf[(*i)++] = '%';
	buf[(*i)++] = '\n';
}

static void	print_bench_prefix(char *buf, int *i)
{
	buf[(*i)++] = '[';
	buf[(*i)++] = 'b';
	buf[(*i)++] = 'e';
	buf[(*i)++] = 'n';
	buf[(*i)++] = 'c';
	buf[(*i)++] = 'h';
	buf[(*i)++] = ']';
	buf[(*i)++] = ' ';
	buf[(*i)++] = 'd';
	buf[(*i)++] = 'i';
	buf[(*i)++] = 's';
	buf[(*i)++] = 'o';
	buf[(*i)++] = 'r';
	buf[(*i)++] = 'd';
	buf[(*i)++] = 'e';
	buf[(*i)++] = 'r';
	buf[(*i)++] = ':';
	buf[(*i)++] = ' ';
}

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
	char	buf[32];
	int		i;

	i = 0;
	print_bench_prefix(buf, &i);
	print_percent(disorder, buf, &i);
	write(2, buf, i);
}
