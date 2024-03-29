/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 12:13:32 by seokang           #+#    #+#             */
/*   Updated: 2023/01/20 17:53:15 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char *av[])
{
	t_info	stack_info;

	if (ac >= 2)
	{
		init_stack(&stack_info);
		validate_args(&stack_info, ac, av);
		stacking(&stack_info);
		checker(&stack_info);
		exit(0);
	}	
	return (0);
}
