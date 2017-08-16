/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 17:18:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
	//ft_putendl("maybe i will draw maybe not");
	Texture_Draw(e); // a drawing in a texture, same as mlx_img
	//ft_putendl("hi i just drawed a frame");
}

Uint8	main_loop(t_env *e)
{
	if (e)
	//	SDL_SetRenderDrawBlendMode(e->ren,SDL_BLENDMODE_BLEND);
		while (e->run)
		{
			while (SDL_PollEvent(&e->eve))
			{
				(e->eve.type == SDL_WINDOWEVENT ? win_events(e) : 0);
				(e->eve.type == SDL_KEYDOWN ? keypress_events(e) : 0);
				(e->debug ? PrintWindowEvent(&e->eve) : 0);
				(e->eve.type == SDL_QUIT ? e->run = 0 : 0);
				(e->run == 0 ? quit(e) : 0);
			}
			//Render_Rand_Rect_SDL(e);
			Texture_Draw(e);
			//draw_frame(e);
		}
	return (0);
}
