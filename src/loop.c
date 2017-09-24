/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/24 11:07:43 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_frame(t_env *e)
{
	int x;
	
	x = 0;
	while (x < WW)
	{
		init_ray(e, x);
		convert_dir(e);
		calc_hor_step(e);
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
			SDL_RenderPresent(e->ren);
		}
	return (0);
}
