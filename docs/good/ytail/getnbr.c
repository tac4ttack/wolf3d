/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytailor <ytailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/08 13:06:20 by ytailor           #+#    #+#             */
/*   Updated: 2014/01/19 18:41:52 by ytailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_print_tab(t_data *env)
{
	int		x;
	int		y;

	y = 0;
	x = 0;
	while (y != env->y_max)
	{
		while (x < env->x_max)
		{
			ft_putnbr(env->map[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		x = 0;
		y++;
	}
}

int			**ft_gettab(char **argv, t_data *env)
{
	int		i;
	int		fd;
	char	*str;
	int		**tab;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
		i++;
	close(fd);
	tab = (int**)malloc(sizeof(int *) * i);
	env->y_max = i;
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		tab[i] = getnbr(str, env);
		i++;
	}
	close(fd);
	return (tab);
}

int			get_count(char *s)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
		{
			while (ft_isdigit(s[i]) || s[i] == '-' || s[i] == '+')
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

int			*getnbr(char *s, t_data *env)
{
	int		*tab;
	int		count;
	size_t	i;
	int		j;

	i = 0;
	count = 0;
	j = 0;
	count = get_count(s);
	env->x_max = count;
	tab = (int*)malloc(sizeof(int) * count);
	while (j < count)
	{
		while (ft_isdigit(s[i]) == 0 && s[i] != '-' && s[i] != '+')
			i++;
		tab[j] = ft_atoi(&s[i]);
		j++;
		while (ft_isdigit(s[i]) != 0 || s[i] == '-' || s[i] == '+')
			i++;
	}
	return (tab);
}
