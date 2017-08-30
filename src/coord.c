/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:43:02 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/30 15:00:29 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		get_player_pos(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < e->map.lin)
	{
		while (x < e->map.col)
		{
			if (e->map.grid[y][x] == 9)
			{
				e->player.spawned = 1;
				e->player.grid.x = x;
				e->player.grid.y = y;
				e->player.pix.x = (x * e->tile_w) + (e->tile_w / 2);
				e->player.pix.y = (y * e->tile_h) + (e->tile_h / 2);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (e->player.spawned);
}

t_ldpt	grid_to_pixels(t_env *e, int x, int y)
{
	t_ldpt res;

	res.x = (x * e->tile_w) + (e->tile_w / 2);
	res.y = (y * e->tile_h) + (e->tile_h / 2);
	return (res);
}
