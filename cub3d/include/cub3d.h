/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:32:58 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:06 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"


/* draw_line */
void		dda(t_game *g);
void		getdrawpoint(t_game *g);
void		drawline(t_game *g, t_texture wall_tex, int x);

/* exit.c */
void		error_exit(char *message);
void		error_exit(char *message);
void		exit_error_with_free(t_game *game, char *message);
int			press_exit(t_game *game);

/* generate_map.c */
void		set_player_position(t_map *map, int col, int row);
int			set_map_component(t_map *map, int col, int row);
void		set_map(t_map *map);
void		get_map(t_map *map);
void		generate_map(t_map *map);

/* get_type.c */
int			get_type_of_component(char *line);
int			get_type_of_color(char *line);
int			get_type_of_map(char *line);
int			get_type(char *line);

/* get_value.c */
char		*get_value_of_addr(char *line);
int			get_value_of_color(char *line);
char		*get_value_of_map(t_map *map, char *line);
bool		get_value_of_path(char *path, t_game *game, int idx);

/* init.c */
void		init_game(t_game *game, int fd);
void		init_coordinates(t_game *g);
int			init_window(t_game *game);
void		init_img(t_game *game);

/* input_key.c */
int			moveable(t_game *game, double nx, double ny);
void		parallel_move(t_game *g, double angle);
void		rotate_move(t_game *g, double angle);
int			deal_key(int key_code, t_game *game);

/* raycast.c */
void		cast_one_ray(t_game *g, int x);
int			main_loop(t_game *g);

/* set_ray.c */
void		draw_background(t_game *g);
void		ray_cal_init(t_game *g, int x);
void		get_deltadist(t_game *g);
void		get_sidedist(t_game *g);

/* set_texture.c */
void		cal_texture(t_game *g, t_texture wall_tex);
t_texture	get_texture(t_game *g);

/* set_type.c */
void		set_type_of_component(t_game *game, int type, char *line);
void		set_type_of_color(t_img *img, int type, char *line);
void		set_type_of_map(t_map *map, t_game *game, char *line);
void		set_type(t_game *game, int type, char *line);

/* set_value.c */
int			set_value_of_element(char *value_line, int *idx);
int			set_value_of_color(char *value_line);

/* validate.c */
bool		is_valid_extention(char *file_name, char *extension);
bool		is_contain(char *str, char c);
void		check_saved_component(t_game *game);
void		check_color_value(char *line);

/* main.c */
void		free_all_data(t_game *game, int idx);

#endif
