/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:05:53 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 23:11:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_textures(t_env *e)
{
	e->tex.src.w = 1;
	e->tex.dst.w = 1;
	if (!(e->tex.bitmap = SDL_LoadBMP("./assets/textures.bmp")))
		env_error(e, NULL);
	if (!(e->tex.shadow = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, 1, 1)))
		env_error(e, "Error creating the shadow buffer");
	e->tex.sheet = SDL_CreateTextureFromSurface(e->ren, e->tex.bitmap);
	SDL_FreeSurface(e->tex.bitmap);
	e->tex.bitmap = NULL;
}

void		resize_textures(t_env *e)
{
	SDL_Surface	*tmp;
	SDL_Rect	canvas;

	e->tex.bitmap = SDL_CreateRGBSurfaceWithFormat(0, TW * 12, TH * 13,
													32, TEXPIX);
	if (!(tmp = SDL_LoadBMP("./assets/textures.bmp")))
		env_error(e, (char*)SDL_GetError());
	canvas.x = 0;
	canvas.y = 0;
	canvas.w = e->tex.bitmap->w;
	canvas.h = e->tex.bitmap->h;
	SDL_BlitScaled(tmp, NULL, e->tex.bitmap, &canvas);
	SDL_FreeSurface(tmp);
	tmp = NULL;
	if (!(e->tex.sheet = SDL_CreateTexture(e->ren, TEXPIX, TEXACC,
											TW * 12, TH * 13)))
		env_error(e, "Error creating the texture sheet buffer");
	e->tex.sheet = SDL_CreateTextureFromSurface(e->ren, e->tex.bitmap);
	SDL_FreeSurface(e->tex.bitmap);
	e->tex.bitmap = NULL;
}

SDL_Rect	get_texture(t_env *e)
{
	SDL_Rect	result;

	result.w = 1;
	if (e->r.hit_val % 12 == 0)
	{
		result.x = ((((e->r.hit_val - 1) % 12)) * TW) + e->r.hit_x;
		result.y = ((e->r.hit_val / 12) - 1) * TH;
	}
	else
	{
		result.x = (((e->r.hit_val % 12) - 1) * TW) + e->r.hit_x;
		result.y = (e->r.hit_val / 12) * TH;
	}
	return (result);
}

SDL_Rect	get_wall_color(t_env *e)
{
	SDL_Rect	result;

	result.w = 1;
	result.h = 1;
	if (e->r.hit_side == 1)
	{
		result.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 2);
		result.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 1) + 1;
	}
	if (e->r.hit_side == 2)
	{
		result.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 5);
		result.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 1) + 1;
	}
	if (e->r.hit_side == 3)
	{
		result.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 2);
		result.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 5) + 1;
	}
	if (e->r.hit_side == 4)
	{
		result.x = (((82 % 12) - 1) * TW) + ((TW / 8) / 2) + ((TW / 8) * 3);
		result.y = ((82 / 12) * TH) + ((TH / 8) / 2) + ((TW / 8) * 1) + 1;
	}
	return (result);
}
