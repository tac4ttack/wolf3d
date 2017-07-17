/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/17 16:47:31 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_sdl(t_env *e)
{
	e->debug = DBUG;
	e->w_w = BWID;
	e->w_h = BHEI;
	e->ren = NULL;
	e->sce = NULL;
	e->tex = NULL;
	e->win = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(e, "Error initializing SDL2");
	if (!(e->win = SDL_CreateWindow(ID, WCEN, WCEN, e->w_w, e->w_h, WFLA)))
		error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1,SDL_RENDERER_SOFTWARE)))
		error(e, "Error creating the renderer");
	if (!(e->tex = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, BWID, BHEI)))
		error(e, "Error creating the render texture");
	if (!(e->sce = (Uint32*)malloc(BWID * BHEI * sizeof(Uint32))))
		error(e, "Error allocating memory for scene");
	e->run = 1;
}
