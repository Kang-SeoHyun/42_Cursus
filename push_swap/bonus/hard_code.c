/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_code.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:57:18 by seokang           #+#    #+#             */
/*   Updated: 2023/01/17 17:17:30 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sort_two(t_info *stack_info)
{
	int	first;
	int	second;

	first = stack_info->stack_a->top->next->data;
	second = stack_info->stack_a->top->next->next->data;
	if (first > second)
		sa(stack_info);
}

void	sort_three(t_info *info)
{
	int	first;
	int	second;
	int	third;

	first = info->stack_a->top->next->data;
	second = info->stack_a->top->next->next->data;
	third = info->stack_a->top->next->next->next->data;
	if (first > second && second > third && first > third)
	{
		sa(info);
		rra(info);
	}
	else if (first > second && second < third && first > third)
		ra(info);
	else if (first > second && second < third && first < third)
		sa(info);
	else if (first < second && second > third && first > third)
		rra(info);
	else if (first < second && second > third && first < third)
	{
		rra(info);
		sa(info);
	}
}
