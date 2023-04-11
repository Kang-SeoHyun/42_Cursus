/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:17:48 by seokang           #+#    #+#             */
/*   Updated: 2023/04/11 21:31:44 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf(RED"ERROR : %s\n"RESET, str);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	if (argc != 5 && argc != 6)
		return (ft_error("argument count"));
	if (parsing(&info, argc, argv))
		return (1);
	info.end = 0;
	simulate(&info);
	return (0);
}
