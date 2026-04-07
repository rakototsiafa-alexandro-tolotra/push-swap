/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:46:34 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 22:34:45 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_strategy_info(t_strategy strat, char **name, char **complexity)
{
	if (strat == STRATEGY_SIMPLE)
	{
		*name = "Simple /";
		*complexity = "O(n^2)";
	}
	else if (strat == STRATEGY_MEDIUM)
	{
		*name = "Medium /";
		*complexity = "O(n√n)";
	}
	else if (strat == STRATEGY_COMPLEX)
	{
		*name = "Complex /";
		*complexity = "O(n log n)";
	}
	else
	{
		*name = "Adaptive /";
		*complexity = "O(n√n)";
	}
}

void	write_int_stderr(int n)
{
	char	buf[12];
	int		i;

	if (n == 0)
	{
		write(2, "0", 1);
		return ;
	}
	i = 11;
	buf[i--] = '\0';
	while (n > 0 && i >= 0)
	{
		buf[i--] = '0' + (n % 10);
		n /= 10;
	}
	write(2, &buf[i + 1], 11 - i - 1);
}
