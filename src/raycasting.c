/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:24:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/22 05:18:46 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_ray(t_env *e, int x)
{
	RX = PX;
	RY = PY;
	RGX = PGX;
	RGY = PGY;
	e->r.deg = (PDIR - (FOV / 2.0)) + (x * e->deg_step);
	e->r.height = e->player.height;
	e->r.hit_x = 0;
	e->r.h_xa = 0;
	e->r.h_ya = 0;
	e->r.v_xa = 0;
	e->r.v_ya = 0;
}

void	convert_dir(t_env *e)
{
	long double tmp;

	tmp = e->r.deg;
	if (tmp == 360 || tmp == 0)
		e->r.rad = 0;
	else
	{
		if (tmp < 0)
			e->r.deg = 360 - fabsl(tmp);
		else if (tmp > 360)
			e->r.deg = fabsl(tmp) - 360;
		e->r.rad = e->r.deg * DEG2RAD;
	}
}

void	calc_hor_step(t_env *e)
{
	if ((e->r.deg >= 270 && e->r.deg < 360) ||
			(e->r.deg > 0 && e->r.deg <= 90) ||
			e->r.deg == 0 || e->r.deg == 360)
	{
		e->r.h_ya = -TH;
		e->r.a.y = (floorl(RY / TH) * TH) - 0.00001;
	}
	else
	{
		e->r.h_ya = TH;
		e->r.a.y = (floorl(RY / TH) * TH) + TH;
	}
	e->r.h_xa = fabsl(e->r.h_ya / tanl(M_PI_2 - e->r.rad));
	e->r.a.x = RX + ((RY - e->r.a.y) / tanl(M_PI_2 - e->r.rad));
	(e->r.deg > 180 ? e->r.h_xa *= -1 : 0);
	while (read_pixels(e, e->r.a.x, e->r.a.y) < 1)
	{
		e->r.a.x += e->r.h_xa;
		e->r.a.y += e->r.h_ya;
	}
}

void	calc_ver_step(t_env *e)
{
	if (e->r.deg >= 0 && e->r.deg < 180)
	{
		e->r.v_xa = TW;
		e->r.b.x = floorl(RX / TW) * TW + TW;
	}
	else
	{
		e->r.v_xa = -TW;
		e->r.b.x = floorl(RX / TW) * TW - 0.00001;
	}
	e->r.v_ya = fabsl(e->r.v_xa / tanl(e->r.rad));
	e->r.b.y = RY + ((RX - e->r.b.x) / tanl(e->r.rad));
	if ((e->r.deg > 270 && e->r.deg < 360) || (e->r.deg >= 0 && e->r.deg < 90)
		|| e->r.deg == 0 || e->r.deg == 360)
		e->r.v_ya *= -1;
	while (read_pixels(e, e->r.b.x, e->r.b.y) < 1)
	{
		e->r.b.x += e->r.v_xa;
		e->r.b.y += e->r.v_ya;
	}
}

void	calc_dst(t_env *e)
{
	long double h_dst;
	long double v_dst;

	h_dst = sqrtl(((RX - e->r.a.x) * (RX - e->r.a.x))
				+ ((RY - e->r.a.y) * (RY - e->r.a.y)));
	v_dst = sqrtl(((RX - e->r.b.x) * (RX - e->r.b.x))
				+ ((RY - e->r.b.y) * (RY - e->r.b.y)));
	if (h_dst < v_dst)
	{
		e->r.dst = h_dst;
		e->player.pix.c.h = 0xffff0000;
		e->r.hit_x = (int)e->r.a.x % TW;
		e->r.hit_val = read_pixels(e, e->r.a.x, e->r.a.y);
		(int)e->r.a.y % TW > 0.5 ? e->player.pix.c.h = 0xffff9900 : 0;
	}
	else
	{
		e->r.dst = v_dst;
		e->player.pix.c.h = 0xff00ff00;
		e->r.hit_x = (int)e->r.b.y % TH;
		e->r.hit_val = read_pixels(e, e->r.b.x, e->r.b.y);
		(int)e->r.b.x % TH > 0.5 ? e->player.pix.c.h = 0xff00ff99 : 0;
	}
}
