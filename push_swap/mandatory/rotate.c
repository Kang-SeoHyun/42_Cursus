/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:39:35 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 06:34:35 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_rotate(t_info *info, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		i;
	t_node	*b_node;
	int		num;

	i = 0;
	b_node = info->stack_b->top->next;
	while (i < info->size_b)
	{
		num = b_node->data;
		a_idx = find_idx(info, num);
		if (i >= (info->size_b + 1) / 2)
			b_idx = (info->size_b - i) * -1;
		else
			b_idx = i;
		if (i == 0 || setidx_getbig(*a, *b, a_idx, b_idx))
		{
			*a = a_idx;
			*b = b_idx;
		}
		b_node = b_node->next;
		i++;
	}
}

void	rotate_same(t_info *info, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(info);
		*a -= 1;
		*b -= 1;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(info);
		*a += 1;
		*b += 1;
	}
}

void	rotate_in_a(t_info *info, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(info);
			a--;
		}
		else
		{
			rra(info);
			a++;
		}
	}
}

void	rotate_in_b(t_info *info, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(info);
			b--;
		}
		else
		{
			rrb(info);
			b++;
		}
	}
}
