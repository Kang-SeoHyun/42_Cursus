/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:04:47 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 01:19:52 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_pid_print(pid_t pid)
{
	
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("Error!! Try: ./server \n", 1);
		return (0);
	}
	pid = getpid();
	ft_pid_print(pid);
}
