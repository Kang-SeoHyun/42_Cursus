/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:13:32 by seokang           #+#    #+#             */
/*   Updated: 2022/12/16 18:05:30 by seokang          ###   ########.fr       */
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
		validate_args(ac, av, &stack_info);
	}	
	return (0);
}
