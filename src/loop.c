/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/22 04:11:36 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
	int x;
	
	x = 0;
	while (x < WW)
	{
		init_ray(e, x);		// initialisation rayon, semble OK
		convert_dir(e);		// conversion direction en radian, semble OK
		calc_hor_step(e);		//calc_step
		calc_ver_step(e);
		calc_dst(e);
		render(e, x);
		x++;
	}
}

Uint8	main_loop(t_env *e)
{
	if (e)
		while (e->run)
		{
			while (SDL_PollEvent(&e->eve))
			{
				(e->eve.type == SDL_WINDOWEVENT ? win_events(e) : 0);
				(e->eve.type == SDL_KEYDOWN ? keypress_events(e) : 0);
				(e->eve.type == SDL_MOUSEMOTION ? mouse_events(e) : 0);
				(e->debug == 1 ? print_window_events_a(&e->eve) : 0);
				(e->eve.type == SDL_QUIT ? e->run = 0 : 0);
				(e->run == 0 ? quit(e) : 0);
			}
			draw_frame(e);
			if (e->texturing == -1)
			{
				SDL_UpdateTexture(e->buf, NULL, e->pix, WW * sizeof (Uint32));
				SDL_RenderCopy(e->ren, e->buf, NULL, NULL);
			}
//			else
//				e->buf = SDL_CreateTextureFromSurface(e->ren, e->tex.buffer);
//			SDL_RenderCopy(e->ren, e->buf, NULL, NULL);
			SDL_Rect	a;
			a.x = 66;
			a.y = 66;
			a.w = 666;
			a.h = 333;
//			SDL_RenderCopy(e->ren, e->tex.sheet2, NULL, &a);
			SDL_RenderPresent(e->ren);
		}
	return (0);
}
