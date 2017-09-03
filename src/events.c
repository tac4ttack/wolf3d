/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmesft_sina <fmesft_sina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 17:01:07 by fmesft_sina          #+#    #+#             */
/*   Updated: 2017/09/03 19:53:00 by fmesft_sina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void win_events(t_env *e)
{
	if (e->eve.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		e->w_w = e->eve.window.data1;
		e->w_h = e->eve.window.data2;
	}
}

void	keypress_events(t_env *e)
{
	if (e->eve.key.type == SDL_KEYDOWN)
	{
		(e->eve.key.keysym.sym == 27 ? quit(e) : 0);
		
		(e->eve.key.keysym.sym == 0x40000050 ? e->player.dir -= 1 : 0); // gauche
		(e->player.dir == -1 ? e->player.dir = 359 : 0);
		(e->eve.key.keysym.sym == 0x4000004F ? e->player.dir += 1 : 0); // droite
		(e->player.dir == 361 ? e->player.dir = 1 : 0);
		if (e->eve.key.keysym.sym == 0x40000052) // haut
		{
			e->player.n_pix.x = e->player.pix.x + sinl((e->player.dir * DEG2RAD)) * 10;
			e->player.n_pix.y = e->player.pix.y - cosl(e->player.dir * DEG2RAD) * 10;
			if (read_pixels(e, e->player.n_pix.x, e->player.n_pix.y) != 1)
			{
				e->player.pix.x = e->player.n_pix.x;
				e->player.pix.y = e->player.n_pix.y;
			}
		}
		if (e->eve.key.keysym.sym == 0x40000051) // bas
		{
			e->player.n_pix.x = e->player.pix.x - sinl((e->player.dir * DEG2RAD)) * 10;
			e->player.n_pix.y = e->player.pix.y + cosl(e->player.dir * DEG2RAD) * 10;
			if (read_pixels(e, e->player.n_pix.x, e->player.n_pix.y) != 1)
			{
				e->player.pix.x = e->player.n_pix.x;
				e->player.pix.y = e->player.n_pix.y;
			}
		}
		(e->eve.key.keysym.sym == 104 ? PrintWindowEvent(&e->eve) : 0);
	}
}
