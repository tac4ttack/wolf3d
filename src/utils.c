/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/24 19:04:04 by fmessina         ###   ########.fr       */
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
		if (e->win || e->ren != NULL)
		{
			(e->ren != NULL ? SDL_DestroyRenderer(e->ren) : 0);
			(e->win != NULL ? SDL_DestroyWindow(e->win) : 0 );
			SDL_Quit();
		}
		free(e);
	}
	exit(EXIT_FAILURE);
}

void		quit(t_env *e)
{
	if (e)
	{
		SDL_DestroyRenderer(e->ren);
		SDL_DestroyWindow(e->win);
		SDL_Quit();
	}
	ft_putendl("Exiting");
	exit(EXIT_SUCCESS);
}
