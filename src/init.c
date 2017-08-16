/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:58:40 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 15:50:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_env *e)
{
	if (e)
	{
		e->map.col = 0;
		e->map.lin = 0;
		e->map.cei = 64;
		e->map.flo = 0;
	}	
}

int		**init_map_grid(t_env *e)
{
	int i;
	int **map;
	
	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * e->map.lin)))
		error(e, "Error allocating memory for map grid lines");
	while (i < e->map.lin)
	{
		if (!(map[i] = (int*)malloc(sizeof(int) * e->map.col)))
			error(e, "Error allocating memory for map grid cols");
		i++;
	}
	return (map);
}

void	init_player(t_env *e)
{
	if (e)
	{
		e->player.fov = 90;
		e->player.dir = 0;
		e->player.height = e->tile_h / 2;
		if (get_player_pos(e) != 0)
			error(e, "Error during initializing player data");
	}
}

void		init(t_env *e)
{
	e->debug = DBUG;
	e->w_w = BWID;
	e->w_h = BHEI;
	e->ren = NULL;
	e->sce = NULL;
	e->tex = NULL;
	e->win = NULL;
	e->tile_w = 64;
	e->tile_h = 64;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		error(e, "Error initializing SDL2");
	if (!(e->win = SDL_CreateWindow(ID, WCEN, WCEN, e->w_w, e->w_h, WFLA)))
		error(e, "Error creating the window");
	if (!(e->ren = SDL_CreateRenderer(e->win, -1,SDL_RENDERER_SOFTWARE)))
		error(e, "Error creating the renderer");
	if (!(e->tex = SDL_CreateTexture(e->ren, TEXPIX, TEXACC, BWID, BHEI)))
		error(e, "Error creating the rendering context");
	if (!(e->sce = (Uint32*)malloc(BWID * BHEI * sizeof(Uint32))))
		error(e, "Error allocating memory for scene");	
	e->run = 1;
}
