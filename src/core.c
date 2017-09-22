/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/22 02:03:46 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		launch_sdl(t_env *e)
{
	if (!(e->win = SDL_CreateWindow(ID, WCEN, WCEN, WW, WH, WFLA)))
		env_error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_PRESENTVSYNC)))
		env_error(e, "Error creating the renderer");
	if (!(e->buf = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, WW, WH)))
		env_error(e, "Error creating the rendering context");
	if (!(e->pix = (Uint32*)malloc(WW * WH * sizeof(Uint32))))
		env_error(e, "Error allocating memory for texture pixels");
	SDL_SetRenderDrawBlendMode(e->ren, SDL_BLENDMODE_BLEND);
}

void		init(t_env *e)
{
	e->debug = -1;
	e->mouse_look = 1;
	e->texturing = -1;
	WW = BWID;
	WH = BHEI;
	e->ren = NULL;
	e->pix = NULL;
	e->buf = NULL;
	e->win = NULL;
	TW = WW / 12;
	TH = TW;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		env_error(e, "Error initializing SDL2");
	launch_sdl(e);
	init_textures(e);
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	SDL_ShowCursor(0);
	e->run = 1;
}

void		reset_screen(t_env *e)
{
	t_ldpt	old;

	old.x = e->player.pix.x / TW;
	old.y = e->player.pix.y / TH;
	e->run = 0;
	WW = e->eve.window.data1;
	WH = e->eve.window.data2;
	TW = WW / 12;
	TH = TW;
	if (e->ren)
		SDL_DestroyRenderer(e->ren);
	if (e->win)
		SDL_DestroyWindow(e->win);
	if (e->pix)
		free(e->pix);
	launch_sdl(e);
	e->player.height = TH / 2;
	e->deg_step = FOV / WW;
	e->sc_gap = (WW / 2) / tanl(M_PI / 6);
	e->run = 1;
	e->player.pix.x = old.x * TW;
	e->player.pix.y = old.y * TH;
}
