/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_Rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:40:59 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:58:34 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_a);
	push_top(info->stack_a, tmp);
}

void	rrb(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_b);
	push_top(info->stack_b, tmp);
}

void	rrr(t_info *info)
{
	t_node	*tmp;

	tmp = pop_bottom(info->stack_a);
	push_top(info->stack_a, tmp);
	tmp = pop_bottom(info->stack_b);
	push_top(info->stack_b, tmp);
}
