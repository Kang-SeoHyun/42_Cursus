/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:54:37 by seokang           #+#    #+#             */
/*   Updated: 2023/01/10 17:17:26 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_of_data(t_info *stack_info)
{
	t_node	*stack;
	int		result;
	int		i;

	stack = stack_info->stack_a->top->next;
	result = stack->data;
	i = 0;
	while (i++ < stack_info->size_a - 1)
	{
		if (result > stack->next->data)
			result = stack->next->data;
		stack = stack->next;
	}
	return (result);
}

int	max_of_data(t_info *stack_info)
{
	t_node	*stack;
	int		result;
	int		i;

	stack = stack_info->stack_a->top->next;
	result = stack->data;
	i = 0;
	while (i++ < stack_info->size_a - 1)
	{
		if (result < stack->next->data)
			result = stack->next->data;
		stack = stack->next;
	}
	return (result);
}

int	setidx_getbig(int a, int b, int a_idx, int b_idx)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_idx < 0)
		a *= -1;
	if (b_idx < 0)
		b *= -1;
	if (a + b > a_idx + b_idx)
		return (1);
	else
		return (0);
}
