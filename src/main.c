/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 15:40:51 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/17 16:50:25 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 		main(void)
{
	t_env *e;

	if (!(e = (t_env*)malloc(sizeof(t_env))))
		error(e, "Error allocating memory for environment");
	init_sdl(e);
	printf("Ce fichier a ete compile le %s a %s\n", __DATE__, __TIME__);
	if (main_loop(e) == 0)
		error(e, "Error can't enter main loop");
	quit(e);
	return 0;
}
