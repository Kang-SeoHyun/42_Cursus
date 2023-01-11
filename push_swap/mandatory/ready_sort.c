/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:03:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/11 17:37:14 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_check(t_info	*stack_info)
{
	int	size;
	int	check;

	size = stack_info->size_array;
	check = 0;
	while (size > 1)
	{
		if (stack_info->array[size - 1] - stack_info->array[size - 2] > 0)
			check++;
		size--;
	}
	if (check == stack_info->size_array - 1)
		exit(0);
}

int	find_max(t_info *stack_info)
{
	int		i;
	int		change;

	change = -2147483648;
	i = 0;
	while (i < stack_info->size_array)
	{
		if (change < stack_info->array[i])
			change = stack_info->array[i];
		i++;
	}
	i = 0;
	while (i < stack_info->size_array)
	{
		if (change == stack_info->array[i])
		{
			stack_info->array[i] = -2147483648;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	indexing(t_info *stack_info)
{
	int	idx;
	int	*idx_array;
	int	max_idx;

	idx_array = (int *)malloc(sizeof(int) * stack_info->size_array);
	if (!idx_array)
		print_error();
	idx = stack_info->size_array - 1;
	while (idx >= 0)
	{
		max_idx = find_max(stack_info);
		idx_array[max_idx] = idx;
		idx--;
	}
	free(stack_info->array);
	stack_info->array = idx_array;
}

void	stacking(t_info *stack_info)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < stack_info->size_array)
	{
		new = init_node(stack_info->array[i] + 1);
		push_bottom(stack_info->stack_a, new);
		i++;
	}
	stack_info->size_a = stack_info->size_array;
	stack_info->max_size = stack_info->size_array;
}
