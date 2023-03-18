/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:25:13 by seokang           #+#    #+#             */
/*   Updated: 2023/03/18 20:53:36 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_init_game(t_game *game)
{
    int idx;

    game->cnt = 0;
    game->collectible = 0;
    idx = 0;
    while (game->map.map_str[idx])
    {
        if (game->map.map_str[idx] == 'C')
            game->collectible++;
        idx++;
    }
    ft_init_sprites(game);
}

void    ft_start_game(t_game *game)
{
    game->mlx_ptr = mlx_init();
    game->win_ptr = mlx_new_window(game->mlx_ptr, \
		(game->map.col + 2) * SIZE, (game->map.row + 2) * SIZE, "so_long");
    ft_init_game(game);
    mlx_hook(game->win_ptr, X_EVENT_KEY_PRESS, 0, &ft_press_key, game);
	mlx_hook(game->win_ptr, X_EVENT_KEY_EXIT, 0, &ft_exit_game, game);
	mlx_loop(game->mlx_ptr);
}