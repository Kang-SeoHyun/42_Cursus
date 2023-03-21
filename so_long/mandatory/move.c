/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:24:55 by seokang           #+#    #+#             */
/*   Updated: 2023/03/21 18:12:03 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_set_cur_idx(t_map *map, int *cur)
{
	int	idx;

	idx = 0;
	while (map->map_str[idx])
	{
		if (map->map_str[idx] == 'P')
			*cur = idx;
		idx++;
	}
}

static void	ft_set_nxt_idx(t_map *map, t_direction direction, int cur, int *nxt)
{
	if (direction == Up)
		*nxt = cur - map->col;
	else if (direction == Down)
		*nxt = cur + map->col;
	else if (direction == Left)
		*nxt = cur - 1;
	else if (direction == Right)
		*nxt = cur + 1;
}

void	ft_move(t_game *game, t_direction direction)
{
    int cur;
    int nxt;

    ft_set_cur_idx(&game->map, &cur);
    ft_set_nxt_idx(&game->map, direction, cur, &nxt);
    if (game->map.map_str[nxt] != '1')
    {
        if (game->map.map_str[nxt] == 'C')
			game->collectible--;
        if (game->map.map_str[nxt] == 'E')
		{
			if (game->collectible)
				return ;
			else
				ft_exit_game(game);
		}
        ft_putstr_fd("count : ", 1);
		ft_putnbr_fd(++game->cnt, 1);
        write(1, "\n", 1);
        game->map.map_str[cur] = '0';
        game->map.map_str[nxt] = 'P';
    }
    ft_set_sprites(game); 
}