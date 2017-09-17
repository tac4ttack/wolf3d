/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 12:25:27 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 19:40:41 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int					ft_init(t_data *e, char **argv)
{
	if (open(argv[1], O_RDONLY) == -1)
	{
		perror(argv[1]);
		return (0);
	}
	e->map = ft_gettab(argv, e);
	e->ptr = mlx_init();
	e->img = mlx_new_image(e->ptr, WIN_X, WIN_Y);
	e->win = mlx_new_window(e->ptr, WIN_X, WIN_Y, "Wolf3d");
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	return (ft_init_pos(X, Y, e));
}

int					ft_init_pos(int x, int y, t_data *env)
{
	if (y <= env->y_max && x <= env->x_max && env->map[y][x] != 1)
	{
		env->pos.a = 90;
		env->pos.Px = x * 64 + 32;
		env->pos.Py = y * 64 + 32;
		return (1);
	}
	ft_putstr("Start position error\n");
	return (0);
}

int					main(int argc, char **argv)
{
	t_data			env;

	if (argc == 1)
	{
		ft_putstr("usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" map\n");
	}
	else
	{
		if (ft_init(&env, argv) == 0)
			return (0);
		ft_draw_background(env);
		ft_get_wall(&env);
		mlx_hook(env.win, 2, 1, key_press, &env);
		mlx_hook(env.win, 3, 2, key_release, &env);
		mlx_loop_hook(env.ptr, loop_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.ptr);
	}
	return (0);
}
