/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 20:34:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
	{
		ft_putendl("\n\x1b[1;31mNo target file!\n---------------\x1b[0m");
		ft_putstr("\x1b[2;32mUsage:\x1b[0m ./wolf3d");
		ft_putstr(" \x1b[2;33m<map filename>\x1b[0m\n\n");
		return (1);
	}
	else
	{
		ft_putendl("\n\x1b[1;31mWOLF3D\n-----\x1b[0m");
		ft_putstr("Initializing game environment...");
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			perror("Error allocating memory for environment:\n");
		init(e);
		ft_putstr(" OK!\nLoading target map file...");
		if (ac == 2)
			load_map(e, av[1]);
		print_keys();
	}
	if (main_loop(e) == 0)
		env_error(e, "Error can't enter main loop");
	quit(e);
	return (0);
}
