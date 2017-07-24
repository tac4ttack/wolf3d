/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/22 19:02:15 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
t_map		init_map(void)
{
	t_map tmp;
	//**grid;
	tmp.col = 0;
	tmp.row = 0;
	tmp.width = 0;
	tmp.height = 0;
	tmp.tile_w = 64;
	tmp.tile_h = 64;
	return (tmp);
}

int		check_map_width(char *line)
{
	int	i;
	int res;
	
	i = 0;
	res = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			res++;
		i++;
	}
	return (res + 1);
}

void	load_map(t_env *e, char *file)
{
	int		fd;
	char	*buf;
	
	e->map = init_map();
	if ((fd = open(file, O_RDONLY)) >= 0)
	{
		while (get_next_line(fd, &buf) == 1)
		{
			if (e->map.row == 0)
			{
				e->map.col = check_map_width(buf);
				e->map.row++;
			}
			else if (e->map.col == check_map_width(buf))	
				e->map.row++;
			else
				error(e, "Wrong map file format (line size error)");
		}
		close(fd);
	}
	else
		error(e, "Error opening target file");
}

int 		main(int ac, char **av)
{
	t_env *e;
	
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		error(e, "Error allocating memory for environment");
	if (ac == 2)
		load_map(e, av[1]);
	else	
		error(e, "Usage : ./wolf3d <filename>");
	init_sdl(e);
	if (DBUG == 1)
		printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
	if (main_loop(e) == 0)
		error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
