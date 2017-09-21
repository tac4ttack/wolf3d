/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:26:03 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/21 04:38:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SDL_MAIN_HANDLED
# include "SDL.h"
# include "SDL_ttf.h"

# define ID         "Wolf3D"
# define BWID       1600
# define BHEI       1050

# define DEG2RAD	(M_PI / 180)
# define RAD2DEG	(180 / M_PI)
# define I			(int)
# define FT			(float)
# define D			(double)
# define LD			(long double)

# define TH			e->tile_h
# define TW			e->tile_w
# define WW			e->w_w
# define WH			e->w_h
# define COL		e->map.col
# define LIN		e->map.lin
# define FOV		e->player.fov
# define PDIR		e->player.dir
# define PX			e->player.pix.x
# define PY			e->player.pix.y
# define PNX		e->player.n_pix.x
# define PNY		e->player.n_pix.y
# define PGX		e->player.grid.x
# define PGY		e->player.grid.y
# define RX			e->r.pix.x
# define RY			e->r.pix.y
# define RGX		e->r.grid.x
# define RGY		e->r.grid.y

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

typedef struct		s_ldpt    // USELESS? long double est le seul interet
{
	long double		x;
	long double		y;
	t_hue			c;
}                   t_ldpt;

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
	long double		deg;
	long double		rad;
	long double		h_xa;
	long double		h_ya;
	long double		v_xa;
	long double		v_ya;
	long double		dst;
	int				hit_x;
	int				hit_val;
	int				height;
}                   t_ray;

typedef struct      s_player
{
	t_ldpt			grid;
	t_ldpt			pix;
	t_ldpt			n_pix;
	long double		fov; // field of view
	long double		dir; // view direction
	int             height; // player's height
	Uint8			spawned;
}                   t_player;

typedef struct      s_map
{
	int             **grid;
	int             col; // longuest line length
	int             lin; // number of lines
	int				cei; // ceilling height
	int				flo; // floor height
}                   t_map;

typedef struct		s_tex
{
	char			*file;
	SDL_Surface		*sheet;
	SDL_Surface		*buffer;
	SDL_Texture		*frame;
	SDL_Rect		src;
	SDL_Rect		dst;
	int				x;
	int				y;
}					t_tex;

typedef struct      s_env
{
	SDL_Window      *win;
	SDL_Renderer    *ren;
	SDL_Texture     *tex;
	SDL_Event       eve;
	SDL_bool        run;
	TTF_Font		*ttf;
	t_map           map;
	t_ray			r;
	t_player		player;
	t_tex			textures;
	Uint32			*pix;
	Uint16          w_w;
	Uint16          w_h;
	int             tile_w;
	int             tile_h;
	int				sc_gap;
	long double		deg_step;
	int				debug;
	int				texturing;
	int				mouse_look;			
}                   t_env;

// fonctions utilitaires
void				error(void);
void		        env_error(t_env *env, char *str);
void                quit(t_env *env);
void				flush_str_array(t_env *e, char **array);

// fonctions d'initialisation
void                init(t_env *env);
//void				init_map(t_env *e);
void				launch_sdl(t_env *e);
int					**init_map_grid(t_env *e);
void				init_player(t_env *e);
void				reset_screen(t_env *e);

// fonctions coord
int					get_spawn_pos(t_env *e);
t_ldpt				grid_to_pixels(t_env *e, int x, int y);
t_ldpt				pixels_to_grid(t_env *e, int x, int y);
int					read_grid(t_env *e, int x, int y);
int					read_pixels(t_env *e, int x, int y);

// fonctions couleurs
t_hue		        set_hue(Uint8 a, Uint8 r, Uint8 g, Uint8 b);
Uint32				set_color(Uint8 a, Uint8 r, Uint8 g, Uint8 b);
Uint32				flip_color_byte_order(int color);

// fonctions dessin SDL
void				sdl_pix_put(t_env *e, int x, int y,  int color);
void				sdl_line(t_env *e, t_ldpt pt1, t_ldpt pt2, int color);
void				sdl_line_ver(t_env *e, t_ldpt p1, t_ldpt p2, int c);
void				sdl_line_hor(t_env *e, t_ldpt p1, t_ldpt p2, int c);

// fonctions de debug
void				print_info(t_env *e);
void				print_window_events_a(const SDL_Event *ev);
void				print_window_events_b(const SDL_Event *ev);
void				map_test(t_env *e);

// fonctions chargement map
void				load_map(t_env *e, char *file);
void				load_raw_map(t_env *e);

// fonctions données de map
int					check_data(char *str);
int					count_col(char *data);
void				parse_data(t_env *e, char *data);

// fonction deplacement joueur
void				move(t_env *e, int delta);
void				strafe(t_env *e, int delta);
void				look(t_env *e, int delta);
void				mouse_look(t_env *e);

// fonctions raycasting
void				draw_frame(t_env *e);	// pour test
void				init_ray(t_env *e, int x);
void				convert_dir(t_env *e);
void				calc_dda(t_env *e);
void				calc_hor_step(t_env *e);
void				calc_ver_step(t_env *e);
void				calc_dst(t_env *e);

// fonction rendering
void				render(t_env *e, int x);
void				render_no_textures(t_env *e, int x);
void				render_textures(t_env *e, int x);

// SDL loop functions
Uint8               main_loop(t_env *env);

// SDL events
void				win_events(t_env *e);
void				keypress_events(t_env *e);
void				mouse_events(t_env *e);

SDL_Texture			*render_text(t_env *e, char *str, SDL_Color color);

void				init_textures(t_env *e);
void				resize_textures(t_env *e);

/* Test & play funky funct'
void  		        Render_Scramble_SDL(t_env *env);
void		        Render_Rand_Rect_SDL(t_env *env);
void		        Render_Fill_Rect(SDL_Renderer *ren, t_rec rec);
void		        Render_Rand_Rect(t_env *env);
void		        Render_Fill_SDLRect(SDL_Renderer *ren, SDL_Rect rec);
void		        Render_Rand_SDLRect(t_env *env);
void				Texture_Draw(t_env *env);
//void				Text_Draw2(t_env *env, long double alpha);
*/

#endif
