/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:31:45 by seokang           #+#    #+#             */
/*   Updated: 2023/05/23 09:31:46 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	do_echo(char **argv, int idx)
{
	while (argv[++idx])
	{
		if (argv[idx][0] == '\0')
			continue ;
		ft_putstr_fd(argv[idx], STDOUT_FILENO);
		if (argv[idx + 1])
			ft_putstr_fd(" ", STDOUT_FILENO);
	}
}

int	ms_echo(char **argv)
{
	int	idx;
	int	n_idx;
	int	newline;

	newline = 1;
	idx = 0;
	if (argv[1] && ft_strncmp(argv[1], "-n", 2) == 0)
	{
		n_idx = 1;
		while (argv[1][n_idx] == 'n')
			n_idx++;
		if (argv[1][n_idx] == '\0')
			newline = 0;
		if (argv[1][n_idx] == '\0')
			idx++;
	}
	do_echo(argv, idx);
	if (newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (0);
}
