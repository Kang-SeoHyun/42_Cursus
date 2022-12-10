/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:13:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/10 20:55:17 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char *av[])
{
	t_info	*stack_info;

	if (ac < 2)
		print_error();
	else
	{
		init_stack(&stack_info);
		validate_args(ac, av, &stack_info);
		check_sort(&stack_info);
		indexing(&stack_info);
		stacking(&stack_info);
		operating(&stack_info);
		exit(0);
	}	
	return (0);
}
