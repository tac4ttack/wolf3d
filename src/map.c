/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:15:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/08 04:03:04 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	char	*read_line(t_env *e, int fd, char *tmp)
{
	int i;
	int status;
	char *buf;
	
	i = 0;
	status = 1;
	while (status == 1)
	{
		status = get_next_line(fd, &buf);
		(status == -1 ? error() : 1);
		if ( status == 0)
			break;
		if (buf[0] != '#')
		{
			tmp = ft_strjoin_free(tmp, ft_strjoin_frs1(buf, "\n"));
			i++;
		}
		else
			free(buf);
	}
	LIN = i;
	return (tmp);
}

static char	*read_file(t_env *e, char *file)
{
	int		fd;
	char	*tmp;
	
	tmp = ft_strnew(0);
	if ((fd = open(file, O_RDONLY)) >= 0)
	{
		tmp = read_line(e, fd, tmp);
		close(fd);
	}
	else
		error();	
	return (tmp);
}

static void	init_map(t_env *e)
{
	if (e)
	{
		e->map.col = 0;
		e->map.lin = 0;
		e->map.cei = TH;
		e->map.flo = 0;
	}	
}

int		**init_map_grid(t_env *e)
{
	int i;
	int **map;
	
	i = 0;
	if (!(map = (int**)malloc(sizeof(int*) * LIN)))
		env_error(e, "Error allocating memory for map grid lines");
	while (i < LIN)
	{
		if (!(map[i] = (int*)malloc(sizeof(int) * COL)))
			env_error(e, "Error allocating memory for map grid cols");
		i++;
	}
	return (map);
}

void	load_map(t_env *e, char *file)
{
	char	*data;
	
	data = ft_strnew(0);
	init_map(e);
//	ft_putendl("map init ok");
	data = ft_strjoin_free(data, read_file(e, file));
//	ft_putendl("parsing map data");
	parse_data(e, data);
//	ft_putendl("map data parsed");
	init_player(e);
	free(data);
}
