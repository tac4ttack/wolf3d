/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:15:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 16:48:23 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char	*read_file(t_env *e, char *file)
{
	int		i;
	int		fd;
	char	*tmp;
	char	*buf;
	
	i = 0;
//	fd = 0;  à virer pour passer à 25 lignes, verifier si ok niveau protection
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
			else
				free(buf);
		}
		close(fd);
	}
	else
		error(e, "Error opening target file");
	e->map.lin = i;
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
