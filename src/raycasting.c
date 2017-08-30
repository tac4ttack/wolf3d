/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 16:24:11 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/30 18:20:18 by fmessina         ###   ########.fr       */
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
	e->r.deg_dir = (e->player.dir - (e->player.fov / 2)) + (x * e->deg_step);
	e->r.height = e->player.height;
	e->r.xa = 0;
	e->r.ya = 0;
	printf("X = %d | player dir = %d\n", x, e->player.dir);
//	printf("r.pix_x = %Lf, r.pix_y = %Lf\nr.dir = %Lf, r.height = %d\n", e->r.pix.x, e->r.pix.y, e->r.deg_dir, e->r.height);
//	printf("e.sc_gap = %d\ne.deg_step = %Lf\n", e->sc_gap, e->deg_step);
}

void	convert_dir(t_env *e)
{
	long double tmp;
	
	tmp = e->r.deg_dir;
	if (tmp == 360 || tmp == 0)
		e->r.rad_dir = 0;
	else
	{
		if (tmp < 0)
			e->r.deg_dir = 360 - fabsl(tmp);
		else if (tmp > 360)
			e->r.deg_dir = fabsl(tmp) - 360;
		e->r.rad_dir = e->r.deg_dir * (M_PI / 180);
	}
	tmp = e->r.rad_dir;
	
	if (e->r.deg_dir == 0 || e->r.deg_dir == 360)
		e->r.ya = -e->tile_h;
	else if ((tmp > (3 * M_PI_2) && tmp <= 2 * M_PI) || (tmp > 0 && tmp < M_PI_2))
		e->r.ya = -e->tile_h;
	else
		e->r.ya = e->tile_h;
		
	e->r.xa = e->r.ya / tan(M_PI_2 - tmp);
//	e->r.xa = 
	printf("new deg_dir is = %Lf\nrad_dir is = %Lf\n", e->r.deg_dir, e->r.rad_dir);
	printf("Ya = %d Xa = %d\n\n", e->r.ya, e->r.xa);

	
	// cas particulier à vérifier: 0/360 90 180 270
	//At 0 and pi, there's no point in searching for horizontal intersections as the ray is horizontal.
	//You'll need to explicitly check for that case.
	//At pi/2 and 3pi/2, the tangent is infinite so 1/tan() should give you zero with floating point math.
	//It will work even if it looks ugly.
	//For vertical intersections, shift the angles by pi/2 and the same reasoning applies.
}

//void	calc_dda(t_env *e)
//{
	
//}
