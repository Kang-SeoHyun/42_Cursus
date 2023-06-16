/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:13 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:34:13 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_type_of_component(t_game *game, int type, char *line)
{
	char	*value_line;

	value_line = get_value_of_addr(line);
	if (type == NO && (game->tex[NO].tex_path_malloc \
			|| !get_value_of_path(value_line, game, NO)))
		error_exit("Invalid 'NO' file");
	else if (type == SO && (game->tex[SO].tex_path_malloc \
			|| !get_value_of_path(value_line, game, SO)))
		error_exit("Invalid 'SO' file");
	else if (type == WE && (game->tex[WE].tex_path_malloc \
			|| !get_value_of_path(value_line, game, WE)))
		error_exit("Invalid 'WE' file");
	else if (type == EA && (game->tex[EA].tex_path_malloc \
			|| !get_value_of_path(value_line, game, EA)))
		error_exit("Invalid 'EA' file");
	free(value_line);
}

void	set_type_of_color(t_img *img, int type, char *line)
{
	if (type == F)
	{
		if (img->floor_color != INIT)
			error_exit("Already saved the value of F");
		img->floor_color = get_value_of_color(line);
	}
	else if (type == C)
	{
		if (img->ceil_color != INIT)
			error_exit("Already saved the value of C");
		img->ceil_color = get_value_of_color(line);
	}
}

void	set_type_of_map(t_map *map, t_game *game, char *line)
{
	check_saved_component(game);
	map->map_value = get_value_of_map(map, line);
}

void	set_type(t_game *game, int type, char *line)
{
	if (NO <= type && type <= EA)
		set_type_of_component(game, type, line);
	else if (F <= type && type <= C)
		set_type_of_color(&game->img, type, line);
	else
		set_type_of_map(&game->map, game, line);
}
