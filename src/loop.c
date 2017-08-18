/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/17 19:47:54 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
	int i, j;
	t_ldpt	a, b;

	a.x = 45;
	a.y = 500;
	b.x = 900;
	b.y = 250;
	i = 0;
	j = 0;
	while (j < 8)
	{
		while (i < 8)
		{
			sdl_tex_pix_put(e, i, j, 0x0000ffff);
			i++;
		}
		i = 0;
		j++;
	}	
	sdl_tex_line(e, a, b, 0xff00ff00);
}

Uint8	main_loop(t_env *e)
{
	if (e)
		SDL_SetRenderDrawBlendMode(e->ren,SDL_BLENDMODE_BLEND);
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
		//	draw_frame(e);
			Render_Rand_Rect_SDL(e);
		//	SDL_UpdateTexture(e->tex, NULL, e->pix, e->w_w * sizeof (Uint32));
		//	SDL_RenderCopy(e->ren, e->tex, NULL, NULL);
		//	SDL_RenderPresent(e->ren);
		}
	return (0);
}
