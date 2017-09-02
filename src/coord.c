/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:43:02 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/02 22:02:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		search_player_pos(t_env *e)
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

	res.x = 0;
	res.y = 0;
	res.x = (x * e->tile_w) + (e->tile_w / 2);
	res.y = (y * e->tile_h) + (e->tile_h / 2);
	return (res);
}


t_ldpt pixels_to_grid(t_env *e, int x, int y)
{
	t_ldpt res;
	
	res.x = 0;
	res.y = 0;
	res.x = x / e->tile_w;
	res.y = y / e->tile_h;
	return (res);
}

int		read_grid(t_env *e, int x, int y)
{
	int	res;

	res = e->map.grid[y][x];
	return (res);
}

int		read_pixels(t_env *e, int x, int y)
{
	int	res;
	
	res = 1;
//	ft_putstr("base x = ");
//	ft_putnbr(x);
//	ft_putstr(" | base y = ");
//	ft_putnbr(y);
//	ft_putstr("\n");
	if (x >= 0 && y >= 0 && x < e->w_w && y < e->w_h)
	{
		x = x / e->tile_w;
		y = y / e->tile_h;
		res = e->map.grid[y][x];
	}
//	ft_putstr("x = ");
//	ft_putnbr(x);
//	ft_putstr(" | y = ");
//	ft_putnbr(y);
//	ft_putstr("\n\n");
	return (res);
}
