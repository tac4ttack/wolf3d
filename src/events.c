/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 17:01:07 by fmessina          #+#    #+#             */
/*   Updated: 2017/08/16 18:19:35 by fmessina         ###   ########.fr       */
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
	//	(e->eve.key.keysym.sym == 104 ? PrintWindowEvent(&e->eve) : 0);
	}
}
