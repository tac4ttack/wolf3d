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
		(e->eve.key.keysym.sym == 0x40000050 ? look(e, -1) : 0); // gauche
		(e->eve.key.keysym.sym == 0x4000004F ? look(e, 1) : 0); // droite
		(e->eve.key.keysym.sym == 0x40000052 ? move(e, 1) : 0);
		(e->eve.key.keysym.sym == 0x40000051 ? move(e, -1) : 0);
		(e->eve.key.keysym.sym == 104 ? PrintWindowEvent(&e->eve) : 0);
	}
}
