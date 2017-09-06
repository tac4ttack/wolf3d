/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:16:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/06 20:55:44 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_env *e, int delta)
{
	if (delta == 1) // haut
	{
		PNX = PX + sinl((PDIR * DEG2RAD)) * 10;
		PNY = PY - cosl(PDIR * DEG2RAD) * 10;
	}
	if (delta == -1) // bas
	{
		PNX = PX - sinl((PDIR * DEG2RAD)) * 10;
		PNY = PY + cosl(PDIR * DEG2RAD) * 10;
	}
	if (read_pixels(e, PNX, PNY) != 1)
		{
			PX = PNX;
			PY = PNY;
		}
}

void	strafe(t_env *e, int delta)
{
	if (delta == 1) // gauche
	{
		PNX = PX + sinl(((PDIR - 90) * DEG2RAD)) * 10;
		PNY = PY - cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (delta == -1) // droite
	{
		PNX = PX - sinl(((PDIR - 90) * DEG2RAD)) * 10;
		PNY = PY + cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (read_pixels(e, PNX, PNY) != 1)
		{
			PX = PNX;
			PY = PNY;
		}
}

void	mouse_look(t_env *e)
{
	long double	angle;
	long double	dif;

	dif = e->eve.motion.x - (WW / 2);
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	angle = dif / 20;
	PDIR += angle;
	(PDIR < 0 ? PDIR = 359 : 0);
	(PDIR > 360 ? PDIR = 1 : 0);
//	printf("player dir = %Lf | mouse angle = %Lf\n", PDIR, angle);
}

void	look(t_env *e, int delta)
{
	PDIR += delta;	
	(PDIR == -1 ? PDIR = 359 : 0);
	(PDIR == 361 ? PDIR = 1 : 0);
}
