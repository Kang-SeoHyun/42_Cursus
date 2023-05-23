/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:30:31 by seokang           #+#    #+#             */
/*   Updated: 2023/05/23 09:30:32 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_handler(int signum)
{
	if (signum == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		ft_putendl_fd("", STDERR_FILENO);
		exit(1);
	}
}

void	quit_handler(int signum)
{
	if (signum == SIGINT)
		ft_putendl_fd("", STDERR_FILENO);
	exit(1);
}

static void	default_handler(int signum)
{
	if (signum == SIGINT)
	{
		ft_putendl_fd(CYAN"💎 minishell-1.0$ "RESET, STDOUT_FILENO);
		g_exit_status = 1;
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

void	set_signal(void)
{
	signal(SIGINT, default_handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
}
