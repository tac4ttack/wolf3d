/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:16:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/04 00:25:11 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_env *e, int delta)
{
	if (delta == 1) // haut
	{
		e->player.n_pix.x = e->player.pix.x + sinl((e->player.dir * DEG2RAD)) * 10;
		e->player.n_pix.y = e->player.pix.y - cosl(e->player.dir * DEG2RAD) * 10;
	}
	if (delta == -1) // bas
	{
		e->player.n_pix.x = e->player.pix.x - sinl((e->player.dir * DEG2RAD)) * 10;
		e->player.n_pix.y = e->player.pix.y + cosl(e->player.dir * DEG2RAD) * 10;
	}
	if (read_pixels(e, e->player.n_pix.x, e->player.n_pix.y) != 1)
		{
			e->player.pix.x = e->player.n_pix.x;
			e->player.pix.y = e->player.n_pix.y;
		}
}

//void	strafe(t_env *e, int delta)
//{
//	delta = e;
//}

void	look(t_env *e, int delta)
{
	e->player.dir += delta;	
	(e->player.dir == -1 ? e->player.dir = 359 : 0);
	(e->player.dir == 361 ? e->player.dir = 1 : 0);
}
