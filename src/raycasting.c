/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:24:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 22:49:14 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_ray(t_env *e, int x)
{
//	x++; // a verifier si utile ou non
	e->r.pix.x = e->player.pix.x;
	e->r.pix.y = e->player.pix.y;
	e->r.grid.x = e->player.grid.x;
	e->r.grid.y = e->player.grid.y;
	e->r.deg = (e->player.dir - (e->player.fov / 2)) + (x * e->deg_step);
	printf("init_ray r.deg = %Lf | degstep = %Lf | fov = %Lf | fov/2 = %Lf\n", e->r.deg, e->deg_step, e->player.fov, e->player.fov/2);
	e->r.height = e->player.height;
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
			e->r.deg = 360 - ft_fabs(tmp);
		else if (tmp > 360)
			e->r.deg = ft_fabs(tmp) - 360;
		e->r.rad = e->r.deg * DEG2RAD;
		printf("convert_dir new r.deg = %Lf | r.rad = %Lf\n", e->r.deg, e->r.rad);
	}
}

void	calc_hor_step(t_env *e)
{
	if ((e->r.deg >= 270 && e->r.deg < 360) ||
			(e->r.deg > 0 && e->r.deg <= 90) ||
			e->r.deg == 0 || e->r.deg == 360)
	{
		e->r.h_ya = -e->tile_h;
		e->r.a.y = (floor(e->r.pix.y / e->tile_h) * e->tile_h) - 1;
	}
	else
	{
		e->r.h_ya = e->tile_h;
		e->r.a.y = (floor(e->r.pix.y / e->tile_h) * e->tile_h) + e->tile_h;
	}
	e->r.h_xa = ft_fabs(e->r.h_ya / tanl(M_PI_2 - e->r.rad));
	//	A.x = Px + (Py-A.y)/ft_tan(ALPHA);
	e->r.a.x = e->r.pix.x + ((e->r.pix.y - e->r.a.y) / tanl(M_PI_2 - e->r.rad));
	(e->r.deg > 180 ? e->r.h_xa *= -1 : 0);
//	ft_putendl("hor dda:");
	while(read_pixels(e, e->r.a.x, e->r.a.y) != 1)
	{
//		ft_putendl("hor dda:");
		e->r.a.x += e->r.h_xa;
		e->r.a.y += e->r.h_ya;
	}
}

void	calc_ver_step(t_env *e)
{
	if (e->r.deg >= 0 && e->r.deg < 180)
	{
		e->r.v_xa = e->tile_w;
		e->r.b.x = floor(e->r.pix.x / e->tile_w) * e->tile_w + e->tile_w;
	}
	else
	{
		e->r.v_xa = -e->tile_w;
		e->r.b.x = floor(e->r.pix.x / e->tile_w) * e->tile_w - 1;
	}
	e->r.v_ya = ft_fabs(e->r.v_xa / ft_tan(e->r.rad));
	e->r.b.y = e->r.pix.y + ((e->r.pix.x - e->r.b.x) / ft_tan(e->r.rad));
	if ((e->r.deg > 270 && e->r.deg < 360) ||
			(e->r.deg >= 0 && e->r.deg < 90) ||
			e->r.deg == 0 || e->r.deg == 360)
		e->r.v_ya *= -1;
//	ft_putendl("ver dda:");
	while(read_pixels(e, e->r.b.x, e->r.b.y) != 1)
	{
//		ft_putendl("ver dda:");
		e->r.b.x += e->r.v_xa;
		e->r.b.y += e->r.v_ya;
	}
}

void	calc_dst(t_env *e)
{
	long double h_dst;
	long double v_dst;
	long double diff_x;
	long double diff_y;

	diff_x = e->r.pix.x - e->r.a.x;
	diff_y = e->r.pix.y - e->r.a.y;
	h_dst = sqrt((diff_x * diff_x) + (diff_y * diff_y));
//	h_dst = ft_fabs(e->r.pix.x - e->r.a.x) / cos(M_PI_2 - e->r.rad);
	diff_x = e->r.pix.x - e->r.b.x;
	diff_y = e->r.pix.y - e->r.b.y;
	v_dst = sqrt((diff_x * diff_x) + (diff_y * diff_y));
//	v_dst = ft_fabs(e->r.pix.x - e->r.b.x) / cos(M_PI_2 - e->r.rad);
//	ft_putstr("h_dist = ");
//	ft_putnbr(h_dst);
//	ft_putstr(" | v_dist = ");
//	ft_putnbr(v_dst);
//	ft_putstr("\n");
	if (h_dst < v_dst)
		e->r.dst = h_dst;
	else
		e->r.dst = v_dst;
//	printf("hdst = %Lf | vdst = %Lf | dst = %Lf\n", h_dst, v_dst, e->r.dst);
//	ft_putstr("DST = ");
//	ft_putnbr(e->r.dst);
//	ft_putendl("\n");
}
