/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .c                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:04:19 by seokang           #+#    #+#             */
/*   Updated: 2022/12/07 20:35:28 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_var *var)
{
	var->stack_a = (t_stack *)malloc(sizeof(t_stack));
	var->stack_b = (t_stack *)malloc(sizeof(t_stack));
	var->stack_a->top = get_new_node(0);
	var->stack_a->bottom = get_new_node(0);
	var->stack_a->top->down = var->stack_a->bottom;
	var->stack_a->bottom->up = var->stack_a->top;
	var->stack_b->top = get_new_node(0);
	var->stack_b->bottom = get_new_node(0);
	var->stack_b->top->down = var->stack_b->bottom;
	var->stack_b->bottom->up = var->stack_b->top;
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
