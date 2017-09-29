/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:00:47 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:10:13 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ldpt	noclip_hit_check(t_env *e)
{
	t_ldpt res;

	if (PNX > (COL * TW) || PNX < 1)
		res.x = PX;
	else
		res.x = PNX;
	if (PNY > (LIN * TH) || PNY < 1)
		res.y = PY;
	else
		res.y = PNY;
	return (res);
}

t_ldpt	hit_check(t_env *e)
{
	t_ldpt res;

	if (read_pixels(e, PNX, PY) > 0)
		res.x = PX;
	else
		res.x = PNX;
	if (read_pixels(e, PX, PNY) > 0)
		res.y = PY;
	else
		res.y = PNY;
	return (res);
}

void	init_player(t_env *e)
{
	if (e)
	{
		e->player.spawned = 0;
		FOV = 60;
		PDIR = 0;
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
