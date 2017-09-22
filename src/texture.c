/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:05:53 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/22 05:06:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_textures(t_env *e)
{
	int	w,h;
	
	e->tex.src.w = 1;
	e->tex.dst.w = 1;
	e->tex.file = ft_strnew(28);
	e->tex.file = "./assets/textures_sheet.bmp";
	if (!(e->tex.sheet = SDL_LoadBMP(e->tex.file)))
		env_error(e, (char*)SDL_GetError());
	e->tex.sheet2 = SDL_CreateTextureFromSurface(e->ren, e->tex.sheet);





	
//////	
	printf("INIT\nsurface sheet\nwidth = %d | height = %d\n", e->tex.sheet->w, e->tex.sheet->h);
	SDL_QueryTexture(e->tex.sheet2, NULL, NULL, &w, &h);
	printf("INIT\ntexture sheet initialized \nwidth = %d | height = %d\n\n", w, h);
//////
}

void		resize_textures(t_env *e)
{
	SDL_Surface	*tmp;
	SDL_Rect	canvas;
	
	SDL_FreeSurface(e->tex.sheet);
	e->tex.sheet = SDL_CreateRGBSurfaceWithFormat(0, TW * 12, TH * 13,
													32, TEXPIX);
	if (!(tmp = SDL_LoadBMP(e->tex.file)))
		env_error(e, (char*)SDL_GetError());
	canvas.x = 0;
	canvas.y = 0;
	canvas.w = e->tex.sheet->w;
	canvas.h = e->tex.sheet->h;
	SDL_BlitScaled(tmp, NULL, e->tex.sheet, &canvas);
	SDL_FreeSurface(tmp);
	if (e->tex.sheet2 != NULL)
		SDL_DestroyTexture(e->tex.sheet2);
	if (!(e->tex.sheet2 = SDL_CreateTexture(e->ren, TEXPIX, TEXACC,
											TW * 12, TH * 13)))
		env_error(e, "Error creating the texture frame buffer");
	e->tex.sheet2 = SDL_CreateTextureFromSurface(e->ren, e->tex.sheet);
}
