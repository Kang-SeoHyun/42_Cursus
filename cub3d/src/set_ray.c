/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:34:03 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:34:03 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_background(t_game *g)
{
	int	y;
	int	x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < HEIGHT / 2)
				g->screen_data[y * WIDTH + x] = g->img.ceil_color;
			else if (y > HEIGHT / 2)
				g->screen_data[y * WIDTH + x] = g->img.floor_color;
			else
				g->screen_data[y * WIDTH + x] = 0;
		}
	}
}

void	ray_cal_init(t_game *g, int x)
{
	g->camerax = 2 * x / (double)(WIDTH - 1) - 1;
	g->raydirx = g->dirx + g->planex * g->camerax;
	g->raydiry = g->diry + g->planey * g->camerax;
	g->mapx = (int)(g->px);
	g->mapy = (int)(g->py);
	get_deltadist(g);
	get_sidedist(g);
	g->hit = 0;
}

void	get_deltadist(t_game *g)
{
	if (g->raydiry == 0)
		g->deltadistx = 0;
	else if (g->raydirx == 0)
		g->deltadistx = 1;
	else
		g->deltadistx = fabs(1 / g->raydirx);
	if (g->raydirx == 0)
		g->deltadisty = 0;
	else if (g->raydiry == 0)
		g->deltadisty = 1;
	else
		g->deltadisty = fabs(1 / g->raydiry);
}

void	get_sidedist(t_game *g)
{
	if (g->raydirx < 0)
	{
		g->stepx = -1;
		g->sidedistx = (g->px - g->mapx) * g->deltadistx;
	}
	else
	{
		g->stepx = 1;
		g->sidedistx = (g->mapx + 1.0 - g->px) * g->deltadistx;
	}
	if (g->raydiry < 0)
	{
		g->stepy = -1;
		g->sidedisty = (g->py - g->mapy) * g->deltadisty;
	}
	else
	{
		g->stepy = 1;
		g->sidedisty = (g->mapy + 1.0 - g->py) * g->deltadisty;
	}
}
