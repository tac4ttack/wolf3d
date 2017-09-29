/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 15:43:02 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:33:48 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_ldpt		grid_to_pixels(t_env *e, int x, int y)
{
	t_ldpt	res;

	res.x = 0;
	res.y = 0;
	res.x = (x * TW) + (TW / 2);
	res.y = (y * TH) + (TH / 2);
	return (res);
}

t_ldpt		pixels_to_grid(t_env *e, int x, int y)
{
	t_ldpt	res;

	res.x = 0;
	res.y = 0;
	res.x = x / TW;
	res.y = y / TH;
	return (res);
}

int			read_grid(t_env *e, int x, int y)
{
	int		res;

	res = e->map.grid[y][x];
	return (res);
}

int			read_pixels(t_env *e, int x, int y)
{
	int		res;

	res = 1;
	if (x >= 0 && y >= 0 && x < COL * TW && y < LIN * TH)
	{
		x = x / TW;
		y = y / TH;
		res = e->map.grid[y][x];
	}
	return (res);
}
