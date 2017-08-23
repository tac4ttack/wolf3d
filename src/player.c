/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:43:02 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/23 16:47:07 by fmessina         ###   ########.fr       */
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
				e->player.pos_x = (x * e->tile_w) + (e->tile_w / 2);
				e->player.pos_y = (y * e->tile_h) + (e->tile_h / 2);
			}
			x++;
		}
		y++;
		x = 0;
	}
	if (e->player.spawned == 1)
		return (0);
	else
		return (1);
}
