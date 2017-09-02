/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 17:01:07 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/03 00:16:25 by fmessina         ###   ########.fr       */
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
			e->player.pix.x += cos(e->player.dir * (M_PI / 180)) * 10;
			e->player.pix.y += sin(e->player.dir * (M_PI / 180)) * 10;
		}
		if (e->eve.key.keysym.sym == 0x40000051) // bas
		{
			e->player.pix.x -= cos(e->player.dir * (M_PI / 180)) * 10;
			e->player.pix.y -= sin(e->player.dir * (M_PI / 180)) * 10;
		}
	//	(e->eve.key.keysym.sym == 104 ? PrintWindowEvent(&e->eve) : 0);
	}
}
