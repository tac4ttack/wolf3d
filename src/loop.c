/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 19:08:47 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
//	Texture_Draw(e); // a drawing in a texture, same as mlx_img
	sdl_tex_pix_put(e, 250, 250, 0x00ffffff);
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
//			Texture_Draw(e);
			draw_frame(e);
			SDL_UpdateTexture(e->tex, NULL, e->pix, e->w_w * sizeof (Uint32));
			SDL_RenderCopy(e->ren, e->tex, NULL, NULL);
			SDL_RenderPresent(e->ren);
//			Render_Rand_Rect_SDL(e);
		}
	return (0);
}
