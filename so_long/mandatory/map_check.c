/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:10:44 by seokang           #+#    #+#             */
/*   Updated: 2023/03/21 19:21:05 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void check_elements(t_game *game)
{
    int idx;
    int player;

    idx = 0;
    player = 0;
    while (game->map.map_str[idx])
    {
		if (game->map.map_str[idx] == 'C')
			game->check.collectible++;
		else if (game->map.map_str[idx] == 'E')
			game->check.exit++;
		else if (game->map.map_str[idx] == 'P')
			player++;
        else if (game->map.map_str[idx] != '1' && game->map.map_str[idx] != '0')
			print_err("ERROR in input components.");
        idx++;
    }
    if (!game->check.collectible || game->check.exit != 1 || player != 1)
        print_err("ERROR in PCE");
}

static void is_it_surrounded(t_map *map)
{
    int	cur_col;
	int	cur_row;

	cur_col = 0;
    while (cur_col < map->col)
    {
        if (map->map_str[cur_col] != '1' || map->map_str[(map->row - 1) * map->col + cur_col] != '1')
            print_err("ERROR in make walls");
        cur_col++;
    }
    cur_row = 0;
    while (cur_row < map->row)
    {
        if (map->map_str[cur_row * map->col] != '1' || map->map_str[cur_row * map->col + (map->col - 1)] != '1')
            print_err("ERROR in make walls");
        cur_row++;
    }
}

void    parse_map(t_game *game)
{
    if (ft_strlen(game->map.map_str) != (size_t)(game->map.col * game->map.row))
		print_err("Map must be rectangular");
    game->check.collectible = 0;
    game->check.exit = 0;
    check_elements(game);
    is_it_surrounded(&(game->map));
    check_valid_path(game);
}
