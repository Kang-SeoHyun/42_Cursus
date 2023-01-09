/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:39:35 by seokang           #+#    #+#             */
/*   Updated: 2023/01/09 22:14:59 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_rotate(t_info *stack_info, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		idx;
	t_node	*b_node;
	int		num;

	idx = 0;
	b_node = stack_info->stack_b->top->next;
	while (idx < stack_info->size_b)
	{
		num = b_node->data;
		a_idx = find_idx(stack_info, num);
		if (idx >= (stack_info->size_b + 1) / 2)
			b_idx = (stack_info->size_b - idx) * -1;
		else
			b_idx = idx;
		if (idx == 0 || get_bigger(*a, *b, a_idx, b_idx))
		{ //여기여기여기
			*a = a_idx;
			*b = b_idx;
		}
		b_node = b_node->next;
		idx++;
	}
}
