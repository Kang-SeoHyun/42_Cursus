/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:04:08 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 04:30:24 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_trans_bit(pid_t pid, char letter)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((letter & (1 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

static void	ft_send_msg(pid_t pid, char msg[])
{
	int	i;

	i = 0;
	while (msg[i] != '\0')
	{
		ft_trans_bit(pid, msg[i]);
		i++;
	}
	ft_trans_bit(pid, '\n');
	ft_trans_bit(pid, '\0');
}

static void	ft_confirm(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr_fd("Server received message\n", 1);
	exit(0);
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac == 3 && av[2][0] != '\0')
	{
		signal(SIGUSR1, ft_confirm);
		pid = ft_atoi(av[1]);
		if (pid < 100 || pid > 99999)
		{
			ft_putstr_fd("Error: wrong pid.\n", 1);
			return (0);
		}
		ft_send_msg(pid, av[2]);
		while (1)
			pause();
	}
	else
	{
		ft_putstr_fd("Error: wrong message.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
