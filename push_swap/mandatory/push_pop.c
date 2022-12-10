/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:51:35 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 12:12:29 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_top(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	tmp = stack->top->down;
	stack->top->down = new;
	tmp->up = new;
	new->up = stack->top;
	new->down = tmp;
}

void	push_bottom(t_stack *stack, t_node *new)
{
	t_node	*tmp;

	tmp = stack->bottom->up;
	stack->bottom->up = new;
	tmp->down = new;
	new->up = tmp;
	new->down = stack->bottom;
}

t_node	*pop_top(t_stack *stack)
{
	t_node	*tmp;

	if (stack->top->down == stack->bottom)
		return (0);
	tmp = stack->top->down;
	tmp->down->up = stack->top;
	tmp->up->down = tmp->down;
	tmp->up = NULL;
	tmp->down = NULL;
	return (tmp);
}

t_node	*pop_bottom(t_stack *stack)
{
	t_node	*tmp;

	if (stack->bottom->up == stack->top)
		return (0);
	tmp = stack->bottom->up;
	tmp->up->down = stack->bottom;
	tmp->down->up = tmp->up;
	tmp->up = NULL;
	tmp->down = NULL;
	return (tmp);
}
