/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassing <hmassing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 12:46:55 by hmassing          #+#    #+#             */
/*   Updated: 2014/01/21 15:15:06 by hmassing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIN_HEIGH 720
# define WIN_WIDTH 1280

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct	s_coordint
{
	int		x;
	int		y;
}				t_coordint;

typedef struct	s_move
{
	int	up;
	int	left;
	int	right;
	int	down;
}				t_move;

typedef struct	s_ray
{
	t_coord		pos;
	t_coord		dir;
	t_coord		plane;
	t_coord		sidedist;
	t_coord		disd;
	t_coordint	posmap;
	int			lheight;
	int			ystart;
	int			yend;
}				t_ray;

typedef struct	s_player
{
	t_coord		pos;
	t_coord		dir;
	t_coordint	step;
	t_move		move;
	double		rspeed;
	double		mspeed;
	double		hcamera;
	int			hit;
	int			wallside;
	int			sprint;
}				t_player;

typedef struct	s_map
{
	int	**map;
	int	display;
	int	sizex;
	int	sizey;
}				t_map;

typedef struct	s_img
{
	void	*img;
	char	*d;
	int		bp;
	int		s;
	int		e;
}				t_img;

typedef struct	s_env
{
	void		*win;
	void		*mlx;
	t_img		img;
	t_player	player;
	t_map		map;
	t_ray		r;
	double		time;
	double		oldtime;
	long int	frametime;
}				t_env;

void	get_timeframe(t_env *e);
int		expose_hook(t_env *t);
int		loop_hook(t_env *e);
int		key_release(int keycode, t_env *e);
int		key_press(int keycode, t_env *e);
void	move(t_env *e);
void	colors(t_env *e, t_rgb *c);
void	drawline(int x, t_env *e, t_rgb *c);

#endif
