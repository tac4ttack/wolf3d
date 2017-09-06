/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/06 21:06:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_env *e)
{
	if (e)
	{
		e->map.col = 0;
		e->map.lin = 0;
		e->map.cei = TH;
		e->map.flo = 0;
	}	
}

int		**init_map_grid(t_env *e)
{
	int i;
	int **map;
	
	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * LIN)))
		env_error(e, "Error allocating memory for map grid lines");
	while (i < LIN)
	{
		if (!(map[i] = (int*)malloc(sizeof(int) * COL)))
			env_error(e, "Error allocating memory for map grid cols");
		i++;
	}
	return (map);
}

void	init_player(t_env *e)
{
	if (e)
	{
		e->player.spawned = 0;
		FOV = 60;
		PDIR = 0;
		e->player.height = TH / 2;
		e->deg_step = FOV / WW;
		e->sc_gap = (WW / 2) / tanl(M_PI / 6);
//		printf("sc_gap = %d | ", e->sc_gap);
		if (search_player_pos(e) != 1)
			env_error(e, "Error during initializing player data");
//		printf("player spawn = %d | player x = %f y = %f | player dir = %f \n\n", e->player.spawned, e->player.pix.x, e->player.pix.y, e->player.dir);
	}
}

/* USELESS */
/*svoid	init_texture_pixels(t_env *e)
{
	int	x;
	int	y;
	Uint32	*tmp;
	
	x = 0;
	y = 0;
	tmp = e->pix;
	while (y < e->w_h)
	{
		while (x < e->w_w)
		{
			*tmp=set_color(0,66,66,66);
			tmp++;
			x++;
		}
		x = 0;
		y++;
	}
	SDL_UpdateTexture(e->tex, NULL, e->pix, e->w_w * sizeof (Uint32));
	SDL_RenderCopy(e->ren, e->tex, NULL, NULL);
	SDL_RenderPresent(e->ren);
}*/

void	init(t_env *e)
{
	e->debug = DBUG;
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
	SDL_WarpMouseInWindow(e->win, WW / 2, WH / 2);
	SDL_ShowCursor(0);
	//	init_texture_pixels(e); inutile?
	e->run = 1;
}
