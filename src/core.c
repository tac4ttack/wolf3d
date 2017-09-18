/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/18 03:47:01 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init(t_env *e)
{
	e->debug = DBUG;
	e->mouse_look = 1;
	e->texturing = -1;
	WW = BWID;
	WH = BHEI;
	e->ren = NULL;
	e->pix = NULL;
	e->tex = NULL;
	e->win = NULL;
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
	SDL_SetRenderDrawBlendMode(e->ren,SDL_BLENDMODE_BLEND);
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	SDL_ShowCursor(0);
// 	init_textures(e);
	e->run = 1;
}

void	reset_screen(t_env *e)
{
	t_ldpt old;
	
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
	if (!(e->win = SDL_CreateWindow(ID, WCEN, WCEN, WW, WH, WFLA)))
		env_error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1, SDL_RENDERER_SOFTWARE)))
		env_error(e, "Error creating the renderer");
	if (!(e->tex = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, WW, WH)))
		env_error(e, "Error creating the rendering context");
	if (!(e->pix = (Uint32*)malloc(WW * WH * sizeof(Uint32))))
		env_error(e, "Error allocating memory for texture pixels");
	e->player.height = TH / 2;
	e->deg_step = FOV / WW;
	e->sc_gap = (WW / 2) / tanl(M_PI / 6);
	e->run = 1;
	e->player.pix.x = old.x * TW;
	e->player.pix.y = old.y * TH;
	ft_putstr("Tile Width = ");
	ft_putnbr(TW);
	ft_putstr("\nTile Height = ");
	ft_putnbr(TH);
	ft_putchar('\n');
}
