/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:38:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/14 20:08:14 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_b);
	if (!tmp)
		return ;
	push_top(info->stack_a, tmp);
	info->size_a += 1;
	info->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_a);
	if (!tmp)
		return ;
	push_top(info->stack_b, tmp);
	info->size_a -= 1;
	info->size_b += 1;
	write(1, "pb\n", 3);
}
