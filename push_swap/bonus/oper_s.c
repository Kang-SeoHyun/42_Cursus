/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:37:17 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:58:43 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(info->stack_a);
	tmp2 = pop_top(info->stack_a);
	push_top(info->stack_a, tmp1);
	push_top(info->stack_a, tmp2);
}

void	sb(t_info *info)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = pop_top(info->stack_b);
	tmp2 = pop_top(info->stack_b);
	push_top(info->stack_b, tmp1);
	push_top(info->stack_b, tmp2);
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
}
