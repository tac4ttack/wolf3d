/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/23 17:46:14 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"


int 		main(int ac, char **av)
{
	t_env *e;

	if (ac != 2)
	{
		perror(NULL);
		ft_putstr("\nUsage : ./wolf3d <map filename>");
		return(1);
	}
	else
	{
		if (!(e = (t_env*)malloc(sizeof(t_env))))
			env_error(e, "Error allocating memory for environment");
		init(e);
		if (ac == 2)
			load_map(e, av[1]);
	}
	// NE PAS OUBLIER DE VIRER LE PRINTF OU REFAIRE LA FONCTION
	if (DBUG == 1)
		printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
		
	if (main_loop(e) == 0)
		env_error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
