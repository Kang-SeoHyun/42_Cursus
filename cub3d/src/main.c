/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:54 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:54 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_all_data(t_game *game, int idx)
{
	while (++idx <= 4)
	{
		if (game->tex[idx].tex_path_malloc)
		{
			free(game->tex[idx].tex_path_malloc);
			game->tex[idx].tex_path_malloc = NULL;
			free(game->tex[idx].data);
			game->tex[idx].data = NULL;
		}
	}
	if (game->map.map_value)
		free(game->map.map_value);
	game->map.map_value = NULL;
	if (game->map.saved_map)
	{
		idx = -1;
		while (game->map.saved_map[++idx])
		{
			free(game->map.saved_map[idx]);
			game->map.saved_map[idx] = NULL;
		}
		free(game->map.saved_map);
	}
}

static int	get_file_fd(char *file_name)
{
	int	fd;

	if (!is_valid_extention(file_name, ".cub"))
		error_exit("Invalid extension");
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		error_exit("Cannot open file");
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	game;

	if (argc != 2)
		error_exit("Input invalid argc");
	fd = get_file_fd(argv[1]);
	init_game(&game, fd);
	init_coordinates(&game);
	init_window(&game);
	init_img(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &press_exit, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	free_all_data(&game, 0);
}
