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
		WW = e->eve.window.data1;
		WH = e->eve.window.data2;
	//	TW = WH / 12;
	//	TH = TW;
	//	e->player.height = TH / 2;
	//	e->deg_step = FOV / WW;
	//	e->sc_gap = (WW / 2) / tanl(M_PI / 6);
	//	e->map.cei = TH;
	}
}

void	keypress_events(t_env *e)
{
	if (e->eve.key.type == SDL_KEYDOWN)
	{
	//	ft_putendl("KEYDOWN");
		(e->eve.key.keysym.sym == 27 ? quit(e) : 0);
		(e->eve.key.keysym.sym == 0x40000050 ? look(e, -1) : 0); // gauche
		(e->eve.key.keysym.sym == 0x4000004F ? look(e, 1) : 0); // droite
		(e->eve.key.keysym.sym == 0x40000052 ? move(e, 1) : 0); // haut
		(e->eve.key.keysym.sym == 0x40000051 ? move(e, -1) : 0); // bas
		(e->eve.key.keysym.sym == 0x77 ? move(e, 1) : 0); // w
		(e->eve.key.keysym.sym == 0x73 ? move(e, -1) : 0); // s
		(e->eve.key.keysym.sym == 0x61 ? strafe(e, 1) : 0); // a
		(e->eve.key.keysym.sym == 0x64 ? strafe(e, -1) : 0); // q
		(e->eve.key.keysym.sym == 0x74 ? e->texturing *= -1 : 0); // t
		(e->eve.key.keysym.sym == 104 ? PrintWindowEvent(&e->eve) : 0);
	}
}

void	mouse_events(t_env *e)
{
	if (e->eve.motion.type == SDL_MOUSEMOTION)
	{
	//	ft_putendl("MOUSEMOTION");
	//	printf("player dir = %Lf\n", e->player.dir);
		mouse_look(e);
	}
}
