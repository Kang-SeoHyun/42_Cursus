/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:57:18 by seokang           #+#    #+#             */
/*   Updated: 2023/01/09 21:00:22 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_info *stack_info)
{
	int	first;
	int	second;

	first = stack_info->stack_a->top->next->data;
	second = stack_info->stack_a->top->next->next->data;
	if (first > second)
		sa(stack_info);
}

void	sort_three(t_info *stack_info)
{
	int	first;
	int	second;
	int	third;

	first = stack_info->stack_a->top->next->data;
	second = stack_info->stack_a->top->next->next->data;
	third = stack_info->stack_a->top->next->next->next->data;
	if (first > second && second > third && first > third)
	{
		ra(stack_info);
		sa(stack_info);
	}
	else if (first > second && second < third && first > third)
		ra(stack_info);
	else if (first > second && second < third && first < third)
		sa(stack_info);
	else if (first < second && second > third && first > third)
		rra(stack_info);
	else if (first < second && second > third && first < third)
	{
		rra(stack_info);
		sa(stack_info);
	}
}
