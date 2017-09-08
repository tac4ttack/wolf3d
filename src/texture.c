/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 04:05:53 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/08 04:28:47 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_textures(t_env *e)
{
	SDL_Texture	*txt;
	SDL_Surface *dst;
	SDL_Rect	canvas;
	
	canvas.x = 0;
	canvas.y = 0;
	canvas.w = TW * 6;
	canvas.h = TH * 19;
	dst = SDL_CreateRGBSurfaceWithFormat(0, TW * 6, TH * 19, 32, TEXPIX);
	if (!(dst = SDL_LoadBMP("./assets/wall_sheet.bmp")))
		env_error(e, (char*)SDL_GetError());
	txt = SDL_CreateTextureFromSurface(e->ren, dst);
	SDL_RenderCopy(e->ren, txt, NULL, &canvas);
}

/*
SDL_Surface* SDL_CreateRGBSurface(Uint32 flags,
                                  int    width,
                                  int    height,
                                  int    depth,
                                  Uint32 Rmask,
                                  Uint32 Gmask,
                                  Uint32 Bmask,
                                  Uint32 Amask)




	SDL_Surface *surf;
	SDL_Texture *text;
	SDL_Rect	*holder;
	surf = SDL_LoadBMP("./wall.bmp");
	text = SDL_CreateTextureFromSurface(e->ren, surf);
	holder = (SDL_Rect*)malloc(sizeof(SDL_Rect*));
	printf("TW = %d | TH = %d\n", TW, TH);
	holder->x = 20;
	holder->y = 500;
	holder->w = TW;
	holder->h = TH;
	SDL_RenderCopy(e->ren, text, NULL, holder);
	SDL_RenderPresent(e->ren);
*/
