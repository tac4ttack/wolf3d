/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 12:25:55 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:33:17 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/includes/libft.h"
# include <math.h>

# define ESCAPE		65307
# define UP			65362
# define RIGHT		65363
# define DOWN		65364
# define LEFT		65361
# define D_LEFT		97
# define D_RIGHT	100
# define AVANCER	119
# define RECULER	115
# define CIEL		0x0D0D0D
# define SOL		0x585561
# define MUR_N		0xB92C39
# define MUR_S		0x401313
# define MUR_O		0x2A2C59
# define MUR_E		0x91F2E9
# define PI			3.14159265
# define WIN_X		1280
# define WIN_Y		800
# define ALPHA		0.046875
# define X			2
# define Y			20

typedef struct		s_ray
{
	double			xa;
	double			ya;
	double			point_x;
	double			point_y;
	int				x;
	int				y;
}					t_ray;

typedef struct		s_pos
{
	float			Px;
	float			Py;
	int				a;
}					t_pos;

typedef struct		s_data
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data;
	int				endian;
	int				sizeline;
	int				bpp;
	t_pos			pos;
	int				**map;
	int				save[7];
	int				y_max;
	int				x_max;
}					t_data;

typedef struct		s_draw
{
	float			angle;
	float			small;
	float			H;
	float			V;
	char			ray;
	int				win_x;
}					t_draw;

typedef struct		s_mov
{
	int				key;
	void			(*ptr_f)(t_data*);
}					t_mov;


/*
 * main.c
 */
int					ft_init(t_data *env, char **argv);
int					ft_init_pos(int x, int y, t_data *env);

/*
 * ft_move.c
 */
int					key_press(int keycode, t_data *env);
int					key_release(int keycode, t_data *env);
int					loop_hook(t_data *env);
int					expose_hook(t_data *param);
void				ft_dash_right(t_data *d);

/*
 * ft_move2.c
 */
void				ft_dash_left(t_data *d);
void				ft_move_up(t_data *d);
void				ft_move_down(t_data *d);
void				ft_move_left(t_data *d);
void				ft_move_right(t_data *d);

/*
 * ft_draw.c
 */
void				ft_draw_background(t_data e);
void				ft_get_wall(t_data *e);
void				ft_draw_column(t_data *e, t_draw d);
void				ft_draw_put(t_data *e, t_draw d, int i, int direction);
int					ft_pixel_img(t_data *e, int x, int y, int color);

/*
 * ft_raycasting.c
 */
float				ft_get_ray_horizon(t_data *e, float angle);
float				ft_get_radian(float alpha);
float				ft_get_ray_vertical(t_data *e, float angle);

/*
 * get_nbr.c
 */
int					get_count(char *s);
int					*getnbr(char *s, t_data *env);
int					**ft_gettab(char **argv, t_data *env);
void				ft_print_tab(t_data *env);

#endif
