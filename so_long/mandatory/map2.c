/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:10:44 by seokang           #+#    #+#             */
/*   Updated: 2023/03/11 17:21:59 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_check_rectangle(t_map *map)
{
    if (ft_strlen(map->map_str) != (size_t)(map->col * map->row))
        print_err("ERROR in map shape.");
}

static void ft_check_components(t_game *game)
{
    int idx;
    int player;

    idx = 0;
    player = 0;
    while (game->map.map_str[idx])
    {
		if (game->map.map_str[idx] == 'C')
			game->check_map.collectible++;
		else if (game->map.map_str[idx] == 'E')
			game->check_map.exit++;
		else if (game->map.map_str[idx] == 'P')
			player++;
        else if (game->map.map_str[idx] != '1' && game->map.map_str[idx] != '0')
			print_err("ERROR in input components.");
        idx++;
    }
    if (!game->check_map.collectible || game->check_map.exit != 1 || player != 1)
        print_err("ERROR in PCE")
}

static void ft_check_wall(t_map *map)
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

void    ft_verify_map(t_game *game)
{
    ft_check_rectangle(&(game->map));
    game->check_map.collectible = 0;
    game->check_map.exit = 0;
    ft_check_components(game);
    ft_check_wall(&(game->map));
    //할 차례!!!!!!아래꺼
    ft_check_valid_path(game);
}