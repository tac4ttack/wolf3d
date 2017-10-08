/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/10/08 20:54:53 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init(t_env *e)
{
	e->debug = -1;
	e->mouse_look = 1;
	e->texturing = -1;
	e->noclip = -1;
	e->txt_hue.a = 0;
	e->txt_hue.r = 255;
	e->txt_hue.g = 0;
	e->txt_hue.b = 0;
	WW = BWID;
	WH = BHEI;
	e->ren = NULL;
	e->win = NULL;
	TW = WW / 12;
	TH = TW;
	ft_bzero(&e->keys, sizeof(t_keys));
	FOV = 60;
	e->sc_gap = (WW / 2) / tanl((FOV / 2) * DEG2RAD);
	launch_sdl(e);
	e->start_ticks = SDL_GetTicks();
	e->frames = 0;
	init_textures(e);
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	SDL_ShowCursor(0);
	e->run = 1;
}

void		launch_sdl(t_env *e)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		env_error(e, "Error initializing SDL2");
	if (!(e->win = SDL_CreateWindow(ID, WPOS, WPOS, WW, WH, WFLA)))
		env_error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_PRESENTVSYNC)))
		env_error(e, "Error creating the renderer");
	if (TTF_Init() != 0)
		env_error(e, "Error during SDL2 TTF initialization");
	if (!(e->ttf = TTF_OpenFont("./assets/font.ttf", 14)))
		env_error(e, "Error loading game text font");
	SDL_SetRenderDrawBlendMode(e->ren, SDL_BLENDMODE_BLEND);
}

static void	valid_screen_res(t_env *e, int width, int height)
{
	if (width < 640 || height < 384)
	{
		if (width < 640)
			width = 640;
		if (height < 384)
			height = 384;
	}
	else
	{
		width = width >= 2432 ? 2560 : width - (width % 128);
		height = height >= 1187 ? 1315 : height - (height % 128);
	}
	WW = width;
	WH = height;
}

void		reset_screen(t_env *e)
{
	t_ldpt	old;

	old.x = e->player.pix.x / TW;
	old.y = e->player.pix.y / TH;
	e->run = 0;
	valid_screen_res(e, e->eve.window.data1, e->eve.window.data2);
	TW = WW / (WW / 128);
	TH = TW;
	if (e->ren)
		SDL_DestroyRenderer(e->ren);
	if (e->win)
		SDL_DestroyWindow(e->win);
	if (e->tex.sheet)
		SDL_DestroyTexture(e->tex.sheet);
	if (e->ttf)
		TTF_CloseFont(e->ttf);
	launch_sdl(e);
	e->sc_gap = (WW / 2) / tanl((FOV / 2) * DEG2RAD);
	e->run = 1;
	e->player.pix.x = old.x * TW;
	e->player.pix.y = old.y * TH;
}
