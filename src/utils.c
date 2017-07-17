/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/17 16:39:49 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_error(t_env *e, char *str)
{
	ft_putstr("Oh no Fractol crashed! ");
	ft_putendl(SDL_GetError());
	ft_putendl(str);
	if (e)
	{
		SDL_DestroyRenderer(e->ren);
		SDL_DestroyWindow(e->win);
		SDL_Quit();
		free(e);
	}
	exit(EXIT_FAILURE);
}

void		ft_exit(t_env *e)
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
