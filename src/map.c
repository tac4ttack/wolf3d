/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:15:13 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/01 00:42:10 by fmessina         ###   ########.fr       */
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
