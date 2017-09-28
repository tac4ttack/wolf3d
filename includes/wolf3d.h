/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 21:26:03 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/28 21:10:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define SDL_MAIN_HANDLED
# include "SDL.h"
# include "SDL_ttf.h"

# define ID         "Wolf3D"
# define BWID       1536
# define BHEI       960

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

typedef struct		s_ldpt
{
	long double		x;
	long double		y;
}                   t_ldpt;

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
	int				hit_side;
	int				hit_val;
	int				height;
}                   t_ray;

typedef struct      s_player
{
	t_ldpt			grid;
	t_ldpt			pix;
	t_ldpt			n_pix;
	long double		fov;
	long double		dir;
	int             height;
	Uint8			spawned;
}                   t_player;

typedef struct      s_map
{
	int             **grid;
	int             col;
	int             lin;
	int				cei;
	int				flo;
}                   t_map;

typedef struct		s_tex
{
	char			*file;
	SDL_Surface		*bitmap;
	SDL_Texture		*sheet;
	SDL_Texture		*shadow;
	SDL_Rect		src;
	SDL_Rect		dst;
	int				x;
	int				y;
}					t_tex;

typedef	struct		s_keys
{
	int				left;
	int				right;
	int				up;
	int				down;
	int				p;
	int				w;
	int				a;
	int				s;
	int				d;
	int				t;
	int				apo;
	int				tab;
}					t_keys;

typedef struct      s_env
{
	SDL_Window      *win;
	SDL_Renderer    *ren;
	SDL_Event       eve;
	SDL_bool        run;
	TTF_Font		*ttf;
	t_keys			keys;
	t_map           map;
	t_ray			r;
	t_player		player;
	t_tex			tex;
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

// fonctions de debug
void				print_info(t_env *e);
void				print_window_events_a(const SDL_Event *ev);
void				print_window_events_b(const SDL_Event *ev);
void				print_key(int key);
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
void				render_crosshair(t_env *e);
int					get_offset(t_env *e, long double hit);

// SDL loop functions
Uint8               main_loop(t_env *env);

// SDL events
void				win_events(t_env *e);
void				keypress_events(t_env *e);
void				keyrelease_events(t_env *e);
void				key_events(t_env *e);
void				mouse_events(t_env *e);

SDL_Texture			*render_text(t_env *e, char *str, SDL_Color color);

void				init_textures(t_env *e);
void				resize_textures(t_env *e);
SDL_Rect			get_texture(t_env *e);
SDL_Rect			get_wall_color(t_env *e);

#endif
