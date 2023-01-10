/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 22:39:35 by seokang           #+#    #+#             */
/*   Updated: 2023/01/10 17:52:06 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min_rotate(t_info *stack_info, int *a, int *b)
{
	int		a_idx;
	int		b_idx;
	int		i;
	t_node	*b_node;
	int		num;

	i = 0;
	b_node = stack_info->stack_b->top->next;
	while (i < stack_info->size_b)
	{
		num = b_node->data;
		a_idx = find_idx(stack_info, num);
		if (i >= (stack_info->size_b + 1) / 2)
			b_idx = (stack_info->size_b - i) * -1;
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
