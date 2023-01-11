/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/11 17:16:32 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_group(t_info *stack_info)
{
	t_node	*tmp;
	int		i;
	int		p1;
	int		p2;

	i = 0;
	p1 = stack_info->max_size / 3;
	p2 = p1 * 2;
	while (i < stack_info->max_size)
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
		i++;
	}
}

void	ascending_order(t_info *stack_info)
{
	int	target;

	target = min_of_idx(stack_info);
	while (target)
	{
		if (target > 0)
		{
			target--;
			ra(stack_info);
		}
		else
		{
			target++;
			rra(stack_info);
		}
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
		sort_two(stack_info);
	if (stack_info->size_a == 3)
		sort_three(stack_info);
	while (stack_info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(stack_info, &a, &b);
		rotate_same(stack_info, &a, &b);
		rotate_in_a(stack_info, a);
		rotate_in_b(stack_info, b);
		pa(stack_info);
	}
	ascending_order(stack_info);
}

void	start_sorting(t_info *stack_info)
{
	if (stack_info->size_array == 2)
		sort_two(stack_info);
	else if (stack_info->size_array == 3)
		sort_three(stack_info);
	else
		sort_array(stack_info);
}
