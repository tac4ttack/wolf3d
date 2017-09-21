/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:05:53 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/21 02:34:45 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_textures(t_env *e)
{
	e->textures.dst.x = 0;
	e->textures.dst.y = 0;
	e->textures.dst.w = 1;
	e->textures.dst.h = 0;
	e->textures.src.x = 0;
	e->textures.src.y = 0;
	e->textures.src.w = 1;
	e->textures.src.h = 0;
	e->textures.file = ft_strnew(28);
	e->textures.file = "./assets/textures_sheet.bmp";
	if (!(e->textures.buffer = SDL_CreateRGBSurfaceWithFormat(0, WW, WH, 32, TEXPIX)))
		env_error(e, "Error creating the texture frame buffer");
	e->textures.sheet = SDL_CreateRGBSurfaceWithFormat(0, TW * 12, TH * 13, 32, TEXPIX);
	if (!(e->textures.sheet = SDL_LoadBMP(e->textures.file)))
		env_error(e, (char*)SDL_GetError());
//	if (!(e->textures.buf = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, WW, WH)))
//		env_error(e, "Error creating the texture frame buffer");
//	e->textures.text_sheet = SDL_CreateTextureFromSurface(e->ren, e->textures.surf_tmp);
}

void		resize_textures(t_env *e)
{
	if (e->textures.buffer)
		SDL_FreeSurface(e->textures.buffer);
	if (!(e->textures.buffer = SDL_CreateRGBSurfaceWithFormat(0, WW, WH, 32, TEXPIX)))
		env_error(e, "Error creating the texture frame buffer");
	if (e->textures.sheet)
		SDL_FreeSurface(e->textures.sheet);
	e->textures.sheet = SDL_CreateRGBSurfaceWithFormat(0, TW * 12, TH * 13, 32, TEXPIX);
	if (!(e->textures.sheet = SDL_LoadBMP(e->textures.file)))
		env_error(e, (char*)SDL_GetError());
//	if (!(e->textures.buf = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, WW, WH)))
//		env_error(e, "Error creating the texture frame buffer");
//	e->textures.text_sheet = SDL_CreateTextureFromSurface(e->ren, e->textures.surf_tmp);
}
