/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/05/11 17:07:10 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
