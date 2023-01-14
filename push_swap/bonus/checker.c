/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 06:55:57 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 08:28:10 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_info	stack_info;

	if (ac < 2)
		print_error();
	else
	{
		init_stack(&stack_info);
		validate_args(&stack_info, ac, av);
		indexing(&stack_info);
		stacking(&stack_info);
		start_sorting(&stack_info);
		checker(&stack_info);
		exit(0);
	}	
	return (0);
}
