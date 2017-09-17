/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassing <hmassing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 18:10:09 by hmassing          #+#    #+#             */
/*   Updated: 2014/01/31 16:15:00 by hmassing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <X.h>
#include "lib/libft.h"
#include "get_next_line.h"
#include "wolf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h> 
#include <unistd.h>

static void	readsize(t_env *e, int fd)
{
	int		*size;
	char	*line;

	if (get_next_line(fd, &line) < 1)
		exit(EXIT_FAILURE);
	size = ft_strsplittoint(line, ' ');
	e->map.sizex = size[0];
	e->map.sizey = size[1];
}

static void	readmap(t_env *e, int fd)
{
	char	*line;
	int		**worldmap;
	int		i;

	i = 0;
	worldmap = (int **)malloc(sizeof(int *) * e->map.sizex);
	if (worldmap == NULL)
		exit(EXIT_FAILURE);
	while (get_next_line(fd, &line) > 0)
	{
		worldmap[i] = ft_strsplittoint(line, ' ');
		i++;
	}
	e->map.map = worldmap;
}

static void	readfile(t_env *e)
{
	int		fd;
	int		i;

	i = 0;
	if ((fd = open("42", O_RDONLY)) == -1)
		exit(EXIT_FAILURE);
	readsize(e, fd);
	readmap(e, fd);
	close(fd);
}

void		get_timeframe(t_env *e)
{
	struct timeval time;

	e->oldtime = e->time;
	gettimeofday(&time, NULL);
	e->time = time.tv_sec * 1000 + time.tv_usec / 1000;
	e->frametime = e->time - e->oldtime;
	e->player.mspeed = e->frametime * 0.003;
	e->player.rspeed = e->frametime * 0.005;
}

int			main(void)
{
	t_env	e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_WIDTH, WIN_HEIGH, "wolf3d");
	e.img.img = NULL;
	e.player.pos.x = 5;
	e.player.pos.y = 5;
	e.player.dir.x = -1;
	e.player.dir.y = 0;
	e.r.plane.x = 0;
	e.r.plane.y = 0.80;
	e.time = 0;
	e.oldtime = 0;
	readfile(&e);
	mlx_loop_hook(e.mlx, &loop_hook, &e);
	mlx_hook(e.win, 2, (1L<<0), &key_press, &e);
	mlx_hook(e.win, 3, (1L<<1), &key_release, &e);
	mlx_loop(e.mlx);
	return (0);
}
