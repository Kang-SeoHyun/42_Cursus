/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 20:56:35 by seokang           #+#    #+#             */
/*   Updated: 2023/03/26 19:43:37 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_sprites(t_game *game)
{
	int	width;
	int	height;

	game->imgs.black = mlx_xpm_file_to_image(game->mlx_ptr, \
	"img/white.xpm", &width, &height);
	game->imgs.pacfood = mlx_xpm_file_to_image(game->mlx_ptr, \
	"img/red_dock.xpm", &width, &height);
	game->imgs.pacman = mlx_xpm_file_to_image(game->mlx_ptr, \
	"img/blue_dock.xpm", &width, &height);
	game->imgs.portal = mlx_xpm_file_to_image(game->mlx_ptr, \
	"img/goal.xpm", &width, &height);
	game->imgs.wall = mlx_xpm_file_to_image(game->mlx_ptr, \
	"img/wall.xpm", &width, &height);
}

static void	ft_show_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	img, (x) * SIZE, (y) * SIZE);
}

void	ft_set_sprites(t_game *game)
{
	int	col;
	int	row;
	int	idx;

	row = 0;
	while (row < game->map.row)
	{
		col = 0;
		while (col < game->map.col)
		{
			idx = row * game->map.col + col;
			if (game->map.map_str[idx] == '1')
				ft_show_image(game, game->imgs.wall, col, row);
			if (game->map.map_str[idx] == '0')
				ft_show_image(game, game->imgs.black, col, row);
			if (game->map.map_str[idx] == 'E')
				ft_show_image(game, game->imgs.portal, col, row);
			if (game->map.map_str[idx] == 'C')
				ft_show_image(game, game->imgs.pacfood, col, row);
			if (game->map.map_str[idx] == 'P')
				ft_show_image(game, game->imgs.pacman, col, row);
			col++;
		}
		row++;
	}
}

void	ft_destroy_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->imgs.black);
	mlx_destroy_image(game->mlx_ptr, game->imgs.pacfood);
	mlx_destroy_image(game->mlx_ptr, game->imgs.pacman);
	mlx_destroy_image(game->mlx_ptr, game->imgs.portal);
	mlx_destroy_image(game->mlx_ptr, game->imgs.wall);
}
