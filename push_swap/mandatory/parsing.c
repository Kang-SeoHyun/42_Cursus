/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:17:08 by seokang           #+#    #+#             */
/*   Updated: 2022/12/14 16:32:13 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_args(int ac, char *av[], t_info *stack_info){
	int	i;
	
	i = 1;
	while (i < av)
	{
    	int	j;
		
		j = 0;
    	while (av[i][j])
    	{
        	if argv[i][j]
        	{
				char	*from;
				char	*to;
            	from = argv[i][j];
            	while (argv[i][j])
				j++;
            	to = argv[i][j];
            	ft_atoi(from, to);
        	}
			j++;
    	}
		i++
	}
}
