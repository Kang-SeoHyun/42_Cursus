/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/02 21:26:50 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_self(t_info *stack_info)
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

void	sort_array(t_info *stack_info)
{
	int	a;
	int	b;

	
}

void	sorting(t_info *stack_info)
{
	if (stack_info->size_array == 2)
		sa(stack_info);
	else if (stack_info->size_array == 3)
		sort_self(stack_info);
	else
		sort_array(stack_info);
}
