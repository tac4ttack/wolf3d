/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 13:30:45 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 17:40:52 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_mov		t[8] =
{
	{UP, ft_move_up},
	{RIGHT, ft_move_right},
	{DOWN, ft_move_down},
	{LEFT, ft_move_left},
	{D_LEFT, ft_dash_left},
	{D_RIGHT, ft_dash_right},
	{-1, NULL},
};

int					expose_hook(t_data *param)
{
	t_data			*data;

	data = (t_data *)param;
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
	return (0);
}

int					key_press(int keycode, t_data *env)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == UP || keycode == AVANCER)
		env->save[0] = 1;
	if (keycode == RIGHT)
		env->save[1] = 1;
	if (keycode == DOWN || keycode == RECULER)
		env->save[2] = 1;
	if (keycode == LEFT)
		env->save[3] = 1;
	if (keycode == D_LEFT)
		env->save[4] = 1;
	if (keycode == D_RIGHT)
		env->save[5] = 1;
	if (keycode == 65293)
		env->save[6] = 1;
	return (0);
}

int					key_release(int keycode, t_data *env)
{
	if (keycode == UP || keycode == AVANCER)
		env->save[0] = 0;
	if (keycode == RIGHT)
		env->save[1] = 0;
	if (keycode == DOWN || keycode == RECULER)
		env->save[2] = 0;
	if (keycode == LEFT)
		env->save[3] = 0;
	if (keycode == D_LEFT)
		env->save[4] = 0;
	if (keycode == D_RIGHT)
		env->save[5] = 0;
	if (keycode == 65293)
		env->save[6] = 0;
	return (0);
}

int					loop_hook(t_data *env)
{
	int				i;

	i = -1;
	while (++i != 7 && env->save[i] != 1)
	{
		if (i == 6 && env->save[i] == 0)
			return (0);
	}
	i = -1;
	while (t[++i].key != -1)
	{
		if (env->save[i] == 1)
			t[i].ptr_f(env);
		if (env->save[6] == 1)
			ft_init_pos(X, Y, env);
	}
	ft_draw_background(*env);
	ft_get_wall(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}

void				ft_dash_right(t_data *d)
{
	d->pos.Py = d->pos.Py - sin(ft_get_radian(d->pos.a - 90)) * 2;
	d->pos.Px = d->pos.Px + cos(ft_get_radian(d->pos.a - 90)) * 2;
	if (d->map[(int)(d->pos.Py / 64)][(int)(d->pos.Px / 64)] == 1)
		ft_dash_left(d);
}
