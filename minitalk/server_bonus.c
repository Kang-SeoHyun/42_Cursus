/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 03:04:37 by seokang           #+#    #+#             */
/*   Updated: 2023/01/15 03:42:37 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_handler(int signal, siginfo_t *info, void *s)
{
	static int	bit;
	static char	tmp;
	pid_t		pid;

	(void)s;
	pid = info->si_pid;
	if (signal == SIGUSR1)
		tmp |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (tmp == '\0')
			kill(pid, SIGUSR1);
		else
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
	pid_t				pid;
	struct sigaction	sig;

	(void)av;
	if (ac != 1 || av[1] != NULL)
	{
		ft_putstr_fd("Error: wrong message.\n", 1);
		ft_putstr_fd("Try: ./server \n", 1);
		return (0);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = &ft_handler;
	sigemptyset(&sig.sa_mask);
	pid = getpid();
	ft_pid_print(pid);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
