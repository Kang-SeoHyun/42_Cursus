/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:51:35 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:04:30 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_top(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	tmp = stack->top->next;
	stack->top->next = new;
	new->prev = stack->top;
	new->next = tmp;
	tmp->prev = new;
}

void	push_bottom(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	tmp = stack->bottom->prev;
	stack->bottom->prev = new;
	new->next = stack->bottom;
	tmp->next = new;
	new->prev = tmp;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top->next == stack->bottom)
		return (0);
	tmp = stack->top->next;
	tmp->next->prev = stack->top;
	tmp->prev->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*tmp;

	if (stack->bottom->prev == stack->top)
		return (0);
	tmp = stack->bottom->prev;
	tmp->prev->next = stack->bottom;
	tmp->next->prev = tmp->prev;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}
