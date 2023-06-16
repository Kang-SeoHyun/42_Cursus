/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:58 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:34:00 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	cast_one_ray(t_game *g, int x)
{
	t_texture	wall_tex;

	ray_cal_init(g, x);
	dda(g);
	getdrawpoint(g);
	wall_tex = get_texture(g);
	g->wall_data = (t_ui *)mlx_get_data_addr(wall_tex.texture.img, \
	&(wall_tex.texture.bpp), &(wall_tex.texture.size_l), \
	&(wall_tex.texture.endian));
	cal_texture(g, wall_tex);
	drawline(g, wall_tex, x);
}

int	main_loop(t_game *g)
{
	int	x;

	mlx_clear_window(g->mlx, g->win);
	g->screen_data = (t_ui *)mlx_get_data_addr(g->screen.img, &(g->screen.bpp), \
	&(g->screen.size_l), &(g->screen.endian));
	draw_background(g);
	x = -1;
	while (++x < WIDTH)
		cast_one_ray(g, x);
	mlx_put_image_to_window(g->mlx, g->win, g->screen.img, 0, 0);
	return (0);
}
