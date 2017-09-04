/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:52:31 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/04 22:07:32 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_wall_col(t_env *e, int x)
{
	int		height;
	t_ldpt	p1;
	t_ldpt	p2;
	
	p1.x = x;
	p1.y = 0;
	p2.x = x;
//	e->r.dst *= fabs(cos((e->player.dir - e->r.rad) * DEG2RAD)); // euclidian lsd
	e->r.dst *= fabs(cos((e->player.dir - e->r.deg) * DEG2RAD));
	height = (e->tile_w / e->r.dst) * e->sc_gap;
	(height > e->w_h ? height = e->w_h - 1 : 0);
	p2.y = (e->w_h / 2) - (height / 2);
//	printf("x = %d | dst = %f | correct dst = %f | height = %d\n", x, e->r.dst, correct_dst, height);
	sdl_tex_line(e, p1, p2, 0x00000033);
	p1.y = p2.y;
	p2.y += height;
	sdl_tex_line(e, p1, p2, e->player.pix.c.h); //e->player.pix.c.h 0xffff0000
	p1.y = p2.y;
	p2.y = e->w_h;
	sdl_tex_line(e, p1, p2, 0x00333333);
}
