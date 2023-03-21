/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seokang <seokang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:51:26 by seokang           #+#    #+#             */
/*   Updated: 2023/03/21 19:13:54 by seokang          ###   ########.fr       */
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
# include "../mlx/mlx.h"
# include "key.h"

# define SIZE 32

typedef struct s_map
{
	int		col;
	int		row;
	char	*map_str;
}	t_map;

typedef struct s_img
{
	void	*black;
	void	*pacfood;
	void	*pacman;
	void	*portal;
	void	*wall;
}	t_img;

typedef struct s_check
{
	int	p_col;
	int	p_row;
	int	collectible;
	int	exit;
	int	*check;	
}	t_check;

typedef struct s_game
{
	int			cnt;
	int			collectible;
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_check		check;
	t_img		imgs;
}	t_game;

typedef enum e_direction
{
	Up,
	Down,
	Left,
	Right			
}	t_direction;

/* main.c */
void    print_err(char  *msg);

/* map.c */
void    init_map(t_game *game, char *file_name);
void    parse_map(t_game *game);
void    check_valid_path(t_game *game);

/* game.c */
void    ft_start_game(t_game *game);
int		ft_exit_game(t_game *game);

/* sprites.c */
void	ft_init_sprites(t_game *game);
void	ft_set_sprites(t_game *game);
void	ft_destroy_sprites(t_game *game);

/* move.c */
void	ft_move(t_game *game, t_direction direction);

#endif