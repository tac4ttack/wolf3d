/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/24 19:12:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		error(t_env *e, char *str)
{
	ft_putstr("Oh no I just crashed! ");
	ft_putendl(SDL_GetError());
	ft_putendl(str);
	if (e)
	{
		if (e->ren)
			SDL_DestroyRenderer(e->ren);
		if (e->win)
			SDL_DestroyWindow(e->win);
		SDL_Quit();
		free(e);
	}
	exit(EXIT_FAILURE);
}

void		quit(t_env *e)
{
	if (e)
	{
		if (e->ren)
			SDL_DestroyRenderer(e->ren);
		if (e->win)
			SDL_DestroyWindow(e->win);
		SDL_Quit();
		free(e);
	}
	ft_putendl("Exiting");
	exit(EXIT_SUCCESS);
}
