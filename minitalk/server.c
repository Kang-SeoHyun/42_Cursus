/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:04:47 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 02:33:52 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal)
{
	static int	bit;
	static char	tmp;

	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(tmp, 1);
		bit = 0;
		tmp = 0;
	}
}

static void	ft_pid_print(pid_t pid)
{
	ft_putstr_fd("PID -> ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for a message...\n", 1);
}

int	main(int ac, char *av[])
{
	pid_t	pid;

	(void)av;
	if (ac != 1 || av[1] != NULL)
	{
		ft_putstr_fd("Error: wrong message.\n", 1);
		ft_putstr_fd("Try: ./server \n", 1);
		return (0);
	}
	pid = getpid();
	ft_pid_print(pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
