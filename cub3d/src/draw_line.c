/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsong <gsong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:33:15 by gsong             #+#    #+#             */
/*   Updated: 2023/06/10 16:33:16 by gsong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	dda(t_game *g)
{
	while (g->hit == 0)
	{
		if (g->sidedistx < g->sidedisty)
		{
			g->sidedistx += g->deltadistx;
			g->mapx += g->stepx;
			g->side = 0;
		}
		else
		{
			g->sidedisty += g->deltadisty;
			g->mapy += g->stepy;
			g->side = 1;
		}
		if (g->map.saved_map[g->mapx][g->mapy] > '0')
			g->hit = 1;
	}
	if (g->side == 0)
		g->perpwalldist = (g->mapx - g->px + (1 - g->stepx) / 2) / g->raydirx;
	else
		g->perpwalldist = (g->mapy - g->py + (1 - g->stepy) / 2) / g->raydiry;
}

void	getdrawpoint(t_game *g)
{
	g->lineheight = (int)(HEIGHT / g->perpwalldist);
	g->drawstart = (-1 * g->lineheight / 2) + (HEIGHT / 2);
	if (g->drawstart < 0)
		g->drawstart = 0;
	g->drawend = g->lineheight / 2 + HEIGHT / 2;
	if (g->drawend >= HEIGHT)
		g->drawend = HEIGHT - 1;
}

void	drawline(t_game *g, t_texture wall_tex, int x)
{
	int	color;
	int	y;

	y = g->drawstart - 1;
	while (++y < g->drawend)
	{
		g->texy = (int)(g->texpos) & (wall_tex.height - 1);
		g->texpos += g->step;
		color = g->wall_data[wall_tex.height * g->texy + g->texx];
		if (g->side == 1)
			color = (color >> 1) & 8355711;
		g->screen_data[y * WIDTH + x] = color;
	}
}
