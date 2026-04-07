/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:08:27 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/07 17:01:41 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_blank_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

static void	validate_token(t_node **a, char **matrix, int i)
{
	long	nb;

	if (!is_numeric(matrix[i]))
		error_exit(a, matrix);
	nb = ft_atol(matrix[i]);
	if (nb > INT_MAX || nb < INT_MIN)
		error_exit(a, matrix);
	if (check_duplicate(*a, (int)nb))
		error_exit(a, matrix);
	append_node(a, (int)nb);
}

static void	process_strings(t_node **a, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		validate_token(a, matrix, i);
		i++;
	}
}

static void	process_arg(t_node **a, char *arg)
{
	char	**matrix;

	if (is_blank_string(arg))
		return ;
	matrix = ft_split(arg, ' ');
	if (!matrix)
		error_exit(a, NULL);
	if (!matrix[0])
	{
		free_matrix(matrix);
		return ;
	}
	process_strings(a, matrix);
	free_matrix(matrix);
}

void	parse_arguments(t_node **a, int *argc, char ***argv, t_opts *opts)
{
	int	i;

	parse_flags(argc, argv, opts);
	if (*argc == 1)
		return ;
	i = 1;
	while (i < *argc)
	{
		process_arg(a, (*argv)[i]);
		i++;
	}
}
