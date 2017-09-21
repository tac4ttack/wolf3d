/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 21:52:31 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/21 04:25:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_no_textures(t_env *e, int x)
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
}

void	render_textured(t_env *e, int x)
{
	int			height;
	
	e->r.dst *= cosl((PDIR - e->r.deg) * DEG2RAD);
	height = (TW / e->r.dst) * e->sc_gap;
//	(height > WH ? height = WH : 0);
	
//	config rect plafond
	e->textures.src.x = 1232;
	e->textures.src.y = 866;
	e->textures.src.w = 1;
	e->textures.src.h = 1;
	e->textures.dst.x = x;
	e->textures.dst.y = 0;
	e->textures.dst.w = 1;
	e->textures.dst.h = (WH / 2) - (height / 2);
	SDL_BlitScaled(e->textures.sheet, &e->textures.src, e->textures.buffer, &e->textures.dst); // blit plafond
//	config rect mur
	e->textures.src.x = (e->r.hit_val * 128) + e->r.hit_x;
	e->textures.src.y = 0;
	e->textures.src.w = 1;
	e->textures.src.h = 128;
	e->textures.dst.x = x;
	e->textures.dst.y = (WH / 2) - (height / 2);
	e->textures.dst.w = 1;
	e->textures.dst.h = height;
	SDL_BlitScaled(e->textures.sheet, &e->textures.src, e->textures.buffer, &e->textures.dst); // blit mur
//	config rect sol
	e->textures.src.x = 1152;
	e->textures.src.y = 768;
	e->textures.src.w = 1;
	e->textures.src.h = 1;
	e->textures.dst.x = x;
	e->textures.dst.y = (WH / 2) + (height / 2);
	e->textures.dst.w = 1;
	e->textures.dst.h = (WH / 2) - (height / 2);
	SDL_BlitScaled(e->textures.sheet, &e->textures.src, e->textures.buffer, &e->textures.dst); // blit sol
}

void	render(t_env *e, int x)
{
	if (e->texturing == -1)
		render_no_textures(e, x);
	else
		render_textured(e, x);
}
