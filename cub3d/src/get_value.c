/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:40 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:40 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*get_value_of_addr(char *line)
{
	int		idx;
	char	**split_line;
	char	*res;

	split_line = ft_split(line, ' ');
	if (!split_line[1] || split_line[2])
		error_exit("Invalid file contents");
	res = ft_strdup(split_line[1]);
	idx = -1;
	while (split_line[++idx])
		free(split_line[idx]);
	free(split_line);
	return (res);
}

int	get_value_of_color(char *line)
{
	char	*value_line;
	int		color_num;

	if (*line == '\0')
		error_exit("ReadLine is empty");
	value_line = get_value_of_addr(line);
	color_num = set_value_of_color(value_line);
	return (color_num);
}

char	*get_value_of_map(t_map *map, char *line)
{
	char	*temp;
	char	*result_value;

	if (map->map_value == 0)
		temp = ft_strdup("");
	else
		temp = ft_strjoin(map->map_value, "\n");
	free(map->map_value);
	result_value = ft_strjoin(temp, line);
	free(temp);
	return (result_value);
}

bool	get_value_of_path(char *path, t_game *game, int idx)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		error_exit("Cannot open xpm file");
	close(fd);
	game->tex[idx].tex_path_malloc = ft_strdup(path);
	return (true);
}
