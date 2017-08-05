/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/01 19:46:28 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			flush_str_array(t_env *e, char **array)
{
	int		i;

	i = 0;
	if (array == NULL)
		error(e, "Error critical failure -> can't flush NULL array");
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

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
