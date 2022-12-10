/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_R_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:40:59 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 21:44:30 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_a);
	push_top(info->stack_a, tmp);
	write(1, "rra\n", 4);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_b);
	push_top(info->stack_b, tmp);
	write(1, "rrb\n", 4);
}

void	rrr(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_a);
	push_top(info->stack_a, tmp);
	tmp = pop_bottom(info->stack_b);
	push_top(info->stack_b, tmp);
	write(1, "rrr\n", 4);
}
