/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:38:03 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 21:36:44 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_a);
	push_bottom(info->stack_a, tmp);
	write(1, "ra\n", 3);
}

void	rb(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_b);
	push_bottom(info->stack_b, tmp);
	write(1, "rb\n", 3);
}

void	rr(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_a);
	push_bottom(info->stack_a, tmp);
	tmp = pop_top(info->stack_b);
	push_bottom(info->stack_b, tmp);
	write(1, "rr\n", 3);
}
