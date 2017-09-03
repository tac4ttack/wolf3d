/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:52:31 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/04 00:08:41 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_wall_col(t_env *e, int x)
{
	float		correct_dst;
	int		height;
	t_ldpt	p1;
	t_ldpt	p2;
	
	p1.x = x;
	p1.y = 0;
	p2.x = x;
//	correct_dst = 0;
	correct_dst = e->r.dst * fabsl(cos((e->player.dir * DEG2RAD) - e->r.rad));
	height = (e->tile_w / correct_dst) * e->sc_gap;
//	height = (e->tile_w / e->r.dst) * e->sc_gap;
	p2.y = (e->w_h / 2) - (height / 2);
	printf("x = %d | dst = %f | correct dst = %f | height = %d\n", x, e->r.dst, correct_dst, height);
	sdl_tex_line(e, p1, p2, 0xAA0000FF);
	p1.y = p2.y + 1;
	p2.y = p1.y + height;
	sdl_tex_line(e, p1, p2, 0xAAFF0000);
	p1.y = p2.y + 1;
	p2.y = e->w_h;
	sdl_tex_line(e, p1, p2, 0xAA00FF00);
}
