/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/05 03:28:26 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int 		main(int ac, char **av)
{
	t_env *e;

//	if (ac != 2)
//	{
//		perror(NULL);
//		ft_putstr("\nUsage : ./wolf3d <map filename>");
//		return(1);
//	}
	if (ac == 1)
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			perror("Error allocating memory for environment:\n");
		init(e);
		load_raw_map(e);
	}
	else
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			perror("Error allocating memory for environment:\n");
		init(e);
//		ft_putendl("init ok, loading map");
		if (ac == 2)
			load_map(e, av[1]);
//		ft_putendl("map loaded");
	}

//	printf("player pos.x = %d pos.y = %d\n", e->player.pos_x, e->player.pos_y);
	// NE PAS OUBLIER DE VIRER LE PRINTF OU REFAIRE LA FONCTION

	if (DBUG == 1)
		printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
	if (main_loop(e) == 0)
		env_error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
