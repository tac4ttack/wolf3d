/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:59:00 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 19:57:59 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_frame(t_env *e)
{
	int		x;

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
	e->frames++;
	e->framerate = ((float)e->frames / (float)(SDL_GetTicks() \
					- (float)e->start_ticks)) * 1000;
	e->tex.dst.x = 10;
	e->tex.dst.y = 10;
	e->tex.dst.w = 30;
	e->tex.dst.h = 30;
	if (e->debug == 1)
		SDL_RenderCopy(e->ren, render_text(e, ft_itoa((int)e->framerate) \
										, e->txt_hue), NULL, &e->tex.dst);
}

void		keyboard_state_events(t_env *e)
{
	(e->keys.left == 1 ? look(e, -1) : 0);
	(e->keys.right == 1 ? look(e, 1) : 0);
	(e->keys.up == 1 ? move(e, 1) : 0);
	(e->keys.down == 1 ? move(e, -1) : 0);
	(e->keys.w == 1 ? move(e, 1) : 0);
	(e->keys.s == 1 ? move(e, -1) : 0);
	(e->keys.a == 1 ? strafe(e, 1) : 0);
	(e->keys.d == 1 ? strafe(e, -1) : 0);
}

Uint8		main_loop(t_env *e)
{
	if (e)
		while (e->run)
		{
			while (SDL_PollEvent(&e->eve))
			{
				(e->eve.type == SDL_WINDOWEVENT ? win_events(e) : 0);
				(e->eve.type == SDL_KEYDOWN ? keypress_events(e) : 0);
				(e->eve.type == SDL_KEYUP ? keyrelease_events(e) : 0);
				(e->eve.type == SDL_MOUSEMOTION ? mouse_events(e) : 0);
				(e->debug == 1 ? print_window_events_a(&e->eve) : 0);
				(e->eve.type == SDL_QUIT ? e->run = 0 : 0);
				(e->run == 0 ? quit(e) : 0);
			}
			keyboard_state_events(e);
			draw_frame(e);
			(e->debug == 1 ? render_crosshair(e) : 0);
			SDL_RenderPresent(e->ren);
		}
	return (0);
}
