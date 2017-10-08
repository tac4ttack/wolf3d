/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:00:47 by fmessina          #+#    #+#             */
/*   Updated: 2017/10/08 22:46:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		noclip_hit_check(t_env *e)
{
	if (PNX > (COL * TW) || PNX < 1)
		PX = PX;
	else
		PX = PNX;
	if (PNY > (LIN * TH) || PNY < 1)
		PY = PY;
	else
		PY = PNY;
}

void		hit_check(t_env *e, char dir, float strafe)
{
	t_ldpt	test;

	if (dir == 1)
	{
		test.x = PNX + sinl((PDIR + strafe) * DEG2RAD) * 20;
		test.y = PNY - cosl((PDIR + strafe) * DEG2RAD) * 20;
	}
	if (dir == -1)
	{
		test.x = PNX - sinl((PDIR + strafe) * DEG2RAD) * 20;
		test.y = PNY + cosl((PDIR + strafe) * DEG2RAD) * 20;
	}
	if (read_pixels(e, test.x, PY) <= 0)
		PX = PNX;
	if (read_pixels(e, PX, test.y) <= 0)
		PY = PNY;
}

void		init_player(t_env *e)
{
	if (e)
	{
		e->player.spawned = 0;
		PDIR = 0;
		if (get_spawn_pos(e) != 1)
			env_error(e, "Error during initializing player data");
	}
}

int			get_spawn_pos(t_env *e)
{
	int		x;
	int		y;

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
