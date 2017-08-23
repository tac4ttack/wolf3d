/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:15:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/23 17:27:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static	char	*read_line(t_env *e, int fd, char *tmp)
{
	int i;
	char *buf;
	
	i = 0;
	if (get_next_line(fd, &buf) == -1)
		error();
	else
	{
		while (get_next_line(fd, &buf) == 1)
		{
			if (buf[0] != '#')
			{
				tmp = ft_strjoin_free(tmp, ft_strjoin_frs1(buf, "\n"));
				i++;
			}
			else
				free(buf);
		}
	}
	e->map.lin = i;
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

int		get_map_grid_val(t_env *e, int x, int y)
{
	return(e->map.grid[y][x]);
}

void	load_map(t_env *e, char *file)
{
	char	*data;
	
	data = ft_strnew(0);
	init_map(e);
	data = ft_strjoin_free(data, read_file(e, file));
	parse_data(e, data);
	init_player(e);
	free(data);
}
