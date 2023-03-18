/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:51:26 by seokang           #+#    #+#             */
/*   Updated: 2023/03/18 20:18:21 by seokang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

//key set
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2


typedef struct s_map
{
	int		col;
	int		row;
	char	*map_str;
}	t_map;

typedef struct s_check_map
{
	int	pl_col;
	int	pl_row;
	int	collectible;
	int	exit;
	int	*check;	
}	t_check_map;

typedef struct s_game
{
	int			cnt;
	int			collectible;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_check_map	check_map;
}	t_game;

/* main.c */
void    print_err(char  *msg);

/* map.c */
void    ft_init_map(t_game *game, char *file_name);
void    ft_check_map(t_game *game);
void    ft_check_valid_path(t_game *game);

#endif