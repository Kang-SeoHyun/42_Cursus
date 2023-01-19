/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:12:15 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 06:39:26 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	min_of_idx(t_info *info)
{
	int		idx;
	int		min;
	int		tmp;
	t_node	*stack_a;

	idx = 0;
	min = min_of_data(info);
	tmp = 0;
	stack_a = info->stack_a->top->next;
	while (idx < info->size_a)
	{
		tmp = stack_a->data;
		if (tmp == min)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (info->size_a + 1) / 2)
		idx = (info->size_a - idx) * -1;
	return (idx);
}

int	max_of_idx(t_info *info)
{
	int		idx;
	int		max;
	int		tmp;
	t_node	*stack_a;

	idx = 0;
	tmp = 0;
	max = max_of_data(info);
	stack_a = info->stack_a->top->next;
	while (idx < info->size_a)
	{
		tmp = stack_a->data;
		if (tmp == max)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	idx++;
	if (idx >= (info->size_a + 1) / 2)
		idx = (info->size_a - idx) * -1;
	return (idx);
}

int	mid_of_idx(t_info *info, int num)
{
	int			idx;
	t_node		*stack_a;

	idx = 1;
	stack_a = info->stack_a->top->next;
	while (idx < info->size_a + 1)
	{
		if (stack_a->next->data == 0)
			return (0);
		if (num > stack_a->data && num < stack_a->next->data)
			break ;
		idx++;
		stack_a = stack_a->next;
	}
	if (idx >= (info->size_a + 1) / 2)
		idx = (info->size_a - idx) * -1;
	return (idx);
}

int	find_idx(t_info *info, int num)
{
	int	result;

	if (num < min_of_data(info))
		result = min_of_idx(info);
	else if (num > max_of_data(info))
		result = max_of_idx(info);
	else
		result = mid_of_idx(info, num);
	return (result);
}
