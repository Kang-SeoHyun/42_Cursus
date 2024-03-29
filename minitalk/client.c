/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:04:50 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 04:30:14 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	if (ac == 3 && av[2][0] != '\0')
	{
		pid = ft_atoi(av[1]);
		if (pid < 100 || pid > 99999)
		{
			ft_putstr_fd("Error: wrong pid.\n", 1);
			return (0);
		}
		ft_send_msg(pid, av[2]);
	}
	else
	{
		ft_putstr_fd("Error: wrong message.\n", 1);
		ft_putstr_fd("Try: ./client [PID] [MESSAGE]\n", 1);
	}
	return (0);
}
