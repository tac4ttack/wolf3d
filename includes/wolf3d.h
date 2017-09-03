/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:26:03 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/04 00:08:29 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <libft.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define SDL_MAIN_HANDLED
# include "SDL.h"

# define ID         "Wolf3D"
# define BWID       1024
# define BHEI       768
# define DEG2RAD	(M_PI / 180)
# define RAD2DEG	(180 / M_PI)
# define WCEN       SDL_WINDOWPOS_CENTERED
# define WFLA       SDL_WINDOW_SHOWN//|SDL_WINDOW_RESIZABLE
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

typedef struct			s_ldpt    // USELESS? float est le seul interet
{
	float			x;
	float			y;
	t_hue				c;
}                   	t_ldpt;

typedef struct      s_rec   // USELESS?
{
	t_ldpt          p;
	int             w;
	int             h;
}                   t_rec;

typedef struct      s_ray
{
	t_ldpt			grid;
	t_ldpt			pix;
	t_ldpt			a;
	t_ldpt			b;
	float		deg;
	float		rad;
	float		h_xa;
	float		h_ya;
	float		v_xa;
	float		v_ya;
	float		dst;
	int				height;
}                   t_ray;

typedef struct      s_player
{
	t_ldpt			grid;
	t_ldpt			pix;
	t_ldpt			n_pix;
	float			fov; // field of view
	float          dir; // view direction
	int             height; // player's height
	int				spawned;
}                   t_player;

typedef struct      s_map
{
	int             **grid;
	int             col; // longuest line length
	int             lin; // number of lines
	int				cei; // ceilling height
	int				flo; // floor height
}                   t_map;

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
	Uint32			*pix;
	int             tile_w;
	int             tile_h;
	int				sc_gap;
	float		deg_step;
	t_map           map;
	t_ray			r;
	t_player		player;
}                   t_env;

// fonctions utilitaires
void				error(void);
void		        env_error(t_env *env, char *str);
void                quit(t_env *env);
void				flush_str_array(t_env *e, char **array);

// fonctions d'initialisation
void                init(t_env *env);
void				init_map(t_env *e);
int					**init_map_grid(t_env *e);
void				init_player(t_env *e);

// fonctions coord
int					search_player_pos(t_env *e);
t_ldpt				grid_to_pixels(t_env *e, int x, int y);
t_ldpt				pixels_to_grid(t_env *e, int x, int y);
int					read_grid(t_env *e, int x, int y);
int					read_pixels(t_env *e, int x, int y);

// fonctions couleurs
t_hue		        set_hue(Uint8 a, Uint8 r, Uint8 g, Uint8 b);
Uint32				set_color(Uint8 a, Uint8 r, Uint8 g, Uint8 b);
Uint32				flip_color_byte_order(int color);

// fonctions dessin SDL
void				sdl_tex_pix_put(t_env *e, int x, int y,  int color);
void				sdl_tex_line(t_env *e, t_ldpt pt1, t_ldpt pt2, int color);
void				sdl_tex_line_ver(t_env *e, t_ldpt p1, t_ldpt p2, int c);
void				sdl_tex_line_hor(t_env *e, t_ldpt p1, t_ldpt p2, int c);

// fonctions de debug
void                PrintWindowEvent(const SDL_Event *ev);
void				map_test(t_env *e);

// fonctions chargement map
int					get_map_grid_val(t_env *e, int x, int y);
void				load_map(t_env *e, char *file);

// fonctions données de map
int					check_data(char *str);
int					count_col(char *data);
void				parse_data(t_env *e, char *data);

// fonctions raycasting
void				draw_frame(t_env *e);	// pour test
void				init_ray(t_env *e, int x);
void				convert_dir(t_env *e);
void				calc_dda(t_env *e);
void				calc_hor_step(t_env *e);
void				calc_ver_step(t_env *e);
void				calc_dst(t_env *e);

// fonction rendering
void	draw_wall_col(t_env *e, int x);

// SDL loop functions
Uint8               main_loop(t_env *env);

// SDL events
void				win_events(t_env *e);
void				keypress_events(t_env *e);

/* Test & play funky funct' */
void  		        Render_Scramble_SDL(t_env *env);
void		        Render_Rand_Rect_SDL(t_env *env);
void		        Render_Fill_Rect(SDL_Renderer *ren, t_rec rec);
void		        Render_Rand_Rect(t_env *env);
void		        Render_Fill_SDLRect(SDL_Renderer *ren, SDL_Rect rec);
void		        Render_Rand_SDLRect(t_env *env);
void				Texture_Draw(t_env *env);
//void				Text_Draw2(t_env *env, float alpha);

# ifdef DEBUG
#  define DBUG 1
# else
#  define DBUG 0
# endif

#endif
