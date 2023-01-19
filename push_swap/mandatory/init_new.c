/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:04:19 by seokang           #+#    #+#             */
/*   Updated: 2023/01/10 20:57:21 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

t_node	*init_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->data = data;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	init_stack(t_info *info)
{
	info->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!info->stack_a)
		print_error();
	info->stack_a->top = init_node(0);
	info->stack_a->bottom = init_node(0);
	info->stack_a->top->next = info->stack_a->bottom;
	info->stack_a->bottom->prev = info->stack_a->top;
	info->size_a = 0;
	info->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!info->stack_b)
		print_error();
	info->stack_b->top = init_node(0);
	info->stack_b->bottom = init_node(0);
	info->stack_b->top->next = info->stack_b->bottom;
	info->stack_b->bottom->prev = info->stack_b->top;
	info->size_b = 0;
	info->array = (long *)malloc(sizeof(long));
	info->size_array = 0;
}
