/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:16:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 15:55:30 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_env *e, int delta)
{
	int tmp_x;
	int tmp_y;

	tmp_x = PX;
	tmp_y = PY;
	printf("PDIR = %Lf\n", PDIR);
	if (delta == 1)
	{
//		PNX = PX + sinl((PDIR * DEG2RAD)) * 10;
//		PNY = PY - cosl(PDIR * DEG2RAD) * 10;
		PNX = PX + sinl((PDIR * DEG2RAD)) * 10;
		PNY = PY - cosl(PDIR * DEG2RAD) * 10;
	}
	if (delta == -1)
	{
//		PNX = PX - sinl((PDIR * DEG2RAD)) * 10;
//		PNY = PY + cosl(PDIR * DEG2RAD) * 10;
		PNX = PX - sinl((PDIR * DEG2RAD)) * 10;
		PNY = PY + cosl(PDIR * DEG2RAD) * 10;
	}
//	if (read_pixels(e, (PDIR > 0 && PDIR < 180 ? PNX + 10 : PNX - 10), PY) < 1)
		tmp_x = PNX;
//	if (read_pixels(e, PX, (PDIR > 90 && PDIR < 270 ? PNY + 10 : PNY - 10)) < 1)
		tmp_y = PNY;
	PX = floor(tmp_x);
	PY = floor(tmp_y);
	printf("x = %Lf | y = %Lf\n", PX, PY);
}

void	strafe(t_env *e, int delta)
{
	int tmp_x;
	int tmp_y;

	tmp_x = PX;
	tmp_y = PY;
	if (delta == 1)
	{
		PNX = PX + sinl((PDIR - 90) * DEG2RAD) * 10;
		PNY = PY - cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (delta == -1)
	{
		PNX = PX - sinl((PDIR - 90) * DEG2RAD) * 10;
		PNY = PY + cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (read_pixels(e, (PDIR > 0 && PDIR < 180 ? PNX + 10 : PNX - 10), PY) < 1)
		tmp_x = PNX;
	if (read_pixels(e, PX, (PDIR > 90 && PDIR < 270 ? PNY + 10 : PNY - 10)) < 1)
		tmp_y = PNY;
	PX = floorl(tmp_x);
	PY = floorl(tmp_y);
	printf("x = %Lf | y = %Lf\n", PX, PY);
}

void	mouse_look(t_env *e)
{
	long double	angle;
	long double	dif;

	if (e->mouse_look == 1)
	{
		dif = e->eve.motion.x - (WW / 2);
		SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
		angle = dif / 20;
		PDIR += angle;
		(PDIR < 0 ? PDIR = 359 : 0);
		(PDIR > 360 ? PDIR = 1 : 0);
	}
}

void	look(t_env *e, int delta)
{
	PDIR += delta;
	(PDIR == -1 ? PDIR = 359 : 0);
	(PDIR == 361 ? PDIR = 1 : 0);
}
