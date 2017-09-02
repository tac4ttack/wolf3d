/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:24:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 00:08:26 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
		e->r.rad = e->r.deg * (M_PI / 180);
	}
}

void	calc_hor_step(t_env *e)
{
	if ((e->r.deg > 270 && e->r.deg < 360) ||
			(e->r.deg >= 0 && e->r.deg < 90) ||
			e->r.deg == 0 || e->r.deg == 360)
	{
		e->r.h_ya = -e->tile_h;
		e->r.a.y = floor(e->r.pix.y / e->tile_h) * e->tile_h - 1;
	}
	else
	{
		e->r.h_ya = e->tile_h;
		e->r.a.y = floor(e->r.pix.y / e->tile_h) * e->tile_h + e->tile_h;
	}
	e->r.h_xa = fabsl(e->r.h_ya / tan(M_PI_2 - e->r.rad));
	e->r.a.x = e->r.pix.x + ((e->r.pix.y - e->r.a.y) / tan(M_PI_2 - e->r.rad));
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
	e->r.v_ya = fabsl(e->r.v_xa / tan(e->r.rad));
	e->r.b.y = e->r.pix.y + ((e->r.pix.x - e->r.b.x) / tan(e->r.rad));
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
	h_dst = sqrt(diff_x * diff_x + diff_y * diff_y);
	diff_x = e->r.pix.x - e->r.b.x;
	diff_y = e->r.pix.y - e->r.b.y;
	v_dst = sqrt(diff_x * diff_x + diff_y * diff_y);
//	ft_putstr("h_dist = ");
//	ft_putnbr(h_dst);
//	ft_putstr(" | v_dist = ");
//	ft_putnbr(v_dst);
//	ft_putstr("\n");
	if (h_dst < v_dst)
		e->r.dst = h_dst;
	else
		e->r.dst = v_dst;
//	ft_putstr("DST = ");
//	ft_putnbr(e->r.dst);
//	ft_putendl("\n");
}
	// cas particulier à vérifier: 0/360 90 180 270
	//At 0 and pi, there's no point in searching for horizontal intersections as the ray is horizontal.
	//You'll need to explicitly check for that case.
	//At pi/2 and 3pi/2, the tangent is infinite so 1/tan() should give you zero with floating point math.
	//It will work even if it looks ugly.
	//For vertical intersections, shift the angles by pi/2 and the same reasoning applies.

/*
calcul dda
sur horizontal puis vertical
	step par step on check la valeur de la case ou tape le rayon
		- fonction pixels to grid
		- fonction read grid
	lorsqu'on tape un mur on s'arrete et on calcul la distance
on compare les 2 distances et on prend la plus courte
*/

	/* test case suivante
			- direction a determiner suivant angle
			-> si mur alors il faut trouver comment calculer la distance
		si pas mur alors on 
	*/

