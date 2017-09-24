/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:52:31 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/24 11:13:11 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_offset(t_env *e, long double hit, char dir)
{
	int		offset;

	if (dir == 'h')
	{
		if (PDIR >= 90 && PDIR <= 270)
			offset = TW - ((int)hit % TW) - 1;
		else
			offset = (int)hit % TW;
	}
	if (dir == 'v')
	{
		if (PDIR >= 180 && PDIR <= 360)
			offset = TH - ((int)hit % TH) - 1;
		else
			offset = (int)hit % TH;
	}
	return (offset);
}

/*void	render_no_textures(t_env *e, int x)
{
	int		height;
	t_ldpt	p1;
	t_ldpt	p2;
	
	p1.x = x;
	p1.y = 0;
	p2.x = x;
//	e->r.dst *= fabsl(cosl((PDIR - e->r.rad) * DEG2RAD)); // euclidian lsd
	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
	(height > WH ? height = WH : 0);
	p2.y = (WH / 2) - (height / 2);
	sdl_line(e, p1, p2, 0xFF000033);
	p1.y = p2.y;
	p2.y += height;
	sdl_line(e, p1, p2, e->player.pix.c.h);
	p1.y = p2.y;
	p2.y = WH;
	sdl_line(e, p1, p2, 0xFF333333);
}*/

void	render_no_textures(t_env *e, int x)
{
	int			height;
	
	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 5) + 1;
	e->tex.src.h = 1;
	e->tex.dst.x = x;
	e->tex.dst.y = 0;
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
	e->tex.src = get_wall_color(e);
//	e->tex.src.h = e->tile_h;
	e->tex.dst.y = (WH / 2) - (height / 2);
	e->tex.dst.h = height;
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 6) + 1;
//	e->tex.src.h = 1;
	e->tex.dst.y = (WH / 2) + (height / 2);
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
}

void	render_textured(t_env *e, int x)
{
	int			height;
	
//	e->r.dst *= fabsl(cosl((PDIR - e->r.rad) * DEG2RAD)); // euclidian lsd
	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
//	printf("X = %d\n", x);
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 5) + 1;
//	printf("ceilling src.x = %d | src.y = %d\n", e->tex.src.x, e->tex.src.y);
	e->tex.src.h = 1;
	e->tex.dst.x = x;
	e->tex.dst.y = 0;
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
	e->tex.src = get_texture(e);
//	printf("hit_x = %d\nwall src.x = %d | src.y = %d\n", e->r.hit_x, e->tex.src.x, e->tex.src.y);
	e->tex.src.h = e->tile_h;
	e->tex.dst.y = (WH / 2) - (height / 2);
	e->tex.dst.h = height;
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 6) + 1;
//	printf("floor src.x = %d | src.y = %d\n\n", e->tex.src.x, e->tex.src.y);
	e->tex.src.h = 1;
	e->tex.dst.y = (WH / 2) + (height / 2);
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet2, &e->tex.src, &e->tex.dst);
}

void	render(t_env *e, int x)
{
	if (e->texturing == -1)
		render_no_textures(e, x);
	else
		render_textured(e, x);
}
