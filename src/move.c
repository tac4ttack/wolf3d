/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 00:16:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/10/09 00:55:09 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move(t_env *e, char dir)
{
	if (dir == 1)
	{
		PNX = PX + sinl(PDIR * DEG2RAD) * 10;
		PNY = PY - cosl(PDIR * DEG2RAD) * 10;
	}
	if (dir == -1)
	{
		PNX = PX - sinl(PDIR * DEG2RAD) * 10;
		PNY = PY + cosl(PDIR * DEG2RAD) * 10;
	}
	if (NOCLIP == 1)
		noclip_hit_check(e);
	else
		hit_check(e, dir, 0);
}

void	strafe(t_env *e, char dir)
{
	if (dir == 1)
	{
		PNX = PX + sinl((PDIR - 90) * DEG2RAD) * 10;
		PNY = PY - cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (dir == -1)
	{
		PNX = PX - sinl((PDIR - 90) * DEG2RAD) * 10;
		PNY = PY + cosl((PDIR - 90) * DEG2RAD) * 10;
	}
	if (NOCLIP == 1)
		noclip_hit_check(e);
	else
		hit_check(e, dir, -90);
}

void	mouse_look(t_env *e)
{
	long double	angle;
	long double	dif;	

	if (e->mouse_look == 1)
	{
		dif = e->eve.motion.x - (WW / 2);
		angle = dif / 25.;
		PDIR += angle;
		(PDIR < 0 ? PDIR = 360 : 0);
		(PDIR > 360 ? PDIR = 0 : 0);
		SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	}
}

void	look(t_env *e, int delta)
{
	PDIR += delta;
	(PDIR < 0 ? PDIR = 360 : 0);
	(PDIR > 360 ? PDIR = 0 : 0);
}
