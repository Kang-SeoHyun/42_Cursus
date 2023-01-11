/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:37:17 by seokang           #+#    #+#             */
/*   Updated: 2023/01/10 20:44:52 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(info->stack_a);
	tmp2 = pop_top(info->stack_a);
	push_top(info->stack_a, tmp1);
	push_top(info->stack_a, tmp2);
	write(1, "sa\n", 3);
}

void	sb(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(info->stack_b);
	tmp2 = pop_top(info->stack_b);
	push_top(info->stack_b, tmp1);
	push_top(info->stack_b, tmp2);
	write(1, "sb\n", 3);
}

void	ss(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(info->stack_a);
	tmp2 = pop_top(info->stack_a);
	push_top(info->stack_a, tmp1);
	push_top(info->stack_a, tmp2);
	tmp1 = pop_top(info->stack_b);
	tmp2 = pop_top(info->stack_b);
	push_top(info->stack_b, tmp1);
	push_top(info->stack_b, tmp2);
	write(1, "ss\n", 3);
}
