/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/25 19:45:22 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_map		*init_map(t_env *e)
{
	t_map *target;

	if (!(target = malloc(sizeof(t_map))))
		error(e, "Error allocating memory for map grid lines");
	target->col = 0;
	target->row = 0;
	target->cei = 64;
	target->grd = 0;
	target->tile_w = 64;
	target->tile_h = 64;
	return (target);
}

t_player	*init_player(t_env *e)
{
	t_player	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < e->map->row)
	{
		while (i < e->map->col)
		{
			if (e->map->grid[j][i] == 9)
				break;
			i++;
		}
		i = 0;
		j++;
	}
	tmp->pos_x = i;
	tmp->pos_y = j;
	tmp->fov = 60;
	tmp->dir = 0;
	tmp->height = e->map->tile_h / 2;
//	printf("player pos_x = %d | pos_y = %d\n", tmp.pos_x, tmp.pos_y);
//	ft_putnbr(e->map.grid[1][1]);
//	printf("player height is %d\n", tmp.height);   OK ca fonctionne
	return (tmp);

	// test map player[3,6]
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

void	check_char(t_env *e, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] > 47  && str[i] < 58) || str[i] == 32 || str[i] == '\n')
			i++;
		else
			error(e, "Map format invalid (wrong char found)");
	}
}

char	*read_file(t_env *e, char *file)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*buf;
	
	i = 0;	
	fd = 0;	
	tmp = ft_strnew(0);
	if ((fd = open(file, O_RDONLY)) >= 0)
	{
		while (get_next_line(fd, &buf) == 1)
		{
			if (e->map->row == 0)
				e->map->col = check_map_width(buf);
			else if (e->map->col != check_map_width(buf))	
				error(e, "Wrong map file format (line size error)");
			check_char(e, buf);
			tmp = ft_strjoin_free(tmp, ft_strjoin_frs1(buf, " "));
			e->map->row++;
		}
		close(fd);
	}
	else
		error(e, "Error opening target file");
	return (tmp);
}

int		**parse_data(t_env *e, char *data)
{
	int		i;
	int		j;
	int		**tmp;
	char	**split;
	
	i = 0;
	j = 0;
	split = ft_strsplit(data, ' ');
	if (!(tmp = (int**)malloc(sizeof(int*) * e->map->row)))
		error(e, "Error allocating memory for map grid lines");
	while (j < e->map->row)
	{
		if (!(tmp[j] = (int*)malloc(sizeof(int) * e->map->col * e->map->row)))
			error(e, "Error allocating memory for map grid rows");
		while (i < e->map->col)
		{	
			tmp[j][i + j * e->map->col] = ft_atoi(split[i + j * e->map->col]);
			i++;
		}
		i = 0;
		j++;
	}
	flush_str_array(e, split);
	return (tmp);
	
/*	read the result
	i = 0;
	j = 0;
	while (j < e->map.row)
	{
		ft_putchar('|');
		while (i < e->map.col)
		{
			ft_putnbr(tmp[j][i + j * e->map.col]);
			ft_putchar('|');
			i++;
		}
		ft_putchar('\n');
		i = 0;
		j++;
	}
	*/
}

void	load_map(t_env *e, char *file)
{
	char	*data;
	
	data = ft_strnew(0);
	e->map = init_map(e);
	data = ft_strjoin_free(data, read_file(e, file));
	e->map->grid = parse_data(e, data);
	e->player = init_player(e);

	ft_putnbr(e->map->grid[9][1]);
//	ft_putnbr(e->player.pos_x);
//	ft_putchar('|');
//	ft_putnbr(e->player.pos_y);
//	ft_putchar('\n');
	free(data);
}

int 		main(int ac, char **av)
{
	t_env *e;
	
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		error(e, "Error allocating memory for environment");
	init_sdl(e);
	if (ac == 2)
		load_map(e, av[1]);
	else	
		error(e, "Usage : ./wolf3d <filename>");
	if (DBUG == 1)
		printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
	if (main_loop(e) == 0)
		error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
