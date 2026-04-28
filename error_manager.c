/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 10:07:38 by herasoan          #+#    #+#             */
/*   Updated: 2026/04/28 10:08:56 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !stack[0])
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix || !*matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	error_exit(t_node **a, char **matrix)
{
	if (a && *a)
		free_stack(a);
	if (matrix)
		free_matrix(matrix);
	write(2, "Error\n", 6);
	exit(1);
}
