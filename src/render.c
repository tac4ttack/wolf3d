/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:52:31 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:40:42 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			get_offset(t_env *e, long double hit)
{
	int		offset;

	if (e->r.hit_side == 3)
		offset = TW - ((int)hit % TW) - 1;
	if (e->r.hit_side == 1)
		offset = (int)hit % TW;
	if (e->r.hit_side == 4)
		offset = TH - ((int)hit % TH) - 1;
	if (e->r.hit_side == 2)
		offset = (int)hit % TH;
	return (offset);
}

void		render_crosshair(t_env *e)
{
	e->tex.src.w = 4;
	e->tex.src.h = 4;
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8));
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 6) + 1;
	e->tex.dst.w = 4;
	e->tex.dst.h = 4;
	e->tex.dst.x = (WW / 2) - 2;
	e->tex.dst.y = (WH / 2) - 2;
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
}

void		render_no_textures(t_env *e, int x)
{
	int		height;

	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 5) + 1;
	e->tex.src.h = 1;
	e->tex.dst.x = x;
	e->tex.dst.y = 0;
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
	e->tex.src = get_wall_color(e);
	e->tex.dst.y = (WH / 2) - (height / 2);
	e->tex.dst.h = height;
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 6) + 1;
	e->tex.dst.y = (WH / 2) + (height / 2);
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
}

void		render_textured(t_env *e, int x)
{
	int		height;

	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 5) + 1;
	e->tex.src.h = 1;
	e->tex.dst.x = x;
	e->tex.dst.y = 0;
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
	e->tex.src = get_texture(e);
	e->tex.src.h = e->tile_h;
	e->tex.dst.y = (WH / 2) - (height / 2);
	e->tex.dst.h = height;
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
	e->tex.src.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
	e->tex.src.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 6) + 1;
	e->tex.src.h = 1;
	e->tex.dst.y = (WH / 2) + (height / 2);
	e->tex.dst.h = (WH / 2) - (height / 2);
	SDL_RenderCopy(e->ren, e->tex.sheet, &e->tex.src, &e->tex.dst);
}

void		render(t_env *e, int x)
{
	if (e->texturing == -1)
		render_no_textures(e, x);
	else
		render_textured(e, x);
}
