/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:13:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/16 20:31:02 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_check(t_info	*stack_info)
{
	int	i;
	int	val;

	i = 0;
	val = stack_info->array[0];
	while (++i < stack_info->size_array)
	{
		if (val > stack_info->array[i])
			return ;
		val = stack_info->array[i];
	}
	exit(0);
}

int	main(int ac, char *av[])
{
	t_info	stack_info;

	if (ac < 2)
		print_error();
	else
	{
		init_stack(&stack_info);
		validate_args(ac, av, &stack_info);
		first_check(&stack_info);
		indexing(&stack_info);
	}	
	return (0);
}
