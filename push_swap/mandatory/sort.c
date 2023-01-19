/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:26:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/17 17:21:30 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_group(t_info *info)
{
	int		i;
	int		p1;
	int		p2;
	t_node	*tmp;

	i = 0;
	p1 = info->max_size / 3;
	p2 = p1 * 2;
	while (i < info->max_size)
	{
		tmp = pop_top(info->stack_a);
		if (tmp->data < p2)
		{
			push_top(info->stack_a, tmp);
			pb(info);
			if (tmp->data < p1)
				rb(info);
		}
		else
		{
			push_top(info->stack_a, tmp);
			ra(info);
		}
		i++;
	}
}

void	ascending_order(t_info *info)
{
	int	target;

	target = min_of_idx(info);
	while (target)
	{
		if (target > 0)
		{
			target--;
			ra(info);
		}
		else
		{
			target++;
			rra(info);
		}
	}
}

void	sort_array(t_info *info)
{
	int	a;
	int	b;

	divide_group(info);
	while (info->size_a > 3)
		pb(info);
	if (info->size_a == 2)
		sort_two(info);
	if (info->size_a == 3)
		sort_three(info);
	while (info->size_b)
	{
		a = 0;
		b = 0;
		get_min_rotate(info, &a, &b);
		rotate_same(info, &a, &b);
		rotate_in_a(info, a);
		rotate_in_b(info, b);
		pa(info);
	}
	ascending_order(info);
}

void	start_sorting(t_info *info)
{
	if (info->size_array == 2)
		sa(info);
	else if (info->size_array == 3)
		sort_three(info);
	else
		sort_array(info);
}
