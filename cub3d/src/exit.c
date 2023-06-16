/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:21 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:22 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	error_exit(char *message)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("ERROR: ", 2);
	if (message)
		ft_putendl_fd(message, 2);
	ft_putstr_fd(RESET, 2);
	exit(FAIL);
}

int	press_exit(t_game *game)
{
	ft_putendl_fd(GREEN, 0);
	ft_putendl_fd("EXIT CUB3D", 0);
	ft_putendl_fd(RESET, 0);
	free_all_data(game, 0);
	exit(FAIL);
}
