/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:32:44 by seokang           #+#    #+#             */
/*   Updated: 2023/03/21 19:23:01 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void count_map_size(t_map *map, char *file_name)
{
	int		fd;
	int		cur_col;
	char	buffer;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_err("ERROR in file.");
	cur_col = 0;
	map->col = 0;
	map->row = 0;
	while (read(fd, &buffer, 1))
	{
		if (buffer == '\n')
		{
			if (map->col < cur_col)
				map->col = cur_col;
			cur_col = 0;
			map->row++;
		}
		else
			cur_col++;
	}
	close(fd);
}

char	*ft_str_replace(char *str, char c1, char c2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c1)
			str[i] = c2;
		i++;
	}
	return (str);
}

static void make_map(t_map *map, char *file_name, int idx)
{
	int		fd;
	int		cur_col;
	int		cur_row;
	char	*line;

	map->map_str = (char *)malloc(sizeof(char) * (map->col * map->row + 1));
	if (!map->map_str)
		print_err("ERROR in memory.");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_err("ERROR in file.");
	cur_row = 0;
	while (cur_row < map->row)
	{
		line = ft_str_replace(get_next_line(fd), '\n', '\0');
		cur_col = 0;
		while ((size_t)cur_col < ft_strlen(line))
		{
			map->map_str[idx++] = line[cur_col];
			cur_col++;
		}
		cur_row++;
	}
	close(fd);
	map->map_str[idx] = '\0';
}

static void read_file(char *file_name)
{
    if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".ber", 4))
        print_err("ERROR in file type.");
}

void    init_map(t_game *game, char *file_name)
{
    read_file(file_name);
    count_map_size(&(game->map), file_name);
    make_map(&(game->map), file_name, 0);
    parse_map(game);
}
