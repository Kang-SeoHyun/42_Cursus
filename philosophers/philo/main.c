/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:17:48 by seokang           #+#    #+#             */
/*   Updated: 2023/04/04 14:31:33 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("ERROR : %s", str);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_info	info;

	if (argc != 5 && argc != 6)
	{
		ft_error("argument count");
		return (1);
	}
	if (parsing(&info, argc, argv) == -1)
		return (2);
	simulate(&info);
	return (0);
}
