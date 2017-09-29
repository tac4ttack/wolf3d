/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 10:33:38 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 22:05:06 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	flush_str_array(t_env *e, char **array)
{
	int	i;

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

void	error(void)
{
	ft_putendl("\nOh no I just crashed!");
	perror(NULL);
	exit(EXIT_FAILURE);
}

void	env_error(t_env *e, char *str)
{
	ft_putendl("\nOh no I just crashed!");
	ft_putendl(SDL_GetError());
	ft_putendl(str);
	if (e)
	{
		SDL_ShowCursor(1);
		if (e->ren)
			SDL_DestroyRenderer(e->ren);
		if (e->win)
			SDL_DestroyWindow(e->win);
		SDL_Quit();
		free(e);
	}
	exit(EXIT_FAILURE);
}

void	quit(t_env *e)
{
	if (e)
	{
		SDL_ShowCursor(1);
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

void	print_keys(void)
{
	ft_putendl("\n\nKey bindings are:\n\t` -> enable/disable debug mode\n \
	t -> enable/disable textures\n \
	p -> print information when debug mode enabled\n \
	n -> enable/disable noclip mode\n \
	wasd and arrows -> move the player\n \
	tab -> enable/disable mouse look");
	ft_putstr("\nLaunching session... Enjoy!\n");
}
