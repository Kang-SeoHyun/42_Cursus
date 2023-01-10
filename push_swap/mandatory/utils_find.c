/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:15 by seokang           #+#    #+#             */
/*   Updated: 2023/01/10 17:09:15 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_of_idx(t_info *stack_info)
{
	int		idx;
	int		min;
	int		tmp;
	int		size_a;
	t_node	*stack_a;

	idx = 0;
	min = min_of_data(stack_info);
	size_a = stack_info->size_a;
	stack_a = stack_info->stack_a->top->next;
	while (idx < size_a)
	{
		tmp = stack_a->data;
		if (tmp == min)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (size_a + 1) / 2)
		idx = (size_a - idx) * -1;
	return (idx);
}

int	max_of_idx(t_info *stack_info)
{
	int		idx;
	int		min;
	int		tmp;
	int		size_a;
	t_node	*stack_a;

	idx = 0;
	min = max_of_data(stack_info);
	size_a = stack_info->size_a;
	stack_a = stack_info->stack_a->top->next;
	while (idx < size_a)
	{
		tmp = stack_a->data;
		if (tmp == min)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (size_a + 1) / 2)
		idx = (size_a - idx) * -1;
	return (idx);
}

int	mid_of_idx(t_info *stack_info, int num)
{
	int			idx;
	int			size_a;
	t_node		*stack_a;

	idx = 1;
	size_a = stack_info->size_a;
	stack_a = stack_info->stack_a->top->next;
	while (idx < size_a + 1)
	{
		if (stack_a->next->data == 0)
			return (0);
		if (num > stack_a->data && num < stack_a->next->data)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (size_a + 1) / 2)
		idx = (size_a - idx) * -1;
	return (idx);
}

int	find_idx(t_info *stack_info, int num)
{
	int	result;

	if (num < min_of_data(stack_info))
		result = min_of_idx(stack_info);
	else if (num > max_of_data(stack_info))
		result = max_of_idx(stack_info);
	else
		result = mid_of_idx(stack_info, num);
	return (result);
}
