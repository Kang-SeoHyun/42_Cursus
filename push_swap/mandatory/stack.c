/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 22:04:19 by seokang           #+#    #+#             */
/*   Updated: 2022/12/04 22:25:21 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_var *var)
{
	var->stack_a = (t_stack *)malloc(sizeof(t_stack));
	var->stack_b = (t_stack *)malloc(sizeof(t_stack));                                                            
}
