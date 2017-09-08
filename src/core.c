/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/08 04:06:39 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init(t_env *e)
{
	e->debug = DBUG;
	WW = BWID;
	WH = BHEI;
	e->ren = NULL;
	e->pix = NULL;
	e->tex = NULL;
	e->win = NULL;
	e->texturing = -1;
	TW = WW / 12;
	TH = TW;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		env_error(e, "Error initializing SDL2");
	if (!(e->win = SDL_CreateWindow(ID, WCEN, WCEN, WW, WH, WFLA)))
		env_error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_SOFTWARE)))
		env_error(e, "Error creating the renderer");
	if (!(e->tex = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, WW, WH)))
		env_error(e, "Error creating the rendering context");
	if (!(e->pix = (Uint32*)malloc(WW * WH * sizeof(Uint32))))
		env_error(e, "Error allocating memory for texture pixels");
	if (init_textures(e) != 0)
		env_error(e, "Error initalizing textures");
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	SDL_ShowCursor(0);
	e->run = 1;
}
