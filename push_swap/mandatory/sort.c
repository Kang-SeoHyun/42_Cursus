/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/09 15:09:45 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_hardcode(t_info *stack_info)
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

void	divide_group(t_info *stack_info)
{
	t_node	*tmp;
	int		cnt;
	int		p1;
	int		p2;

	cnt = 0;
	p1 = stack_info->max_size / 3;
	p2 = p1 * 2;
	while (cnt < stack_info->max_size)
	{
		tmp = pop_top(stack_info->stack_a);
		if (tmp->data < p2)
		{
			push_top(stack_info->stack_a, tmp);
			pb(stack_info);
			if (tmp->data < p1)
				rb(stack_info);
		}
		else
		{
			push_top(stack_info->stack_a, tmp);
			ra(stack_info);
		}
		cnt++;
	}
}

void	sort_array(t_info *stack_info)
{
	int	a;
	int	b;

	divide_group(stack_info);
	while (stack_info->size_a > 3)
		pb(stack_info);
	if (stack_info->size_a == 2)
	{
		if (stack_info->stack_a->top->next->data > \
			stack_info->stack_a->top->next->next->data)
			sa(stack_info);
	}
	if (stack_info->size_a == 3)
		sort_hardcode(stack_info);
	while (stack_info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack_info, &a, &b);
	}
	//sort_big_last(stack_info);
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
