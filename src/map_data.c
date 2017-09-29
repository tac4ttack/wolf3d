/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:16:52 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:35:24 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*split_map_data(t_env *e, char *data)
{
	int			i;
	char		*tmp;
	char		**split;

	i = 0;
	tmp = ft_strnew(0);
	split = ft_strsplit(data, '\n');
	while (i < LIN)
	{
		tmp = ft_strjoin_free(tmp, ft_strjoin(split[i], " "));
		i++;
	}
	flush_str_array(e, split);
	return (tmp);
}

static void		fill_map_grid(t_env *e, char *data)
{
	int			i;
	int			j;
	char		**split;

	i = 0;
	j = 0;
	split = ft_strsplit(data, ' ');
	while (j < LIN)
	{
		while (i < COL)
		{
			e->map.grid[j][i] = ft_atoi(split[i + (j * COL)]);
			i++;
		}
		j++;
		i = 0;
	}
	flush_str_array(e, split);
}

static int		count_col(char *data)
{
	int			i;
	int			current;
	int			best;

	i = 0;
	current = 0;
	best = 0;
	while (data[i] != '\0')
	{
		while (data[i] != '\n')
		{
			if (data[i] == ' ' || data[i] == '\t')
			{
				while (data[i + 1] == ' ' || data[i + 1] == '\t')
					i++;
				current++;
			}
			i++;
		}
		i++;
		current++;
		(best < current ? best = current : 0);
		current = 0;
	}
	return (best);
}

static int		check_data(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == ' ' || str[i] == '-' || str[i] == '+' ||
			(str[i] >= 48 && str[i] <= 57))
			i++;
		else
			return (1);
	}
	return (0);
}

void			parse_data(t_env *e, char *data)
{
	char		*tmp;

	tmp = NULL;
	if (check_data(data) != 0)
		env_error(e, "Error, the map file seems to be invalid");
	COL = count_col(data);
	e->map.grid = init_map_grid(e);
	tmp = split_map_data(e, data);
	fill_map_grid(e, tmp);
	free(tmp);
}
