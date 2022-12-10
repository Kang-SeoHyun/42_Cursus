/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:04:19 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 12:16:55 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_info *info)
{
	info->stack_a = (t_stack *)malloc(sizeof(t_stack));
	info->stack_a->top = get_new_node(0);
	info->stack_a->bottom = get_new_node(0);
	info->stack_a->top->down = info->stack_a->bottom;
	info->stack_a->bottom->up = info->stack_a->top;
	info->stack_b = (t_stack *)malloc(sizeof(t_stack));
	info->stack_b->top = get_new_node(0);
	info->stack_b->bottom = get_new_node(0);
	info->stack_b->top->down = info->stack_b->bottom;
	info->stack_b->bottom->up = info->stack_b->top;
}

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->data = num;
	node->up = NULL;
	node->down = NULL;
	return (node);
}
