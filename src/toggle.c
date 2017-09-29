/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toggle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:06:25 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 17:45:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	toggle_option(t_env *e, int option)
{
	if (option == 0)
	{
		if (e->keys.t == 0)
			e->texturing *= -1;
		(TEXTURING == 1 ? ft_putendl("Textures enabled")\
						: ft_putendl("Textures disabled"));
	}
	if (option == 1)
	{
		if (e->keys.n == 0)
			e->noclip *= -1;
		(NOCLIP == 1 ? ft_putendl("Noclip mode enabled")\
					: ft_putendl("Noclip mode disabled"));
	}
	if (option == 2)
		if (e->keys.tab == 0)
		{
			e->mouse_look *= -1;
			(SDL_ShowCursor(-1) == 0 ? SDL_ShowCursor(1) : SDL_ShowCursor(0));
			(MLOOK == 1 ? ft_putendl("Mouse look enabled")\
						: ft_putendl("Mouse look disabled"));
		}
}
