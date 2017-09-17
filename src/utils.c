/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/23 17:42:48 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			flush_str_array(t_env *e, char **array)
{
	int		i;

	i = 0;
	if (array == NULL)
		env_error(e, "Error critical failure -> can't flush NULL array");
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void		error(void)
{
	ft_putendl("\nOh no I just crashed!");
	perror(NULL);
	exit(EXIT_FAILURE);
}

void		env_error(t_env *e, char *str)
{
	ft_putendl("\nOh no I just crashed!");
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
