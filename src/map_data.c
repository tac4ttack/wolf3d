/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 11:16:52 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/05 02:14:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static char		*split_map_data(t_env *e, char *data)
{
	int		i;
	char	*tmp;
	char	**split;

	i = 0;
	tmp = ft_strnew(0);
	split = ft_strsplit(data, '\n');
	while (i < e->map.lin)
	{
		tmp = ft_strjoin_free(tmp, ft_strjoin(split[i], " "));
		i++;
	}
	flush_str_array(e, split);
	return (tmp);
}

static void	fill_map_grid(t_env *e, char *data)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = 0;
	ft_putendl(data);
	ft_putstr("col = ");
	ft_putnbr(e->map.col);
	ft_putstr(" line = ");
	ft_putnbr(e->map.lin);
	ft_putchar('\n');
	ft_putendl("split?");
	split = ft_strsplit(data, ' ');
//	ft_putendl("split ok");
	while (j < e->map.lin)
	{
//		ft_putstr("j = ");
//		ft_putnbr(j);
		while (i < e->map.col)
		{
//			ft_putstr(" i = ");
//			ft_putnbr(i);
//			ft_putchar('\n');
			e->map.grid[j][i] = ft_atoi(split[i + (j * e->map.col)]);
			i++;
		}
		j++;
		i = 0;
	}
//	ft_putendl("flushing array?");
	flush_str_array(e, split);
//	ft_putendl("flushing array OK");
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

void		parse_data(t_env *e, char *data)
{
	char	*tmp;
	
	tmp = NULL;
	if (check_data(data) != 0)
		env_error(e, "Error, the map file seems to be invalid");
	ft_putendl("data checked ok\ncounting columns");
	e->map.col = count_col(data);
	ft_putendl("columns counted\ngrid map init");
	e->map.grid = init_map_grid(e);
	ft_putendl("map grid init ok\nspliting map data");
	tmp = split_map_data(e, data);
	ft_putendl("map data split ok\nfilling grid");
	fill_map_grid(e, tmp);
	ft_putendl("map grid filled");
	(e->debug ? map_test(e) : 0);
	free(tmp);
}
