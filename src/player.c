/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:00:47 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/27 12:50:54 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_player(t_env *e)
{
	if (e)
	{
		e->player.spawned = 0;
		FOV = 60;
		PDIR = 0;
		e->player.height = TH / 2;
		e->deg_step = FOV / WW;
		e->sc_gap = (WW / 2) / tanl(M_PI / 6);
		if (get_spawn_pos(e) != 1)
			env_error(e, "Error during initializing player data");
	}
}

int		get_spawn_pos(t_env *e)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < LIN && e->player.spawned != 1)
	{
		while (x < COL && e->player.spawned != 1)
		{
			if (e->map.grid[y][x] == -1)
			{
				e->player.spawned = 1;
				e->player.grid.x = x;
				e->player.grid.y = y;
				PX = (x * TW) + (TW / 2);
				PY = (y * TH) + (TH / 2);
			}
			x++;
		}
		y++;
		x = 0;
	}
	return (e->player.spawned);
}
