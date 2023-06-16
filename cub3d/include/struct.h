/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:03 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:04 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx_opengl_20191021/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>



# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define RESET "\033[0m"

# define TRUE 1
# define FALSE 0

# define INIT -1
# define FAIL 1


# define MAP_COMPONENT "01NSEW "
# define UNMOVABLE "1 "
# define MOVABLE "0NSEW"

# define NO 1
# define SO 2
# define WE 3
# define EA 4
# define F 5
# define C 6
# define MAP 7

# define WIDTH 1920
# define HEIGHT 1080
# define M_UNIT 0.1
# define R_UNIT M_PI_4

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define LEFT 123
# define RIGHT 124
# define UP 126
# define DOWN 125
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

typedef unsigned int	t_ui;

typedef struct s_img
{
	int		ceil_color;
	int		floor_color;
}	t_img;

typedef struct s_img2
{
	void			*img;
	unsigned int	*data;
	int				size_l;
	int				bpp;
	int				endian;

}	t_img2;

typedef struct s_player
{
	char	start_point;
	double	y;
	double	x;
	double	dirx;
	double	diry;

}	t_player;

typedef struct s_texture
{
	char			*tex_path_malloc;
	unsigned int	*data;
	t_img2			texture;
	int				width;
	int				height;
}	t_texture;

typedef struct s_map
{
	t_player	player;
	char		*map_value;
	char		**saved_map;
	int			row;
	int			col;

}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		img;
	t_texture	tex[5];

	t_img2		wall;
	t_ui		*wall_data;
	t_img2		screen;
	t_ui		*screen_data;

	double		px;
	double		py;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;

	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;

	double		wallx;
	int			texx;
	int			texy;

	double		step;
	double		texpos;
}	t_game;

#endif
