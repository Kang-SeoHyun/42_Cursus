/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:13:32 by seokang           #+#    #+#             */
/*   Updated: 2023/01/17 21:53:44 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_info	stack_info;

	if (ac < 2)
		print_error();
	else
	{
		init_stack(&stack_info);
		system("leaks push_swap | grep leaked");
		validate_args(&stack_info, ac, av);
		system("leaks push_swap | grep leaked");
		first_check(&stack_info);
		system("leaks push_swap | grep leaked");
		indexing(&stack_info);
		system("leaks push_swap | grep leaked");
		stacking(&stack_info);
		system("leaks push_swap | grep leaked");
		start_sorting(&stack_info);
		system("leaks push_swap | grep leaked");
		exit(0);
	}	
	return (0);
}
