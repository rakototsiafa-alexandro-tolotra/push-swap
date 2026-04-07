/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 15:03:56 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 16:47:35 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_flags(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (1);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (1);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (1);
	if (ft_strncmp(arg, "--bench", 8) == 0)
		return (1);
	return (0);
}

static void	apply_flag(char *arg, t_opts *opts)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		opts->strategy = STRATEGY_SIMPLE;
	else if (ft_strncmp(arg, "--medium", 9) == 0)
		opts->strategy = STRATEGY_MEDIUM;
	else if (ft_strncmp(arg, "--complex", 10) == 0)
		opts->strategy = STRATEGY_COMPLEX;
	else if (ft_strncmp(arg, "--adaptive", 11) == 0)
		opts->strategy = STRATEGY_ADAPTIVE;
	else if (ft_strncmp(arg, "--bench", 8) == 0)
		opts->bench = 1;
}

void	parse_flags(int *argc, char ***argv, t_opts *opts)
{
	while (*argc > 1 && is_strategy_flags((*argv)[1]))
	{
		apply_flag((*argv)[1], opts);
		(*argv)++;
		(*argc)--;
	}
}
