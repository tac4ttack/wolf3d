/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/01 19:46:27 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_map(t_env *e)
{
	if (e)
	{
		e->map.col = 0;
		e->map.row = 0;
		e->map.cei = 64;
		e->map.flo = 0;
	}	
}

void	init_player(t_env *e, int x, int y)
{
	if (e)
	{
		e->player.pos_x = (x * e->tile_w) + (e->tile_w / 2);
		e->player.pos_y = (y * e->tile_h) + (e->tile_h / 2);
		e->player.fov = 90;
		e->player.dir = 0;
		e->player.height = e->tile_h / 2;
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
			if (buf[0] != '#')
			{
				tmp = ft_strjoin_free(tmp, ft_strjoin_frs1(buf, "\n"));
				i++;
			}
		}
		close(fd);
	}
	else
		error(e, "Error opening target file");
	e->map.row = i;
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
	if (!(tmp = (int**)malloc(sizeof(int*) * e->map.row)))
		error(e, "Error allocating memory for map grid lines");
	while (j < e->map.row)
	{
		if (!(tmp[j] = (int*)malloc(sizeof(int) * e->map.col * e->map.row)))
			error(e, "Error allocating memory for map grid rows");
		while (i < e->map.col)
		{	
			tmp[j][i + j * e->map.col] = ft_atoi(split[i + j * e->map.col]);
			i++;
		}
		i = 0;
		j++;
	}
	flush_str_array(e, split);
	return (tmp);
	
//	read the result
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
	
}

int		count_col(char *data)
{
	int	i;
	int current;
	int best;

	i = 0;
	current = 0;
	best = 0;
	while (data[i] != '\0')
	{
		while (data[i] != '\n')
		{
			(data[i] == ' ' ? current++ : 0);
			i++;
		}
		i++;
		current++;
		(best < current ? best = current : 0);
		current = 0;
	}
	return (best);
}

int		check_data(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 10 || str[i] == 32 || (str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (1);
	}
	return (0);
}

void	load_map(t_env *e, char *file)
{
	char	*data;
	
	data = ft_strnew(0);
	init_map(e);
	data = ft_strjoin_free(data, read_file(e, file));
	if (check_data(data) != 0)
		error(e, "Error, the map file seems to be invalid");
	e->map.col = count_col(data);
	e->map.grid = parse_data(e, data);
//	init_player(e);

	printf("data =\n%s\n", data);
	printf("number of lines is %d\n", e->map.row);
	printf("longest line is %d rows long\n", e->map.col);
	free(data);
}

int 		main(int ac, char **av)
{
	t_env *e;
	
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		error(e, "Error allocating memory for environment");
	init(e);
	if (ac == 2)
		load_map(e, av[1]);
	else	
		error(e, "Usage : ./wolf3d <map filename>");
	if (DBUG == 1)
		printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
	if (main_loop(e) == 0)
		error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
