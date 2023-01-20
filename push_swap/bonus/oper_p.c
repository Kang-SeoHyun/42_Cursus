/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:38:00 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 18:05:57 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_info *info)
{
	t_node	*tmp;

	tmp = pop_top(info->stack_b);
	if (!tmp)
		return ;
	push_top(info->stack_a, tmp);
	info->size_a += 1;
	info->size_b -= 1;
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
}
