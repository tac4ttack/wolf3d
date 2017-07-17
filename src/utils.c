/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/07/17 16:48:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		error(t_env *e, char *str)
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

void		exit(t_env *e)
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
