/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arakotot <arakotot@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:09:43 by arakotot          #+#    #+#             */
/*   Updated: 2026/04/07 11:30:31 by arakotot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_node *stack)
{
	int	size;

	if (!stack)
		return (-1);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	get_max_pos(t_node *stack)
{
	int	max_idx;
	int	current_pos;
	int	max_pos;

	if (!stack)
		return (-1);
	max_idx = -1;
	current_pos = 0;
	max_pos = 0;
	while (stack)
	{
		if (stack->index > max_idx)
		{
			max_idx = stack->index;
			max_pos = current_pos;
		}
		current_pos++;
		stack = stack->next;
	}
	return (max_pos);
}

int	get_min_pos(t_node *stack)
{
	int	min_value;
	int	min_pos;
	int	current_pos;

	if (!stack)
		return (-1);
	min_value = stack->value;
	min_pos = 0;
	current_pos = 0;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_pos = current_pos;
		}
		stack = stack->next;
		current_pos++;
	}
	return (min_pos);
}

void	index_stack(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int	ft_sqrt(int number)
{
	int	i;

	if (!number)
		return (0);
	i = 1;
	while (i * i <= number && i <= 46340)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (i - 1);
}
