/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_Rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 08:37:18 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 08:54:45 by seokang          ###   ########.fr       */
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
