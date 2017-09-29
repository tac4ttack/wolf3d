/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmessina <fmessina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:24:26 by fmessina          #+#    #+#             */
/*   Updated: 2017/09/29 23:16:33 by fmessina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		win_events(t_env *e)
{
	if (e->eve.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
	{
		reset_screen(e);
		resize_textures(e);
	}
}

void		keyrelease_events(t_env *e)
{
	if (e->eve.key.type == SDL_KEYUP)
	{
		(e->eve.key.keysym.sym == 0x40000050 ? e->keys.left = 0 : 0);
		(e->eve.key.keysym.sym == 0x4000004F ? e->keys.right = 0 : 0);
		(e->eve.key.keysym.sym == 0x40000052 ? e->keys.up = 0 : 0);
		(e->eve.key.keysym.sym == 0x40000051 ? e->keys.down = 0 : 0);
		(e->eve.key.keysym.sym == 0x77 ? e->keys.w = 0 : 0);
		(e->eve.key.keysym.sym == 0x73 ? e->keys.s = 0 : 0);
		(e->eve.key.keysym.sym == 0x61 ? e->keys.a = 0 : 0);
		(e->eve.key.keysym.sym == 0x64 ? e->keys.d = 0 : 0);
		(e->eve.key.keysym.sym == 96 ? e->keys.apo = 0 : 0);
		(e->eve.key.keysym.sym == 0x74 ? e->keys.t = 0 : 0);
		(e->eve.key.keysym.sym == 0x09 ? e->keys.tab = 0 : 0);
		(e->eve.key.keysym.sym == 0x70 ? e->keys.p = 0 : 0);
		(e->eve.key.keysym.sym == 110 ? e->keys.n = 0 : 0);
	}
}

static void	keypress_events_toggle(t_env *e)
{
	if (e->eve.key.keysym.sym == 0x74)
	{
		toggle_option(e, 0);
		e->keys.t = 1;
	}
	if (e->eve.key.keysym.sym == 110)
	{
		toggle_option(e, 1);
		e->keys.n = 1;
	}
	if (e->eve.key.keysym.sym == 0x09)
	{
		toggle_option(e, 2);
		e->keys.tab = 1;
	}
	if (e->debug == 1)
		if (e->eve.key.keysym.sym == 0x70)
		{
			(e->keys.p == 0 ? print_info(e) : 0);
			e->keys.p = 1;
		}
}

void		keypress_events(t_env *e)
{
	if (e->eve.key.type == SDL_KEYDOWN)
	{
		if (e->debug == 1)
			print_input(e->eve.key.keysym.sym);
		(e->eve.key.keysym.sym == 27 ? quit(e) : 0);
		(e->eve.key.keysym.sym == 0x40000050 ? e->keys.left = 1 : 0);
		(e->eve.key.keysym.sym == 0x4000004F ? e->keys.right = 1 : 0);
		(e->eve.key.keysym.sym == 0x40000052 ? e->keys.up = 1 : 0);
		(e->eve.key.keysym.sym == 0x40000051 ? e->keys.down = 1 : 0);
		(e->eve.key.keysym.sym == 0x77 ? e->keys.w = 1 : 0);
		(e->eve.key.keysym.sym == 0x73 ? e->keys.s = 1 : 0);
		(e->eve.key.keysym.sym == 0x61 ? e->keys.a = 1 : 0);
		(e->eve.key.keysym.sym == 0x64 ? e->keys.d = 1 : 0);
		if (e->eve.key.keysym.sym == 96)
		{
			if (e->keys.apo == 0)
			{
				e->debug *= -1;
				(e->debug == 1 ? ft_putendl("Debug mode enabled")\
								: ft_putendl("Debug mode disabled"));
			}
			e->keys.apo = 1;
		}
		keypress_events_toggle(e);
	}
}

void		mouse_events(t_env *e)
{
	if (e->eve.motion.type == SDL_MOUSEMOTION)
	{
		mouse_look(e);
	}
}
