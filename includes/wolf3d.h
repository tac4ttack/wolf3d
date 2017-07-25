/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:26:03 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/25 19:42:09 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdlib.h>

# define SDL_MAIN_HANDLED
# include "SDL.h"

# include <stdio.h> // do no forget to remove

# define ID         "Wolf3D"
# define BWID       1024
# define BHEI       768
# define WCEN       SDL_WINDOWPOS_CENTERED
# define WFLA       SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE
# define TEXPIX     SDL_PIXELFORMAT_ARGB8888
# define TEXACC		SDL_TEXTUREACCESS_STREAMING

typedef struct      s_hue // ARGB8888 Pixels format
{
	Uint8           r;
	Uint8           g;
	Uint8           b;
	Uint8           a;
	Uint32          h;
}                   t_hue;

typedef struct      s_pt    // USELESS? float est le seul interet
{
	float           x;
	float           y;
	t_hue           c;
}                   t_pt;

typedef struct      s_rec   // USELESS?
{
	t_pt            p;
	int             w;
	int             h;
}                   t_rec;

typedef struct      s_map
{
	int             **grid;
	int             col;
	int             row;
	int				cei;
	int				grd;
	int             tile_w;
	int             tile_h;
}                   t_map;

typedef struct      s_player
{
	int             pos_x;
	int             pos_y;
	int				fov;
	int             dir;
	int             height;
}                   t_player;


typedef struct      s_env
{
	SDL_Window      *win;
	SDL_Renderer    *ren;
	SDL_Texture     *tex;
	SDL_Event       eve;
	SDL_bool        run;
	Uint8           debug;
	Uint16          w_w;
	Uint16          w_h;
	Uint32			*sce;
	t_map           *map;
	t_player		*player;
}                   t_env;

Uint32		        set_color(Uint8 a, Uint8 r, Uint8 g, Uint8 b);
void		        error(t_env *env, char *str);
void                quit(t_env *env);
void				flush_str_array(t_env *e, char **array);
void                init_sdl(t_env *env);
t_map				*init_map(void);
Uint8               main_loop(t_env *env);

/* Test & play funky funct' */
void  		        Render_Scramble_SDL(t_env *env);
void		        Render_Rand_Rect_SDL(t_env *env);
void		        Render_Fill_Rect(SDL_Renderer *ren, t_rec rec);
void		        Render_Rand_Rect(t_env *env);
void		        Render_Fill_SDLRect(SDL_Renderer *ren, SDL_Rect rec);
void		        Render_Rand_SDLRect(t_env *env);
void				Text_Draw(t_env *env);
void				Text_Draw2(t_env *env, float alpha);

void                PrintWindowEvent(const SDL_Event *ev);

# ifdef DEBUG
#  define DBUG 1
# else
#  define DBUG 0
# endif

#endif
